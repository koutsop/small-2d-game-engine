/**
 *	Graphics.h
 *
 *	Nikoloas Koutsopoulos <koutsop@gmail.com>
 *	November 2013
 */

#ifndef	GRAPHICS_H
#define GRAPHICS_H


#include <allegro5/allegro.h>

#include "DLLs.h"
#include "Common.h"

namespace engine {
	
	//////////////////////////////////////////
	//	typedef
	typedef ALLEGRO_BITMAP Bitmap;

	//-----------------------------------------------------------------------

	void ENGINE_API InitialiseGraphics (void);
	void ENGINE_API CleanUpGraphics (void);

	//-----------------------------------------------------------------------

	void ENGINE_API Display (int w, int h, bool fullScreen = false);

	//-----------------------------------------------------------------------

	void ENGINE_API DestroyDisplay (void);

	//-----------------------------------------------------------------------

	void ENGINE_API Rest (double seconds);

	//-----------------------------------------------------------------------

	ENGINE_API Bitmap * LoadBitmapFromFile (const std::string& path);	

	//-----------------------------------------------------------------------

	void ENGINE_API DestroyBitmap (Bitmap* b);		

	//-----------------------------------------------------------------------

	void ENGINE_API DrawBitmap (Bitmap* b, const Point& at);
	void ENGINE_API DrawBitmap (Bitmap* b, int x, int y);

	//-----------------------------------------------------------------------

	void ENGINE_API DrawSubBitmap (Bitmap* source, const Rect & rect, const Point& at);

	//-----------------------------------------------------------------------

	void ENGINE_API MaskedDraw (Bitmap* source, Bitmap* dest, const Rect & rect, const Point& at); 

	//-----------------------------------------------------------------------

	void ENGINE_API SetCanvas (Bitmap* b);

	//-----------------------------------------------------------------------

	void ENGINE_API SetBufferAsCanvas (void);
	
	//-----------------------------------------------------------------------

	void ENGINE_API ConvertMaskToAlpha (Bitmap* bitmap, int r, int g, int b);

	//-----------------------------------------------------------------------
	
	void ENGINE_API FlipDisplay (void);

	//-----------------------------------------------------------------------

	void ENGINE_API HideMouseCursor (void);

}	//namesapce engine

#endif	//GRAPHICS_H