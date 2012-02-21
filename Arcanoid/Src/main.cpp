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
#include "Audio.h"
#include "StateHolder.h"
#include <allegro5/allegro_primitives.h>

int Rectangle_X = 0;
int Rectangle_Y = 0;



const float FPS = 120;
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
	engine::Audio::Initialise();
	engine::KeyboardInput::Initialise();
	Display(640, 480);
	
	ALLEGRO_TIMER * timer	= al_create_timer(1.0 / 60);
	Bitmap buffer			= LoadBitmap (".\\..\\images\\BufferGameScreen.bmp");
	Bitmap bg				= LoadBitmap (".\\..\\images\\GameScreen.bmp");
	engine::AnimationFilmHolder a(".\\..\\configsFiles\\films.cfg");

	engine::Audio trac1(".\\..\\1.ogg");
	engine::Audio trac2(".\\..\\2.ogg");

	StateHolder::RegisterState("GoLeft");

	
	engine::Audio::SetReserveNumber(20);
	trac1.Play(PlayModeONCE);
	//trac2.Play(PlayModeONCE);

	al_start_timer(timer);
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	while(!engine::KeyboardInput::IsKeyActive(engine::KeyboardInput::KEY_ESCAPE)) {
		engine::KeyboardInput::CheckInput();
		Clock::SetGameTime();

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
		FPSCalculator::CalcFPS();
		std::cout << "FPS: " << FPSCalculator::GetFPS() << std::endl;
	}

	engine::DestroyDisplay();
	DestroyBitmap(bg);
	DestroyBitmap(buffer);
	engine::CleanUpGraphics();
}

