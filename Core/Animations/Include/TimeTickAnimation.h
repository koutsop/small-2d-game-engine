#ifndef TICK_ANIMATION_H
#define TICK_ANIMATION_H

#include "Common.h"
#include "Animation.h"

namespace engine {

class ENGINE_API TimeTickAnimation : public Animation {
public:
	typedef void (*TickFunc)(void* closure);

	TimeTickAnimation (animid_t id) :
		Animation(id),
		delay(0),
		repetitions(1),
		action((TickFunc)0),
		closure((void*) 0){}

	virtual Animation*	Clone (animid_t newId) const;

protected:
	virtual				~TimeTickAnimation () {}			//LatelyDestroyable design pattern

private:
	delay_t		delay;
	byte		repetitions;
	TickFunc	action;
	void*		closure;
};

}	//namespace engine


#endif	//TICK_ANIMATION_H