#if 0
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int BOUNCER_SIZE = 32;
 
int main(int argc, char **argv)
{
   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   ALLEGRO_TIMER *timer = NULL;
   ALLEGRO_BITMAP *bouncer = NULL;
   float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
   float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;
   float bouncer_dx = -4.0, bouncer_dy = 4.0;
   bool redraw = true;
 
   if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }
	al_init_image_addon();
   timer = al_create_timer(1.0 / FPS);
   if(!timer) {
      fprintf(stderr, "failed to create timer!\n");
      return -1;
   }
 
   display = al_create_display(SCREEN_W, SCREEN_H);
   if(!display) {
      fprintf(stderr, "failed to create display!\n");
      al_destroy_timer(timer);
      return -1;
   }

   bouncer = al_create_sub_bitmap(al_load_bitmap(".\\..\\images\\films\\ballsFilm.bmp"), 0, 0, 8, 8);
   //bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);
   if(!bouncer) {
      fprintf(stderr, "failed to create bouncer bitmap!\n");
      al_destroy_display(display);
      al_destroy_timer(timer);
      return -1;
   }
 
   al_set_target_bitmap(bouncer);
 
   al_clear_to_color(al_map_rgb(255, 0, 255));
 
   al_set_target_bitmap(al_get_backbuffer(display));
 
   event_queue = al_create_event_queue();
   if(!event_queue) {
      fprintf(stderr, "failed to create event_queue!\n");
      al_destroy_bitmap(bouncer);
      al_destroy_display(display);
      al_destroy_timer(timer);
      return -1;
   }
 
   al_register_event_source(event_queue, al_get_display_event_source(display));
 
   al_register_event_source(event_queue, al_get_timer_event_source(timer));
 
   al_clear_to_color(al_map_rgb(0,0,0));
 
   al_flip_display();
 
   al_start_timer(timer);
 
   while(1) {
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
      else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
         break;
      }
 
      if(redraw && al_is_event_queue_empty(event_queue)) {
         redraw = false;
 
         al_clear_to_color(al_map_rgb(0,0,0));
 
         al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);
 
         al_flip_display();
      }
   }
 
   al_destroy_bitmap(bouncer);
   al_destroy_timer(timer);
   al_destroy_display(display);
   al_destroy_event_queue(event_queue);
 
   return 0;
}
#endif

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
#include "FPSCalculator.h"
#include <allegro5/allegro_primitives.h>

int Rectangle_X = 0;
int Rectangle_Y = 0;



const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int BOUNCER_SIZE = 32;


using namespace engine;

static bool False (void) { return false; }

int main(int argc, char **argv)
{

	float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_dx = -4.0, bouncer_dy = 4.0;
	bool redraw = true;


	engine::InitialiseGraphics();
	engine::KeyboardInput::Initialise();
	Display(640, 480);
	
	ALLEGRO_TIMER * timer		= al_create_timer(1.0 / 60);
	Bitmap buffer = LoadBitmap (".\\..\\images\\BufferGameScreen.bmp");
	Bitmap bg = LoadBitmap (".\\..\\images\\GameScreen.bmp");
	engine::AnimationFilmHolder a(".\\..\\configsFiles\\films.cfg");
	

	al_start_timer(timer);
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	while(!engine::KeyboardInput::IsKeyActive(engine::KeyboardInput::KEY_ESCAPE)) {
		engine::KeyboardInput::CheckInput();

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
			SetTargetBitmap(buffer);
			DrawBitmap(bg, Point(0, 0));
			SetBufferAsTargetBitmap();


			//Edw zwgrafizoume sto buffer oti 8eloume
			AnimationFilm  ball = a.GetFilm("ballsFilm");
			Bitmap b			= ball.GetBitmap();
			Rect r				= ball.GetFrameBox(0);
			MaskedDraw(b, buffer, r, Point(bouncer_x, bouncer_y));
			//DrawSubBitmap(b, r, Point(bouncer_x, bouncer_y));
			
			//edw zografizoume sthn o8onh auto pou 8eloume
			DrawBitmap(buffer, 0, 0);
			FlipDisplay();
		}
		FPSCalculator::FPS();
	}

	engine::DestroyDisplay();
	DestroyBitmap(bg);
	DestroyBitmap(buffer);
	engine::CleanUpGraphics();
}

