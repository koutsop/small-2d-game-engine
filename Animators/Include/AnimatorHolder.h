#ifndef ANIMATOR_HOLDER_H
#define ANIMATOR_HOLDER_H

#include "Clock.h"
#include "Animator.h"

namespace engine {

class AnimatorHolder {
public:
	static void Pause (void);
	static void Resum (void);
	static void Register (Animator* a);
	static void Cancel (Animator* a);
	static void MarkAsRunning (Animator* a);
	static void MarkAsSuspended (Animator* a);
	static void Progress (timestamp_t currTime);

private:
	static timestamp_t		pauseTime;
	static AnimatorListPtr	running, suspended, paused;
};

}	//namespace engine

#endif //ANIMATOR_HOLDER_H