#include "FlashAnimation.h"

namespace engine {

//---------------------------------------------------

FlashAnimation::FlashAnimation (
	frame_t n, 
	delay_t show, 
	delay_t hide,
	animid_t id
):	repetitions(n), 
	hideDelay(hide), 
	showDelay(show), 
	Animation(id){}

//---------------------------------------------------

void FlashAnimation::SetRepetitions (frame_t n) 
	{ repetitions = n; }

//---------------------------------------------------

frame_t	FlashAnimation::GetRepetitions (void) const 
	{ return repetitions; }

//---------------------------------------------------

void FlashAnimation::SetHideDelay (delay_t d) 
	{ hideDelay = d; }

//---------------------------------------------------

delay_t	FlashAnimation::GetHideDelay (void) const 
	{ return hideDelay; }

//---------------------------------------------------

void FlashAnimation::SetShowDelay (delay_t d) 
	{ showDelay = d; }

//---------------------------------------------------

delay_t	FlashAnimation::GetShowDelay (void) const 
	{ return showDelay; }

//---------------------------------------------------

Animation *	FlashAnimation::Clone (animid_t newId) const
	{ return new FlashAnimation(repetitions, hideDelay, showDelay, newId); }
}