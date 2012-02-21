#include <algorithm>
#include "AnimatorHolder.h"

namespace engine {

AnimatorListPtr	AnimatorHolder::paused;
AnimatorListPtr AnimatorHolder::running; 
AnimatorListPtr	AnimatorHolder::suspended;

//---------------------------------------------------

void AnimatorHolder::Pause (void) {
	pauseTime						= Clock::GetSystemTime();
	AnimatorListPtr::iterator start	= running.begin();

	while(start != running.end()){
		Animator * a = *start++;
		running.remove(a);
		paused.push_back(a);
	}
}

//---------------------------------------------------

void AnimatorHolder::Resum (void) {
	timestamp_t diffTime			= Clock::DiffTime(Clock::GetSystemTime(), pauseTime);
	AnimatorListPtr::iterator start	= paused.begin();

	while(start != paused.end()){
		Animator * a = *start++;
		a->TimeShift(diffTime);
		paused.remove(a);
		running.push_back(a);
	}
}

//---------------------------------------------------

void AnimatorHolder::Register (Animator* a) 
	{ suspended.push_back(a); }

//---------------------------------------------------

void AnimatorHolder::Cancel (Animator* a) 
	{ suspended.remove(a); }

//---------------------------------------------------

void AnimatorHolder::MarkAsRunning (Animator* a) { 
	suspended.remove(a); 
	running.push_back(a); 
}

//---------------------------------------------------

void AnimatorHolder::MarkAsSuspended (Animator* a) { 
	running.remove(a); 
	suspended.push_back(a); 
}

//---------------------------------------------------

void AnimatorHolder::Progress (timestamp_t currTime) {
	for (AnimatorListPtr::iterator a = running.begin(); a != running.end(); ++a)
		 (*a)->Progress(currTime);
}

//---------------------------------------------------

void AnimatorHolder::RemoveDeadAnimators (void) {
	suspended.remove_if(CheckFunctor());
}


}