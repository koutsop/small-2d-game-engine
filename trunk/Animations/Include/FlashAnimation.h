#ifndef FLASH_ANIMATION_H
#define FLASH_ANIMATION_H

#include "Animation.h"

namespace angine {

class FlashAnimation : public Animation {
public:
    frame_t		SetRepetitions (frame_t n) 
					{ repetitions = n; }
    frame_t		GetRepetitions (void) const 
					{ return repetitions; }
    void		SetHideDeay (delay_t d) 
					{ hideDelay = d; }
    delay_t		GetHideDeay (void) const 
					{ return hideDelay; }
    void		SetShowDeay (delay_t d) 
					{ showDelay = d; }
    delay_t		GetShowDeay (void) const 
					{ return showDelay; }

    Animation*	Clone (animid_t newId) const
					{ return new FlashAnimation(repetitions, hideDelay, showDelay, newId); }

    FlashAnimation (frame_t n, delay_t show, delay_t hide,animid_t id ) :
		repetitions(n), hideDelay(hide), showDelay(show), Animation(id){}

private:
	frame_t		repetitions;
    delay_t		hideDelay;
    delay_t		showDelay;
};


}	//engine

#endif	//FLASH_ANIMATION_H