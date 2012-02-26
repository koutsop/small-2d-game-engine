#include "MovingAnimator.h"

namespace engine {

void MovingAnimator::Progress (timestamp_t currTime) {
	if (currTime - lastTime >= anim->GetDelay()) {
		sprite->Move(anim->GetDx(), anim->GetDy());
		lastTime += anim->GetDelay();
		
		if (!anim->GetContinuous()) {
			state = ANIMATOR_FINISHED;
			NotifyStopped();
		}
		//else {
			//lastTime += anim->GetDelay();
			//Progress(currTime);  // Recursion (make loop)
		//}
	}
	return;
}

//-----------------------------------------------------------------------

void MovingAnimator::Start(Sprite* s, MovingAnimation* a, timestamp_t t) {
	sprite		= s;
	anim 		= a;
	lastTime 	= t;
	state 		= ANIMATOR_RUNNING;
}

//-----------------------------------------------------------------------

Animation* MovingAnimator::GetAnimation (void)
	{ return anim; }

}