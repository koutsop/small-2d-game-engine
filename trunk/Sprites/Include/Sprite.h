#ifndef SPRITE_H
#define SPRITE_H

#include "Common.h"
#include "Graphics.h"
#include "AnimationFilm.h"

namespace engine {


class Sprite {
public:
    Sprite (Dim _x, Dim _y, AnimationFilm* film);
	virtual ~Sprite () {}

    void			SetFrame (byte i);
    byte			GetFrame (void) const;
    void			SetVisibility (bool v);
    bool			IsVisible (void) const;
	void			SetPosition (const Point &p);
	void			SetPosition (Dim x_, Dim _y);
	Point			GetPosition (void) const;
	Dim				GetX (void) const;
	Dim				GetY (void) const;

	Rect			GetRect (void) const;
	Dim				GetWidth (void) const;
	Dim				GetHeight (void) const;

	void			Display (Bitmap dest);
	virtual bool	Move (Dim x, Dim y) = 0;
	virtual bool	CollisionCheck (Sprite* s);
    
private:
    byte			frameNo;
    Rect			frameBox;
    Dim				x, y;
    bool			isVisible;
    AnimationFilm*	currFilm;

};


}


#endif //SPRITE_H