#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include "Utility.h"
#include "ConfigFile.h"
#include "BrickHolder.h"
#include "SpriteHolder.h"
#include "MovingAnimator.h"
#include "MovingAnimation.h"
#include "AnimatorManager.h"



engine::delay_t						BrickHolder::delay = 2000;
BrickHolder::Brick2AnimatorMapping	BrickHolder::bricks;

void BrickHolder::LoadLevel (engine::AnimationFilm * film, const std::string & path) {
	Clear();
	engine::ConfigFile config;

	if (config.LoadFile(path)) {
		unsigned int brickId = 0;
		const char * section = config.GetFistSection();
		
		while (section) {
			if (strlen(section) > 0) {	//skip global section
				int x, y;
				Brick * b = new Brick(
									x = std::atoi(config.GetValue(section, "x")),
									y = std::atoi(config.GetValue(section, "y")),
									film,
									std::atoi(config.GetValue(section, "frameNo")),
									std::atoi(config.GetValue(section, "hits")),
									std::atoi(config.GetValue(section, "score")),
									engine::StringToBool(config.GetValue(section, "unbreakable")),
									"Brick" + engine::string_cast(brickId)
								);
				engine::SpriteHolder::Register(b);

				engine::MovingAnimation * animation = new engine::MovingAnimation(x, y, 1, true, brickId++);
				engine::MovingAnimator * animator	= new engine::MovingAnimator();
				animator->Start(b, animation, delay);//2000
				bricks[b] = animator;
			}
			section = config.GetNextSection();
		}		
	}	
}

bool BrickHolder::Cancel (Brick *b) {
	assert(b);
	bool result							= false;
	Brick2AnimatorMapping::iterator i	= bricks.find(b);

	if (i != bricks.end()) {
		i->second->GetAnimation()->Destroy();
		engine::SpriteHolder::Cancel(b->GetId());
		engine::AnimatorManager::Cancel(i->second);
		result = true;
		bricks.erase(i);
	}
	return result;
}

engine::delay_t BrickHolder::GetDelay (void)
	{ return delay; }


void BrickHolder::SetDelay (engine::delay_t d)
	{ delay = d; }

void BrickHolder::Clear (void) {
	std::for_each(
		bricks.begin(),
		bricks.end(),
		ClearFunctor()
	);
}

void BrickHolder::ClearFunctor::operator() (std::pair<Brick *, engine::Animator *> p) {
	p.second->GetAnimation()->Destroy();
	engine::SpriteHolder::Cancel(p.first->GetId());
	engine::AnimatorManager::Cancel(p.second);	
}