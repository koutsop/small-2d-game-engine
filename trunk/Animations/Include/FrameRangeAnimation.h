#ifndef FRAME_RANGE_ANIMATION_H
#define FRAME_RANGE_ANIMATION_H

#include "MovingAnimation.h"

namespace engine {

typedef unsigned char frame_t;

class FrameRangeAnimation : public MovingAnimation {
public:
    frame_t		GetStartFrame (void) const 
					{ return start; }
    void	 	SetStartFrame (frame_t v) 
					{ start = v; }
    frame_t		GetEndFrame (void) const 
					{ return end; }
    void	    SetEndFrame (frame_t v) 
					{ end = v; }
    
	Animation*	Clone (animid_t newId) const {
        return new FrameRangeAnimation(
						start, 
						end, 
						GetDx(), 
						GetDy(), 
						GetDelay(), 
						GetContinuous(), 
						newId
					);
    }

    FrameRangeAnimation (
        frame_t		s, 
		frame_t		e, 
        offset_t	dx, 
		offset_t	dy, 
		delay_t		d, 
		bool		c, 
		animid_t	id
    ): start(s), end(e), MovingAnimation(dx, dy, d, c, id){}

private:
	frame_t start, end;
};

}

#endif //FRAME_RANGE_ANIMATION_H