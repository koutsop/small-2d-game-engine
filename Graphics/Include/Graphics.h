#ifndef	GRAPHICS_H
#define GRAPHICS_H

#include <allegro5/allegro.h>
#include "Common.h"

namespace engine {
	//////////////////////////////////////////
	//	typedef
	typedef ALLEGRO_BITMAP * Bitmap;

	//---------------------------------------------------

	void	InitialiseGraphics (void);
	void	CleanUpGraphics (void);

	//---------------------------------------------------
	void	Display (int w, int h);

	//---------------------------------------------------

	void	DestroyDisplay (void);

	//---------------------------------------------------

	Bitmap	LoadBitmap (const std::string& path);	

	//---------------------------------------------------

	void	DestroyBitmap (Bitmap);		

	//---------------------------------------------------

	void	DrawBitmap (Bitmap b, const Point& at);
	void	DrawBitmap (Bitmap b, int x, int y);

	//---------------------------------------------------

	void	DrawSubBitmap (Bitmap source, const Rect & rect, const Point& at);

	//---------------------------------------------------

	void	MaskedDraw (Bitmap source, Bitmap dest, const Rect & rect, const Point& at); 

	//---------------------------------------------------

	void	SetTargetBitmap (Bitmap b);

	//---------------------------------------------------

	void	SetBufferAsTargetBitmap (void);
	
	//---------------------------------------------------

	void ConvertMaskToAlpha (Bitmap bitmap, int r, int g, int b);

	//---------------------------------------------------
	
	void	FlipDisplay (void);

			



}	//namesapce engine

#endif	//GRAPHICS_H