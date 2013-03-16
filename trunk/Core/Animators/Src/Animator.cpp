#include "Animator.h"

namespace engine {

//-----------------------------------------------------------------------

Animator::Animator (void) :
    lastTime(0), 
	state(ANIMATOR_FINISHED), 
    onFinish((FinishCallback) 0), 
	finishClosure((void*) 0)
{}


//-----------------------------------------------------------------------

void Animator::Stop (void) {
	if (!HasFinished()) {
		state = ANIMATOR_STOPPED;
		NotifyStopped();
	}
}

//-----------------------------------------------------------------------

bool Animator::HasFinished (void) const { 
	return state != ANIMATOR_RUNNING; 
}

//-----------------------------------------------------------------------

void Animator::TimeShift (timestamp_t offset) 
	{ lastTime += offset; }

//-----------------------------------------------------------------------

void Animator::SetOnFinish (FinishCallback f, void* c) { 
	onFinish = f, 
	finishClosure = c; 
}

//-----------------------------------------------------------------------

void Animator::NotifyStopped (void) {
	if (onFinish)
		(*onFinish)(this, finishClosure);
}

		
}