#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include <allegro5/allegro.h>	//to xriazetai h malakia allegro_image.h
#include <allegro5/allegro_image.h>

#include "Graphics.h"



static bool isInitialized			= false;
static ALLEGRO_DISPLAY * display	= (ALLEGRO_DISPLAY *)0;


/////////////////////////////////////////////////////////
////	Defines

#define LOAD_ALLEGRO_COMPONENT(COMPONENT)		\
	if (!COMPONENT()) {							\
		std::cerr	<< "Failed to initialize: " \
					<< #COMPONENT				\
					<< std::endl;				\
		std::abort();							\
	} else

namespace engine {

//---------------------------------------------------

void InitGraphics (void) {
	if (!isInitialized) {
		LOAD_ALLEGRO_COMPONENT(al_init);
		LOAD_ALLEGRO_COMPONENT(al_init_image_addon);
	}

	isInitialized = true;
}

//---------------------------------------------------



ALLEGRO_DISPLAY * Display (int w, int h) {
	//al_set_new_display_flags(ALLEGRO_FULLSCREEN);
	display = al_create_display(w, h);
	return display;
	//todo check display
}

void DestroyDisplay (void) {
	assert (display);
	al_destroy_display(display);
}

void Flip (void) 
	{ al_flip_display(); }


//---------------------------------------------------

Bitmap	LoadBitmap (const std::string& path) { 
	InitGraphics();
	return al_load_bitmap(path.c_str()); 
}

//---------------------------------------------------

void DestroyBitmap (Bitmap b) { 
	assert(b);
	InitGraphics();
	al_destroy_bitmap(b);
	b = (Bitmap)0;
}

//---------------------------------------------------

void MaskedBlit (Bitmap source, Bitmap dest, const Rect & rect, const Point& at) {
	InitGraphics();
	Bitmap b = al_create_sub_bitmap(source, rect.x, rect.y, rect.w, rect.h);
	al_set_target_bitmap(dest);
	al_draw_bitmap(b, at.x, at.y, 0);
	al_set_target_bitmap(al_get_backbuffer(display));
}



}