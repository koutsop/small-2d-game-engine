#ifndef ANIMATION_FILM_H
#define ANIMATION_FILM_H

#include <string>
#include "Common.h"
#include "Graphics.h"

namespace engine {

class AnimationFilm {
public:
	std::size_t				GetTotalFrames (void) const 
								{ return boxes.size(); }
    Bitmap					GetBitmap (void) const 
								{ assert(bitmap); return bitmap; }
    const std::string & 	GetId (void) const 
								{ assert(id != ""); return id; }
    const Rect				GetFrameBox (std::size_t frameNo) const
								{ assert(boxes.size() > frameNo); return boxes[frameNo]; }
    void					DisplayFrame (Bitmap dest, const Point& at, std::size_t frameNo) const;
	void					DisplayFrame (const Point& at, std::size_t frameNo) const;
								
	AnimationFilm (void);
	AnimationFilm (Bitmap bitmap_, const RectVec & bbs, const std::string& id_);


private:
    RectVec		boxes;
    Bitmap		bitmap;
    std::string	id;

};

}	//namespace engine

#endif