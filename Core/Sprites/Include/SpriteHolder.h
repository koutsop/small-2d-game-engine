#ifndef SPRITE_HOLDER_H
#define SPRITE_HOLDER_H

#include <map>
#include <string>
#include <functional>
#include "DLLs.h"
#include "Sprite.h"
#include "Graphics.h"


namespace engine {

class ENGINE_API SpriteHolder {
public:
	///--- Class SpriteHolder API

	static bool			Register (Sprite * s);
	static void			Clear (void);	//marks all sprites as dead
	static void			Display (Bitmap* source = (Bitmap*)0);
	static bool			Cancel (const std::string& id); //marks the sprite as dead
	//static void			RemoveDeadSprites (void);
	static const SpriteList	
						GetSprites (void);
	static Sprite*		GetSprite (const std::string& id);

private:
	//friend struct RemoveFunctor;
	
	typedef std::pair<std::string, Sprite *>	String2SpritePair;
	typedef std::map<std::string, Sprite *>		String2SpriteMapping;
	
	///--- member variables
	static String2SpriteMapping	str2sprite;
	//static SpriteList		sprites;

	//----------------------------
	//-- struct SpriteHolder::RemoveFunctor	

	//struct RemoveFunctor : public std::unary_function<Sprite*, bool> {
	//	bool operator() (Sprite* s);
	//};

	struct ClearFunctor : public std::unary_function<String2SpritePair, void> {
		void operator() (String2SpritePair p)
			{ p.second->Destroy(); }		
	};

	struct DisplayFunctor : public std::unary_function<String2SpritePair, void> {
		engine::Bitmap* source;
		DisplayFunctor (engine::Bitmap* s) : source (s) {}

		void operator() (const String2SpritePair & p){ 
			if (p.second->IsVisible())
				p.second->Display(source); 
		}
	};
};

}	//namespace engine

#endif	//SPRITE_HOLDER_H