#ifndef FRAME_RANGE_ANIMATOR_H
#define FRAME_RANGE_ANIMATOR_H

#include "Sprite.h"
#include "Animator.h"
#include "FrameRangeAnimation.h"

namespace engine {

class FrameRangeAnimator : public Animator {
public:
	FrameRangeAnimator (void): 
	 	sprite		((Sprite*) 0), 
		anim		((FrameRangeAnimation*) 0), 
		currFrame	(0xFF){}
	~FrameRangeAnimator(){}


	void Progress (timestamp_t currTime);
	void Start (Sprite* s, FrameRangeAnimation* a, timestamp_t t);
private:
	Sprite*			sprite;
	FrameRangeAnimation*	anim;
	frame_t			currFrame;


};



}	//namespace engine

#endif	//FRAME_RANGE_ANIMATOR_H