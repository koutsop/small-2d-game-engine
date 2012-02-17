#ifndef	GRAPHICS_H
#define GRAPHICS_H

#include <allegro5/allegro.h>
#include "Common.h"

namespace engine {
	//////////////////////////////////////////
	//	typedef
	typedef ALLEGRO_BITMAP * Bitmap;

	//---------------------------------------------------

	bool InitGraphics (void);

	//---------------------------------------------------

	Bitmap	LoadBitmap (const std::string& path);	

	//---------------------------------------------------

	void	DestroyBitmap (Bitmap);					

	//---------------------------------------------------

	void	MaskedBlit (Bitmap source, Bitmap dest, const Rect & rect, const Point& at); 

}	//namesapce engine

#endif	//GRAPHICS_H