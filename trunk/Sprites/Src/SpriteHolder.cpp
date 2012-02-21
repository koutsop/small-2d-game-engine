#include <assert.h>
#include <algorithm>
#include "SpriteHolder.h"


namespace engine {

SpriteList SpriteHolder::sprites;

//---------------------------------------------------

void SpriteHolder::Register (Sprite * s) { 
	assert(s);
	SpriteList::iterator i = std::find_if(
								sprites.begin(), 
								sprites.end(), 
								FindFunctor(s->GetId())
							);	
	if (i != sprites.end())
		sprites.push_back(s); 
}

//---------------------------------------------------

void SpriteHolder::RemoveDeadSprites (void)
	{ sprites.remove_if(CheckFunctor()); }

//---------------------------------------------------

const SpriteList& SpriteHolder::GetSprites (void)
	{ return sprites; }

//---------------------------------------------------

Sprite*	SpriteHolder::GetSprite (const std::string& id) {
	SpriteList::iterator i = std::find_if(
								sprites.begin(), 
								sprites.end(), 
								FindFunctor(id)
							);
	return i != sprites.end()? *i : (Sprite*)0;
}


}	//namespace engine