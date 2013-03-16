#include <algorithm>
#include "AnimatorManager.h"


namespace engine {

timestamp_t		AnimatorManager::pauseTime;
AnimatorListPtr	AnimatorManager::paused;
AnimatorListPtr AnimatorManager::running; 
AnimatorListPtr	AnimatorManager::suspended;

//-----------------------------------------------------------------------

void AnimatorManager::Pause (void) {
	pauseTime						= Clock::GetSystemTime();
	AnimatorListPtr::iterator start	= running.begin();

	while(start != running.end()){
		Animator * a = *start++;
		running.remove(a);
		paused.push_back(a);
	}
}

//-----------------------------------------------------------------------

void AnimatorManager::Resum (void) {
	timestamp_t diffTime			= Clock::DiffTime(Clock::GetSystemTime(), pauseTime);
	AnimatorListPtr::iterator start	= paused.begin();

	while(start != paused.end()){
		Animator * a = *start++;
		a->TimeShift(diffTime);
		paused.remove(a);
		running.push_back(a);
	}
}

//-----------------------------------------------------------------------

void AnimatorManager::Clear (void) {
	std::for_each(
		running.begin(),
		running.end(),
		std::mem_fn(&Animator::Destroy)
	);

	std::for_each(
		suspended.begin(),
		suspended.end(),
		std::mem_fn(&Animator::Destroy)
	);

	std::for_each(
		paused.begin(),
		paused.end(),
		std::mem_fn(&Animator::Destroy)
	);

	paused.clear();
	running.clear();
	suspended.clear();
}

//-----------------------------------------------------------------------

void AnimatorManager::Register (Animator* a) 
	{ suspended.push_back(a); }

//-----------------------------------------------------------------------

void AnimatorManager::Cancel (Animator* a) { 
	if (!a->HasFinished()) {
		a->Stop();
		MarkAsSuspended(a);
	}
	suspended.remove(a); 
	a->Destroy();
}

//-----------------------------------------------------------------------

void AnimatorManager::MarkAsRunning (Animator* a) { 
	suspended.remove(a); 
	running.push_back(a); 
}

//-----------------------------------------------------------------------

void AnimatorManager::MarkAsSuspended (Animator* a) { 
	running.remove(a); 
	suspended.push_back(a); 
}

//-----------------------------------------------------------------------

void AnimatorManager::Progress (timestamp_t currTime) {
	for (AnimatorListPtr::iterator a = running.begin(); a != running.end(); ++a)
		 (*a)->Progress(currTime);
}

//-----------------------------------------------------------------------

//void AnimatorManager::RemoveDeadAnimators (void) {
//	suspended.remove_if(CheckFunctor());
//}


}