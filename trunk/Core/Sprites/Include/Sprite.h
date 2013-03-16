#ifndef SPRITE_H
#define SPRITE_H

#include <list>
#include <string>
#include "DLLs.h"
#include "Common.h"
#include "Graphics.h"
#include "AnimationFilm.h"
#include "LatelyDestroyable.h"

namespace engine {

class Sprite;
typedef std::list<Sprite *> SpriteList;

class ENGINE_API Sprite : public LatelyDestroyable  {
public:
	///--- Constructors
    Sprite (Dim _x, Dim _y, AnimationFilm* film, const std::string& id_);

	///--- Class Sprite API
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
	const std::string& 		
					GetId (void) const; 

	void			Display (Bitmap* dest);
	virtual void	Move (Dim x, Dim y) = 0;
	virtual bool	CollisionCheck (Sprite* s);
    
protected:
	virtual ~Sprite () {}		//LatelyDestroyable design pattern

	///--- protected Member Variables
    byte			frameNo;
    Rect			frameBox;
    Dim				x, y;
    bool			isVisible;
    AnimationFilm*	currFilm;
	std::string		id;
};


}


#endif //SPRITE_H