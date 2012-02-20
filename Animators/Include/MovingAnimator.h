#ifndef MOVING_ANIMATOR_H
#define MOVING_ANIMATOR_H

#include "Sprite.h"
#include "Animator.h"
#include "MovingAnimation.h"

namespace engine {

class MovingAnimator : public Animator {
public:
	MovingAnimator (void): sprite((Sprite*) 0), anim((MovingAnimation*) 0){}
	~MovingAnimator(){}

	void Progress (timestamp_t currTime);
	void Start (Sprite* s, MovingAnimation* a, timestamp_t t);

private:
	Sprite*				sprite;
	MovingAnimation*	anim;
};

}	//namespace engine

#endif