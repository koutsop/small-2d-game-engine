#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <list>
#include "Clock.h"

namespace engine {

enum animatorstate_t {
	ANIMATOR_FINISHED	= 0,
	ANIMATOR_RUNNING	= 1,
	ANIMATOR_STOPPED	= 2
};


class Animator {
public:
	typedef void (*FinishCallback)(Animator*, void*);

	Animator (void); 
	virtual ~Animator(){};

	void			Stop (void);
	bool			HasFinished (void) const;
	virtual void	TimeShift (timestamp_t offset);
	virtual void	Progress (timestamp_t currTime) = 0;
	void			SetOnFinish (FinishCallback f, void* c=(void*) 0);
	

protected:
	void			NotifyStopped (void);
	
	timestamp_t		lastTime;
	animatorstate_t	state;
	FinishCallback	onFinish;
	void *			finishClosure;
	
};

typedef std::list<Animator*> AnimatorListPtr;

}	//namespace engine


#endif //ANIMATOR_H