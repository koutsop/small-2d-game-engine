#include "FrameRangeAnimator.h"

namespace engine {

//-----------------------------------------------------------------------

void FrameRangeAnimator::Progress (timestamp_t currTime) {
	if(currTime - lastTime >= anim->GetDelay()){
	    if (currFrame == anim->GetEndFrame())
			currFrame = anim->GetStartFrame();
	    else
			++currFrame;
	    sprite->Move( anim->GetDx(), anim->GetDy() );
	    sprite->SetFrame(currFrame);
	    lastTime += anim->GetDelay();

	    if (currFrame == anim->GetEndFrame() && !anim->GetContinuous()) {
			state = ANIMATOR_FINISHED;
			NotifyStopped();
			return;
	    }
	}
}

//-----------------------------------------------------------------------

void FrameRangeAnimator::Start (Sprite* s, FrameRangeAnimation* a, timestamp_t t) {
	sprite		= s;
	anim		= a;
	lastTime	= t;
	state		= ANIMATOR_RUNNING;
	sprite->SetFrame(currFrame = anim->GetStartFrame());
}	

//-----------------------------------------------------------------------

Animation* FrameRangeAnimator::GetAnimation (void)
	{ return anim; }

}