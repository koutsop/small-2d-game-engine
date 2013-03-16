#ifndef FRAME_RANGE_ANIMATOR_H
#define FRAME_RANGE_ANIMATOR_H

#include "Sprite.h"
#include "Animator.h"
#include "FrameRangeAnimation.h"

namespace engine {

class ENGINE_API FrameRangeAnimator : public Animator {
public:
	FrameRangeAnimator (void): 
	 	sprite		((Sprite*) 0), 
		anim		((FrameRangeAnimation*) 0), 
		currFrame	(0xFF){}
	
	void			Progress (timestamp_t currTime);
	void			Start (Sprite* s, FrameRangeAnimation* a, timestamp_t t);
	virtual Animation*
					GetAnimation (void);


protected:
	virtual			~FrameRangeAnimator(void) {}			//LatelyDestroyable design pattern

private:
	Sprite*			sprite;
	FrameRangeAnimation*	anim;
	frame_t			currFrame;


};



}	//namespace engine

#endif	//FRAME_RANGE_ANIMATOR_H