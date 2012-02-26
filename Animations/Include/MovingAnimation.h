#ifndef	MOVING_ANIMATION_H
#define	MOVING_ANIMATION_H

#include "Animation.h"

namespace engine {

class MovingAnimation : public Animation {
public:
    MovingAnimation (
		offset_t	_dx, 
		offset_t	_dy, 
		delay_t		_delay, 
		bool		c, 
		animid_t	_id
    );

	offset_t	GetDx (void) const;
    void	    SetDx (offset_t v);
    offset_t  	GetDy (void) const;
    void	    SetDy (offset_t v);
    delay_t   	GetDelay (void) const;
    void	    SetDelay (delay_t v);
    bool		GetContinuous (void) const;
    void	 	SetContinuous (bool v);
    Animation*	Clone (animid_t newId) const;

protected:
	virtual		~MovingAnimation (void) {}			//LatelyDestroyable design pattern

private:
	offset_t	dx, dy;
    delay_t		delay;
    bool		continuous;
};


}	//namespace engine

#endif	//MOVING_ANIMATION_H