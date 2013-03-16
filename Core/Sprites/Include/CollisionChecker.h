#ifndef COLLISION_CHECKER_H
#define COLLISION_CHECKER_H

#include <list>
#include <assert.h>
#include <functional>
#include "DLLs.h"
#include "Sprite.h"

namespace engine {

class ENGINE_API CollisionChecker {
public:
	///--- class CollisionChecker Typedefs
	typedef std::function<void (Sprite*)> CollideCallback;

	///--- class CollisionChecker API
    static void Register (Sprite* s1, Sprite* s2, CollideCallback c);
    static void Cancel (Sprite* s1, Sprite* s2);
    static void Check (void);

private:
	///--- class CollisionChecker Typedefs
	typedef std::pair<Sprite*, Sprite*> SpritePair;

	//----------------------------
	//-- struct CollisionChecker::CollisionPair

	struct CollisionPair {
		SpritePair		sprites;
		CollideCallback collide;
		CollisionPair (const SpritePair & p, CollideCallback c) : sprites(p), collide(c) {}
	};

	//----------------------------
	//-- struct CollisionChecker::MatchFunctor
    
	struct MatchFunctor : public std::unary_function<CollisionPair, bool> {
		Sprite * s1, * s2;
		MatchFunctor (Sprite * s1_, Sprite * s2_) : s1(s1_), s2(s2_) {} 
		bool operator()(const CollisionPair& p) { 
			assert(p.sprites.first && p.sprites.second);
			return	s1 == p.sprites.first &&
					s2 == p.sprites.second;
		}
    };

	///--- private Member Variables
    static std::list<CollisionPair> pairs;
};


}	//namespace engine

#endif	//COLLISION_CHECKER_H