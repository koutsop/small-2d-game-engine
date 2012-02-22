#include <assert.h>
#include <algorithm>
#include "SpriteHolder.h"


namespace engine {

//-------------------------------------------------------//
//---- Static Variables ---------------------------------//

SpriteList					SpriteHolder::sprites;
SpriteHolder::String2Sprite	SpriteHolder::str2sprite;

//-------------------------------------------------------//
//---- Class SpriteHolder -------------------------------//

void SpriteHolder::Register (Sprite * s) { 
	assert(s);
	if (!GetSprite(s->GetId()))
		sprites.push_back(s); 
}

//-------------------------------------------------------------------------------------------

void SpriteHolder::RemoveDeadSprites (void)
	{ sprites.remove_if(RemoveFunctor()); }

//-------------------------------------------------------------------------------------------

const SpriteList& SpriteHolder::GetSprites (void)
	{ return sprites; }

//-------------------------------------------------------------------------------------------

Sprite*	SpriteHolder::GetSprite (const std::string& id) {
	String2Sprite::iterator i = str2sprite.find(id);
	return i != str2sprite.end()? i->second : (Sprite*)0;
}

//-------------------------------------------------------//
//---- struct RemoveFunctor -----------------------------//

bool SpriteHolder::RemoveFunctor::operator()(Sprite* s) {
	if (!s->IsAlive()) {
		str2sprite.erase(s->GetId());
		return true;
	}
	return false; 
}

}	//namespace engine