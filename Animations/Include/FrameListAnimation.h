#ifndef FRAME_LIST_ANIMATION_H
#define FRAME_LIST_ANIMATION_H

#include <list>
#include "MovingAnimation.h"

namespace engine{

class FrameListAnimation : public MovingAnimation {
public:
	typedef std::list<frame_t> Frame_tList;


    const Frame_tList&	GetFrames (void) const 
							{ return frames; }
    void				SetFrames (const std::list<frame_t>& f) 
							{ frames.clear(); frames = f; }
    Animation*			Clone (animid_t newId) const {
							return new FrameListAnimation(
											frames, GetDx(), GetDy(), GetDelay(), GetContinuous(), newId
  										); 
						}

    FrameListAnimation (
		const Frame_tList& _frames, 
		offset_t dx, offset_t dy, delay_t d, bool c, animid_t id
    ): frames(_frames), MovingAnimation(dx, dy, d, c, id){}

private:
	Frame_tList frames;
};


}	//namespace engine

#endif