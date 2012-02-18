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

private:
	class ProgressFunctor : public std::unary_function<Animator*, void> {
	    timestamp_t t;
	public: 
	    ProgressFunctor (timestamp_t _t) : t(_t){}

		void operator()(Animator* a) const 
			{ a->Progress(t); }
	};

	static timestamp_t		pauseTime;
	static AnimatorListPtr	running, suspended, paused;
};

}	//namespace engine

#endif //ANIMATOR_HOLDER_H