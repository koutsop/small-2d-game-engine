#include "FrameListAnimation.h"

namespace engine {


//-----------------------------------------------------------------------

FrameListAnimation::FrameListAnimation (
	const Frame_tList&	_frames, 
	offset_t			dx, 
	offset_t			dy, 
	delay_t				d, 
	bool				c, 
	animid_t			id
):	frames(_frames), 
	MovingAnimation(dx, dy, d, c, id){}

//-----------------------------------------------------------------------

const Frame_tList& FrameListAnimation::GetFrames (void) const 
	{ return frames; }

//-----------------------------------------------------------------------

void FrameListAnimation::SetFrames (const Frame_tList& f) 
	{ frames.clear(); frames = f; }

//-----------------------------------------------------------------------

Animation* FrameListAnimation::Clone (animid_t newId) const {
	return new FrameListAnimation(
					frames, 
					GetDx(), 
					GetDy(), 
					GetDelay(), 
					GetContinuous(), 
					newId
  				); 
}

}