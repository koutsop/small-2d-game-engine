#include "AnimationFilm.h"


namespace engine {

AnimationFilm::AnimationFilm (void) : bitmap((Bitmap)0), boxes (), id ("") {}

//-----------------------------------------------------------------------
    
AnimationFilm::AnimationFilm (
	Bitmap				bitmap_, 
	const RectVec &		bbs, 
	const std::string&	id_)
:	bitmap(bitmap_),
	boxes(bbs),
	id(id_)
{}

//-----------------------------------------------------------------------

void AnimationFilm::DisplayFrame (
		Bitmap			dest, 
		const Point&	at, 
		byte			frameNo
	) const {
	MaskedDraw(bitmap, dest, GetFrameBox(frameNo), at);
}

//-----------------------------------------------------------------------

void AnimationFilm::DisplayFrame (const Point&	at, byte frameNo) const 
	{ DrawSubBitmap(bitmap, GetFrameBox(frameNo), at); }

//-----------------------------------------------------------------------

byte AnimationFilm::GetTotalFrames (void) const 
	{ return boxes.size(); }

//-----------------------------------------------------------------------

Bitmap AnimationFilm::GetBitmap (void) const 
	{ assert(bitmap); return bitmap; }

//-----------------------------------------------------------------------

const std::string & AnimationFilm::GetId (void) const 
	{ assert(id != ""); return id; }

//-----------------------------------------------------------------------

const Rect& AnimationFilm::GetFrameBox (byte frameNo) const
	{ assert(boxes.size() > frameNo); return boxes[frameNo]; }

}	//namespace engine