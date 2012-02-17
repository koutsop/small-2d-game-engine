#include <stdio.h>
#include <iostream>
#include <string>
#include <tuple>
//#include <allegro5/allegro.h>
//#include <allegro5/allegro_image.h>

#include "Graphics.h"

#include "Film.h"
#include "Common.h"
#include "FilmLoader.h"
#include "BBoxesLoader.h"
#include "BitmapLoader.h"
#include "AnimationFilmHolder.h"
#include "KeyboardInput.h"
#include "MouseInput.h"
#include <allegro5/allegro_primitives.h>

int Rectangle_X = 0;
int Rectangle_Y = 0;



int main(int argc, char **argv)
{
	engine::InitGraphics();
	al_init_primitives_addon();
	al_install_mouse();


	ALLEGRO_DISPLAY *display = al_create_display( 640, 480 );
	engine::KeyboardInput::Initialise();
	engine::MouseInput::Initialise();
	al_hide_mouse_cursor(display);

	//ALLEGRO_MOUSE_STATE mouse_state;
	while(1){
		al_clear_to_color( al_map_rgb( 0, 0, 0) );
		al_draw_rectangle( Rectangle_X, Rectangle_Y, Rectangle_X + 50, Rectangle_Y + 50, al_map_rgb( 255, 210, 0 ), 1.0 );
		al_flip_display();
		//al_get_keyboard_state( &Key_State );
		//al_get_mouse_state(&mouse_state);

		engine::MouseInput::CheckInput();
		engine::KeyboardInput::CheckInput();

		if (engine::MouseInput::HasState(engine::MouseInput::MOUSE_STATE_MOVED_RIGHT) && Rectangle_X + 1 < 640)
			Rectangle_X += 1;
		if (engine::MouseInput::HasState(engine::MouseInput::MOUSE_STATE_MOVED_LEFT) && Rectangle_X - 1 > 0)
			Rectangle_X -= 1;
		
		if (engine::MouseInput::HasState(engine::MouseInput::MOUSE_STATE_MOVED_DOWN) && Rectangle_Y + 1 < 480)
			Rectangle_Y += 1;
		if (engine::MouseInput::HasState(engine::MouseInput::MOUSE_STATE_MOVED_UP) && Rectangle_Y - 1 > 0)
			Rectangle_Y -= 1;

		if (engine::MouseInput::HasState(engine::MouseInput::MOUSE_STATE_KEY_RIGHT) && Rectangle_X + 1 < 640)
			Rectangle_X += 1;
		if (engine::MouseInput::HasState(engine::MouseInput::MOUSE_STATE_KEY_LEFT) && Rectangle_X - 1 > 0)
			Rectangle_X -= 1;
		
	}
	engine::AnimationFilmHolder a(".\\..\\configsFiles\\films.cfg");

	engine::MouseInput::CleanUp();
	engine::KeyboardInput::CleanUp();
	al_destroy_display( display );
	return 0;

}