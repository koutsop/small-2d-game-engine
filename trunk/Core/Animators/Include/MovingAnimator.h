#ifndef MOVING_ANIMATOR_H
#define MOVING_ANIMATOR_H

#include "Sprite.h"
#include "Animator.h"
#include "MovingAnimation.h"

namespace engine {

class ENGINE_API MovingAnimator : public Animator {
public:
	MovingAnimator (void);
	
	void			Progress (timestamp_t currTime);
	void			Start (Sprite* s, MovingAnimation* a, timestamp_t t);
	virtual Animation*
					GetAnimation (void);

protected:
	virtual			~MovingAnimator (){}			//LatelyDestroyable design pattern

private:
	Sprite*				sprite;
	MovingAnimation*	anim;
};

}	//namespace engine

#endif