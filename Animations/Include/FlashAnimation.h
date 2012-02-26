#ifndef FLASH_ANIMATION_H
#define FLASH_ANIMATION_H

#include "Animation.h"

namespace engine {

class FlashAnimation : public Animation {
public:
    FlashAnimation (frame_t n, delay_t show, delay_t hide, animid_t id);

    void		SetRepetitions (frame_t n);
    frame_t		GetRepetitions (void) const;
    void		SetHideDelay (delay_t d);
    delay_t		GetHideDelay (void) const;
    void		SetShowDelay (delay_t d);
    delay_t		GetShowDelay (void) const;
    Animation*	Clone (animid_t newId) const;

protected:
	virtual		~FlashAnimation() {}			//LatelyDestroyable design pattern

private:
	frame_t		repetitions;
    delay_t		hideDelay;
    delay_t		showDelay;
};


}	//engine

#endif	//FLASH_ANIMATION_H