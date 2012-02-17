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
#include <allegro5/allegro_primitives.h>

int Rectangle_X = 0;
int Rectangle_Y = 0;



int main(int argc, char **argv)
{
	engine::InitGraphics();
	al_init_primitives_addon();


	ALLEGRO_DISPLAY *display = al_create_display( 640, 480 );
	engine::KeyboardInput::Initialise();


	while(1){
		al_clear_to_color( al_map_rgb( 0, 0, 0) );
		al_draw_rectangle( Rectangle_X, Rectangle_Y, Rectangle_X + 50, Rectangle_Y + 50, al_map_rgb( 255, 210, 0 ), 1.0 );
		al_flip_display();
		//al_get_keyboard_state( &Key_State );
		
		engine::KeyboardInput::CheckInput();
		if (engine::KeyboardInput::IsKeyActive(engine::KeyboardInput::KEY_A))
			Rectangle_X += 1;
		if (engine::KeyboardInput::IsKeyActive(engine::KeyboardInput::KEY_B))
			Rectangle_X -= 1;
		

	}
	engine::AnimationFilmHolder a(".\\..\\configsFiles\\films.cfg");

	engine::KeyboardInput::CleanUp();
	al_destroy_display( display );
	return 0;

}