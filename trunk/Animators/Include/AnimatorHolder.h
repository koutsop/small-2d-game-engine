#ifndef ANIMATOR_HOLDER_H
#define ANIMATOR_HOLDER_H

#include <functional>
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
	static void RemoveDeadAnimators (void);

private:
	static timestamp_t		pauseTime;
	static AnimatorListPtr	running, suspended, paused;

	struct CheckFunctor : public std::unary_function<Animator*, bool> {
		bool operator() (Animator* a)
			{ return !a->IsAlive(); }
	};
};

}	//namespace engine

#endif //ANIMATOR_HOLDER_H