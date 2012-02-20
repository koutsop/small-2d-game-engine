
#include <algorithm>
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
	std::remove_if(
 	    pairs.begin(), 
		pairs.end(), 
		MatchFunctor (s1, s2)
	);
}

//---------------------------------------------------

void CollisionChecker::Check (void) {
	std::for_each(
 	    pairs.begin(), 
		pairs.end(), 
		CheckFunctor()
	);
}


}