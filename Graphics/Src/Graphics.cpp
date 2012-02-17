#include <assert.h>
#include <iostream>
#include <allegro5/allegro.h>	//to xriazetai h malakia allegro_image.h
#include <allegro5/allegro_image.h>

#include "Graphics.h"



static bool isInitialized = false;


/////////////////////////////////////////////////////////
////	Defines

#define LOAD_ALLEGRO_COMPONENT(COMPONENT)		\
	if (!COMPONENT()) {							\
		std::cerr	<< "Failed to initialize: " \
					<< #COMPONENT				\
					<< std::endl;				\
		return false;							\
	} else

namespace engine {

//---------------------------------------------------

bool InitGraphics (void) {
	if (!isInitialized) {
		LOAD_ALLEGRO_COMPONENT(al_init);
		LOAD_ALLEGRO_COMPONENT(al_install_mouse);
		LOAD_ALLEGRO_COMPONENT(al_install_keyboard);
		LOAD_ALLEGRO_COMPONENT(al_install_joystick);
		LOAD_ALLEGRO_COMPONENT(al_init_image_addon);
	}

	return isInitialized = true;
}

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
	assert(!"Does not implemented yet");
}



}