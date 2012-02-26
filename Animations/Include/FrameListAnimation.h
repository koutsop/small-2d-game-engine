#ifndef FRAME_LIST_ANIMATION_H
#define FRAME_LIST_ANIMATION_H

#include "Animation.h"
#include "MovingAnimation.h"

namespace engine{

class FrameListAnimation : public MovingAnimation {
public:
    FrameListAnimation (
		const Frame_tList&	_frames, 
		offset_t			dx, 
		offset_t			dy, 
		delay_t				d, 
		bool				c, 
		animid_t			id
    );

	const Frame_tList&	GetFrames (void) const;
    void				SetFrames (const Frame_tList& f);
    Animation*			Clone (animid_t newId) const;

protected:
	virtual				~FrameListAnimation(){}			//LatelyDestroyable design pattern

private:
	Frame_tList			frames;
};


}	//namespace engine

#endif