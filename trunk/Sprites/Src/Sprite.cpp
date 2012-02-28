#include <assert.h>
#include "Sprite.h"

namespace engine {

//-------------------------------------------------------//
//---- Class Sprite -------------------------------------//

Sprite::Sprite (Dim _x, Dim _y, AnimationFilm* film, const std::string& id_)
:	x(_x), 
	y(_y), 
	frameNo (0),
	frameBox (),
	currFilm(film), 
	isVisible(true),
	id(id_){ 
	frameNo = currFilm->GetTotalFrames(); 
	SetFrame(0); 
}

//-----------------------------------------------------------------------

void Sprite::SetFrame (byte i) {	
	if (i != frameNo) {
		assert(i < currFilm->GetTotalFrames());
		frameBox = currFilm->GetFrameBox(frameNo = i);
	}
}

//-----------------------------------------------------------------------

byte Sprite::GetFrame (void) const 
	{ return frameNo; }

//-----------------------------------------------------------------------

void Sprite::SetVisibility (bool v) 
	{ isVisible = v; }

//-----------------------------------------------------------------------

bool Sprite::IsVisible (void) const 
	{ return isVisible; }

//-----------------------------------------------------------------------

bool Sprite::CollisionCheck (Sprite* s) {
	assert(s);
	return !(	(x				> s->GetX() + s->GetWidth())		||
				(x + frameBox.w < s->GetX())						||
				(y				> s->GetY() + s->GetHeight())	||
				(y + frameBox.h < s->GetY()) );
}

//-----------------------------------------------------------------------
void Sprite::Display (Bitmap* dest) { 
	if (!dest)
		currFilm->DisplayFrame(Point(x, y), frameNo); 
	else
		currFilm->DisplayFrame(dest, Point(x, y), frameNo); 
}

//-----------------------------------------------------------------------

void Sprite::SetPosition (const Point &p) 
	{ SetPosition (p.x, p.y); }

//-----------------------------------------------------------------------

void Sprite::SetPosition (Dim x_, Dim y_) {
	x = x_;
	y = y_;
}

//-----------------------------------------------------------------------

Point Sprite::GetPosition (void) const
	{ return Point(x, y);}

//-----------------------------------------------------------------------

Dim Sprite::GetX (void) const
	{ return x; }

//-----------------------------------------------------------------------

Dim Sprite::GetY (void) const
	{ return y; }

//-----------------------------------------------------------------------

Rect Sprite::GetRect (void) const
	{ return frameBox; }

//-----------------------------------------------------------------------

Dim	Sprite::GetWidth (void) const
	{ return frameBox.w; }

//-----------------------------------------------------------------------

Dim	Sprite::GetHeight (void) const
	{ return frameBox.h; }

//-----------------------------------------------------------------------

const std::string& Sprite::GetId (void) const
	{ return id; }

}	//namespace