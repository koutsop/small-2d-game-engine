#include <algorithm>
#include "AnimatorHolder.h"

namespace engine {

AnimatorListPtr	AnimatorHolder::paused;
AnimatorListPtr AnimatorHolder::running; 
AnimatorListPtr	AnimatorHolder::suspended;

//---------------------------------------------------

void AnimatorHolder::Pause (void) {
	//startPauseTime = MyTime::GetSystemTime();

	//std::list<Animator*>::iterator start	= running.begin();
	//std::list<Animator*>::iterator end		= running.end();

	//while(start!=end){
	//	Animator * a = (*start);
	//	start++;
	//	running.remove(a);
	//	paused.push_back(a);
	//}
}

//---------------------------------------------------

void AnimatorHolder::Resum (void) {
	//timestamp_t pauseTime = MyTime::GetSystemDiffTime( MyTime::GetSystemTime(), startPauseTime);
	//std::list<Animator*>::iterator start	= paused.begin();
	//std::list<Animator*>::iterator end		= paused.end();

	//while(start!=end){
	//	Animator *a = (*start);
	//	start++;
	//	a->TimeShift(pauseTime);
	//	paused.remove(a);
	//	running.push_back(a);
	//}
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
	//std::for_each(
	//	running.begin(), running.end(), ProgressFunctor(currTime)
	//); 
}


}