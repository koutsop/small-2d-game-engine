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



const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int BOUNCER_SIZE = 32;


using namespace engine;

int main(int argc, char **argv)
{
	//engine::InitGraphics();
	//al_init_primitives_addon();
	//al_install_mouse();


	//ALLEGRO_DISPLAY *display = al_create_display( 640, 480 );
	//engine::KeyboardInput::Initialise();
	//engine::MouseInput::Initialise();
	//al_hide_mouse_cursor(display);

	////ALLEGRO_MOUSE_STATE mouse_state;
	//while(1){
	//	al_clear_to_color( al_map_rgb( 0, 0, 0) );
	//	al_draw_rectangle( Rectangle_X, Rectangle_Y, Rectangle_X + 50, Rectangle_Y + 50, al_map_rgb( 255, 210, 0 ), 1.0 );
	//	al_flip_display();
	//	//al_get_keyboard_state( &Key_State );
	//	//al_get_mouse_state(&mouse_state);

	//	engine::MouseInput::CheckInput();
	//	engine::KeyboardInput::CheckInput();

	//	if (engine::MouseInput::HasState(engine::MouseInput::MOUSE_STATE_MOVED_RIGHT) && Rectangle_X + 1 < 640)
	//		Rectangle_X += 1;
	//	if (engine::MouseInput::HasState(engine::MouseInput::MOUSE_STATE_MOVED_LEFT) && Rectangle_X - 1 > 0)
	//		Rectangle_X -= 1;
	//	
	//	if (engine::MouseInput::HasState(engine::MouseInput::MOUSE_STATE_MOVED_DOWN) && Rectangle_Y + 1 < 480)
	//		Rectangle_Y += 1;
	//	if (engine::MouseInput::HasState(engine::MouseInput::MOUSE_STATE_MOVED_UP) && Rectangle_Y - 1 > 0)
	//		Rectangle_Y -= 1;

	//	if (engine::MouseInput::HasState(engine::MouseInput::MOUSE_STATE_KEY_RIGHT) && Rectangle_X + 1 < 640)
	//		Rectangle_X += 1;
	//	if (engine::MouseInput::HasState(engine::MouseInput::MOUSE_STATE_KEY_LEFT) && Rectangle_X - 1 > 0)
	//		Rectangle_X -= 1;
	//	
	//}
	//engine::AnimationFilmHolder a(".\\..\\configsFiles\\films.cfg");

	//engine::MouseInput::CleanUp();
	//engine::KeyboardInput::CleanUp();
	//al_destroy_display( display );
	//return 0;


	float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_dx = -4.0, bouncer_dy = 4.0;
	bool redraw = true;


	engine::InitGraphics();
	ALLEGRO_DISPLAY * display = Display(640, 480);
	//ALLEGRO_DISPLAY * display	= al_create_display(640, 480);
	ALLEGRO_TIMER * timer		= al_create_timer(1.0 / 60);
	

	Bitmap buffer = LoadBitmap (".\\..\\images\\BufferGameScreen.bmp");
	Bitmap bg = LoadBitmap (".\\..\\images\\GameScreen.bmp");
	engine::AnimationFilmHolder a(".\\..\\configsFiles\\films.cfg");
	AnimationFilm  ball = a.GetFilm("ballsFilm");

	al_start_timer(timer);
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	while(1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if(ev.type == ALLEGRO_EVENT_TIMER) {
			if(bouncer_x < 0 || bouncer_x > SCREEN_W - BOUNCER_SIZE) {
			bouncer_dx = -bouncer_dx;
			}
 
			if(bouncer_y < 0 || bouncer_y > SCREEN_H - BOUNCER_SIZE) {
			bouncer_dy = -bouncer_dy;
			}
 
			bouncer_x += bouncer_dx;
			bouncer_y += bouncer_dy;
 
			redraw = true;
		}

		if(redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
 
			//Edw ka8arizoume to buffer bitmap pou exoume
			al_set_target_bitmap(buffer);
			al_draw_bitmap(bg, 0, 0, 0);
			al_set_target_bitmap(al_get_backbuffer(display));


			//Edw zwgrafizoume sto buffer oti 8eloume
			//to bitmap exei problhma tou animation ???
			Bitmap b	= ball.GetBitmap();//LoadBitmap (".\\..\\images\\films\\ballsFilm.bmp");//
			Rect r		= ball.GetFrameBox(0);
			MaskedBlit(b, buffer, r, Point(bouncer_x, bouncer_y));
			
			//edw zografizoume sthn o8onh auto pou 8eloume
			al_draw_bitmap(buffer, 0, 0, 0);
			al_flip_display();
		}
	}

	//engine::DestroyDisplay();
	DestroyBitmap(bg);
	//DestroyBitmap(buffer);

}