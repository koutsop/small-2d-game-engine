#include "CollisionChecker.h"

namespace engine {

std::list<CollisionChecker::CollisionPair> CollisionChecker::pairs;

//---------------------------------------------------

void CollisionChecker::Register (Sprite* s1, Sprite* s2, CollideCallback c) {
	assert (s1 && s2);
	pairs.push_back(CollisionPair(std::make_pair(s1, s2), c));
}

//---------------------------------------------------

void CollisionChecker::Cancel (Sprite* s1, Sprite* s2) {
	assert (s1 && s2);
	pairs.remove_if(MatchFunctor(s1, s2));
}

//---------------------------------------------------

void CollisionChecker::Check (void) {
	std::list<CollisionPair>::iterator start	= pairs.begin();
	std::list<CollisionPair>::iterator end		= pairs.end();

	while (start != end) {	//mporei na kanoume cancel eno trexei to loop
		CollisionPair & p = *start++;
		if (p.sprites.first->CollisionCheck(p.sprites.second))
			p.collide(p.sprites.second);
	}	
}


}