#ifndef SPRITE_HOLDER_H
#define SPRITE_HOLDER_H

#include <map>
#include <string>
#include <functional>
#include "Sprite.h"


namespace engine {

class SpriteHolder {
public:
	///--- Class SpriteHolder API

	static void			Register (Sprite * s);
	static void			RemoveDeadSprites (void);
	static const SpriteList&	
						GetSprites (void);
	static Sprite*		GetSprite (const std::string& id);

private:
	friend struct RemoveFunctor;
	
	typedef std::map<std::string, Sprite *> String2Sprite;
	
	///--- member variables
	static String2Sprite	str2sprite;
	static SpriteList		sprites;

	//----------------------------
	//-- struct SpriteHolder::RemoveFunctor	

	struct RemoveFunctor : public std::unary_function<Sprite*, bool> {
		bool operator() (Sprite* s);
	};
};

}	//namespace engine

#endif	//SPRITE_HOLDER_H