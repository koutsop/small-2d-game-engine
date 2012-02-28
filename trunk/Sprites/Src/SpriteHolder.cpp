#include <assert.h>
#include <iterator>
#include <algorithm>
#include "Utility.h"
#include "SpriteHolder.h"


namespace engine {

//-------------------------------------------------------//
//---- Static Variables ---------------------------------//

//SpriteList					SpriteHolder::sprites;
SpriteHolder::String2SpriteMapping	SpriteHolder::str2sprite;

//-------------------------------------------------------//
//---- Class SpriteHolder -------------------------------//

bool SpriteHolder::Register (Sprite * s) { 
	assert(s);
	bool result	= false;
	if (!GetSprite(s->GetId())) {
		str2sprite[s->GetId()] = s;
		result = true;
	}
	return result;
}

//-------------------------------------------------------------------------------------------

void SpriteHolder::Clear (void) {
	std::for_each(
		str2sprite.begin(),
		str2sprite.end(),
		ClearFunctor()
	);
	str2sprite.clear();
}
//-------------------------------------------------------------------------------------------

void SpriteHolder::Display (Bitmap* source) {
	std::for_each(
		str2sprite.begin(),
		str2sprite.end(),
		DisplayFunctor(source)
	);
}

//-------------------------------------------------------------------------------------------

bool SpriteHolder::Cancel (const std::string& id) {
	bool result							= false; 
	String2SpriteMapping::iterator i	= str2sprite.find(id);

	if (i != str2sprite.end()) {
		result = true;
		str2sprite.erase(i);
	}
	return result;
}

//-------------------------------------------------------------------------------------------

//void SpriteHolder::RemoveDeadSprites (void){ 
//	sprites.remove_if(RemoveFunctor()); 
//}

//-------------------------------------------------------------------------------------------

const SpriteList SpriteHolder::GetSprites (void) { 
	SpriteList sprites;
	std::transform(
		str2sprite.begin(), 
		str2sprite.end(), 
		std::back_inserter(sprites), 
		RetrieveValue()
	);
	return sprites; 
}

//-------------------------------------------------------------------------------------------

Sprite*	SpriteHolder::GetSprite (const std::string& id) {
	String2SpriteMapping::iterator i = str2sprite.find(id);
	return i != str2sprite.end()? i->second : (Sprite*)0;
}

//-------------------------------------------------------//
//---- struct RemoveFunctor -----------------------------//

//bool SpriteHolder::RemoveFunctor::operator()(Sprite* s) {
//	if (!s->IsAlive()) {
//		str2sprite.erase(s->GetId());
//		return true;
//	}
//	return false; 
//}

}	//namespace engine