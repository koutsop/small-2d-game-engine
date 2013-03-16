#include <assert.h>
#include <allegro5/allegro.h>	//to xriazetai h malakia allegro_image.h
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>


#include "Graphics.h"
#include "GraphicsCommon.h"



namespace engine {

static bool isInitialized			= false;
static Bitmap* canvas				= (Bitmap*)0;
static ALLEGRO_DISPLAY * display	= (ALLEGRO_DISPLAY *)0;


//-----------------------------------------------------------------------

void InitialiseGraphics (void) {
	if (!isInitialized) {
		CHECK_ALLEGRO_COMPONENT(al_init());
		CHECK_ALLEGRO_COMPONENT(al_init_image_addon());
		canvas	= (Bitmap*)0;
		display	= (ALLEGRO_DISPLAY *)0;
	}

	isInitialized = true;
}

//-----------------------------------------------------------------------

void CleanUpGraphics (void) {
	isInitialized = false;
	al_shutdown_image_addon();
}

//-----------------------------------------------------------------------

void Display (int w, int h, bool fullScreen) {
	if (fullScreen)
		al_set_new_display_flags(ALLEGRO_FULLSCREEN);
	display = al_create_display(w, h);
	CHECK_ALLEGRO_COMPONENT(display);
}

//-----------------------------------------------------------------------

void DestroyDisplay (void) {
	assert(display);
	al_destroy_display(display);
}


//-----------------------------------------------------------------------

void Rest (double seconds) 
	{ al_rest(seconds); }

//-----------------------------------------------------------------------

Bitmap*	LoadBitmapFromFile (const std::string& path) { 
	return al_load_bitmap(path.c_str());
}

//-----------------------------------------------------------------------

void DestroyBitmap (Bitmap* b) { 
	assert(b);
	al_destroy_bitmap(b);
	b = (Bitmap*)0;
}

//-----------------------------------------------------------------------

void DrawBitmap (Bitmap* b, const Point& at) 
	{ DrawBitmap(b, at.x, at.y); }

void DrawBitmap (Bitmap* b, int x, int y) {
	assert (display && b);
	al_draw_bitmap(b, x, y, 0);
}

//-----------------------------------------------------------------------

void DrawSubBitmap (Bitmap* source, const Rect & rect, const Point& at) {
	assert(display);
	al_draw_bitmap_region(source, rect.x, rect.y, rect.w, rect.h, at.x, at.y, 0);
}

//-----------------------------------------------------------------------

void MaskedDraw (Bitmap* source, Bitmap* dest, const Rect & rect, const Point& at) {
	assert(display);
	if (canvas != dest)
		al_set_target_bitmap(dest);
	al_draw_bitmap_region(source, rect.x, rect.y, rect.w, rect.h, at.x, at.y, 0);
	
	if (canvas != dest)
		al_set_target_bitmap(canvas);
}

//-----------------------------------------------------------------------

void SetCanvas (Bitmap* b) {
	assert(b && display);
	canvas = b;
	al_set_target_bitmap(canvas);
}

//-----------------------------------------------------------------------

void SetBufferAsCanvas (void) {
	assert(display);
	al_set_target_bitmap(al_get_backbuffer(display));
}

//-----------------------------------------------------------------------

void ConvertMaskToAlpha (Bitmap* bitmap, int r, int g, int b) {
	assert(display);
	al_convert_mask_to_alpha(bitmap, al_map_rgb(r, g, b));
}

//-----------------------------------------------------------------------

void FlipDisplay (void) { 
	assert(display);
	al_flip_display(); 
}

//-----------------------------------------------------------------------

void HideMouseCursor (void) {
	assert(display);
	al_hide_mouse_cursor (display);
}








}