#ifndef ANIMATION_FILM_H
#define ANIMATION_FILM_H

#include <string>
#include "DLLs.h"
#include "Common.h"
#include "Graphics.h"

#ifdef _WIN32
	#pragma warning (disable:4251)
#endif

namespace engine {

class ENGINE_API AnimationFilm {
public:
	byte					GetTotalFrames (void) const;
    Bitmap*					GetBitmap (void) const;
    const std::string&	 	GetId (void) const;
    const Rect&				GetFrameBox (byte frameNo) const;
    void					DisplayFrame (Bitmap* dest, const Point& at, byte frameNo) const;
	void					DisplayFrame (const Point& at, byte frameNo) const;
								
	AnimationFilm (void);
	AnimationFilm (Bitmap* bitmap_, const RectVec & bbs, const std::string& id_);


private:
    RectVec		boxes;
    Bitmap*		bitmap;
    std::string	id;

};

}	//namespace engine

#endif