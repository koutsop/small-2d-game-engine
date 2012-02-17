#include "AnimationFilm.h"


namespace engine {

AnimationFilm::AnimationFilm (void) : bitmap((Bitmap)0), boxes (), id ("") {}

//---------------------------------------------------
    
AnimationFilm::AnimationFilm (
	Bitmap				bitmap_, 
	const RectVec &		bbs, 
	const std::string&	id_)
:	bitmap(bitmap_),
	boxes(bbs),
	id(id_)
{}

//---------------------------------------------------

void AnimationFilm::DisplayFrame (
		Bitmap			dest, 
		const Point&	at, 
		std::size_t		frameNo
	) const {
	MaskedBlit(bitmap, dest, GetFrameBox(frameNo), at);
}



}	//namespace engine