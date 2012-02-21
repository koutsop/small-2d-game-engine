#ifndef SPRITE_HOLDER_H
#define SPRITE_HOLDER_H

#include <string>
#include <functional>
#include "Sprite.h"


namespace engine {

class SpriteHolder {
public:
	static void			Register (Sprite * s);
	static void			RemoveDeadSprites (void);
	static const SpriteList&	
						GetSprites (void);
	static Sprite*		GetSprite (const std::string& id);

private:
	static SpriteList sprites;

	struct CheckFunctor : public std::unary_function<Sprite*, bool> {
		bool operator() (Sprite* s)
			{ return !s->IsAlive(); }
	};

	struct FindFunctor : public std::unary_function<Sprite*, bool> {
		std::string id;
		FindFunctor (const std::string& id_) : id(id_) {}
		bool operator() (Sprite* s)
			{ return s->GetId() == id; }
	};

};

}	//namespace engine

#endif	//SPRITE_HOLDER_H