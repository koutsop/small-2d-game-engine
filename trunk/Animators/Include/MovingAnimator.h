#ifndef MOVING_ANIMATOR_H
#define MOVING_ANIMATOR_H


#include "Animator.h"
#include "MovingAnimation.h"
namespace engine {

class MovingAnimator : public Animator {
	public:
	void Progress (timestamp_t currTime);
	/*void Start (Sprite* s, MovingAnimation* a, timestamp_t t) {
		sprite		= s;
		anim 		= a;
		lastTime 	= t;
		state 		= ANIMATOR_RUNNING;
	}*/

	//MovingAnimator (void): sprite((Sprite*) 0), anim((MovingAnimation*) 0){}
	~MovingAnimator(){}

private:
	//Sprite*				sprite;
	MovingAnimation*	anim;



};

}	//namespace engine

#endif