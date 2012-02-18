#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include <allegro5/allegro.h>	//to xriazetai h malakia allegro_image.h
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>


#include "Graphics.h"



static bool isInitialized			= false;
static ALLEGRO_DISPLAY * display	= (ALLEGRO_DISPLAY *)0;


/////////////////////////////////////////////////////////
////	Defines

#define CHECK_ALLEGRO_COMPONENT(COMPONENT)		\
	if (!COMPONENT) {							\
		std::cerr	<< "Failed to initialize: " \
					<< #COMPONENT				\
					<< std::endl;				\
		std::abort();							\
	} else

namespace engine {

//---------------------------------------------------

void InitialiseGraphics (void) {
	if (!isInitialized) {
		CHECK_ALLEGRO_COMPONENT(al_init());
		al_init_font_addon();
		CHECK_ALLEGRO_COMPONENT(al_init_ttf_addon());
		CHECK_ALLEGRO_COMPONENT(al_init_image_addon());
	}

	isInitialized = true;
}

//---------------------------------------------------

void CleanUpGraphics (void) {
	al_shutdown_ttf_addon();
	al_shutdown_font_addon();
	al_shutdown_image_addon();
}

//---------------------------------------------------

void Display (int w, int h) {
	al_set_new_display_flags(ALLEGRO_FULLSCREEN);
	display = al_create_display(w, h);
	CHECK_ALLEGRO_COMPONENT(display);
}

//---------------------------------------------------

void DestroyDisplay (void) {
	assert(display);
	al_destroy_display(display);
}

//---------------------------------------------------

Bitmap	LoadBitmap (const std::string& path) { 
	assert(display);
	return al_load_bitmap(path.c_str()); 
}

//---------------------------------------------------

void DestroyBitmap (Bitmap b) { 
	assert(b && display);
	al_destroy_bitmap(b);
	b = (Bitmap)0;
}

//---------------------------------------------------

void DrawBitmap (Bitmap b, const Point& at) 
	{ DrawBitmap(b, at.x, at.y); }

void DrawBitmap (Bitmap b, int x, int y) {
	assert (display && b);
	al_draw_bitmap(b, x, y, 0);
}

//---------------------------------------------------

void DrawSubBitmap (Bitmap source, const Rect & rect, const Point& at) {
	assert(display);
	al_draw_bitmap_region(source, rect.x, rect.y, rect.w, rect.h, at.x, at.y, 0);
}

//---------------------------------------------------

void MaskedDraw (Bitmap source, Bitmap dest, const Rect & rect, const Point& at) {
	assert(display);
	al_set_target_bitmap(dest);
	al_draw_bitmap_region(source, rect.x, rect.y, rect.w, rect.h, at.x, at.y, 0);
	al_set_target_bitmap(al_get_backbuffer(display));
}

//---------------------------------------------------

void SetTargetBitmap (Bitmap b) {
	assert(b && display);
	al_set_target_bitmap(b);
}

//---------------------------------------------------

void SetBufferAsTargetBitmap (void) {
	assert(display);
	al_set_target_bitmap(al_get_backbuffer(display));
}

//---------------------------------------------------

void ConvertMaskToAlpha (Bitmap bitmap, int r, int g, int b) {
	assert(display);
	al_convert_mask_to_alpha(bitmap, al_map_rgb(r, g, b));
}

//---------------------------------------------------

void FlipDisplay (void) { 
	assert(display);
	al_flip_display(); 
}








}