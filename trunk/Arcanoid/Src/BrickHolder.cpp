#include <stdio.h>
#include <stdlib.h>
#include <iterator>
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

//-----------------------------------------------------------------------

unsigned int BrickHolder::LoadLevel (engine::AnimationFilm * film, const std::string & path) {
	Clear();
	unsigned int brickId = 0;
	engine::ConfigFile config;

	if (config.LoadFile(path)) {
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
				engine::AnimatorManager::Register(animator);
				engine::AnimatorManager::MarkAsRunning(animator);
				bricks[b] = animator;
			}
			section = config.GetNextSection();
		}		
	}
	return brickId;
}

//-----------------------------------------------------------------------

bool BrickHolder::Cancel (Brick *b) {
	assert(b);
	bool result							= false;
	Brick2AnimatorMapping::iterator i	= bricks.find(b);

	if (i != bricks.end()) {
		b->SetVisibility(false);
		i->second->GetAnimation()->Destroy();
		engine::SpriteHolder::Cancel(b->GetId());
		engine::AnimatorManager::Cancel(i->second);
		result = true;
		bricks.erase(i);
	}
	return result;
}

//-----------------------------------------------------------------------

BrickList BrickHolder::GetBricks (void) {
	BrickList list;
	std::transform(
		bricks.begin(), 
		bricks.end(), 
		std::back_inserter(list), 
		engine::RetrieveKey()
	);
	return list; 
}

//-----------------------------------------------------------------------

engine::delay_t BrickHolder::GetDelay (void)
	{ return delay; }

//-----------------------------------------------------------------------

void BrickHolder::SetDelay (engine::delay_t d)
	{ delay = d; }

//-----------------------------------------------------------------------

void BrickHolder::Clear (void) {
	std::for_each(
		bricks.begin(),
		bricks.end(),
		ClearFunctor()
	);
}

//-----------------------------------------------------------------------

void BrickHolder::ClearFunctor::operator() (std::pair<Brick *, engine::Animator *> p) {
	p.second->GetAnimation()->Destroy();
	engine::SpriteHolder::Cancel(p.first->GetId());
	engine::AnimatorManager::Cancel(p.second);	
}