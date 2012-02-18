#ifndef FRAME_RANGE_ANIMATION_H
#define FRAME_RANGE_ANIMATION_H

#include "MovingAnimation.h"

namespace engine {

class FrameRangeAnimation : public MovingAnimation {
public:
    FrameRangeAnimation (
        frame_t		s, 
		frame_t		e, 
        offset_t	dx, 
		offset_t	dy, 
		delay_t		d, 
		bool		c, 
		animid_t	id
    );

    frame_t		GetStartFrame (void) const;
    void	 	SetStartFrame (frame_t v);
    frame_t		GetEndFrame (void) const;
    void	    SetEndFrame (frame_t v);
	Animation*	Clone (animid_t newId) const;

private:
	frame_t start, end;
};

}

#endif //FRAME_RANGE_ANIMATION_H