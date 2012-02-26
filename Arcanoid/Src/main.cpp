#include <stdio.h>
#include <iostream>
#include <string>
#include <tuple>
#include <vld.h>
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
#include "Font.h"
#include "BrickHolder.h"
#include "SpriteHolder.h"
#include "DestructionManager.h"
#include "AnimatorManager.h"
#include "Terrain.h"
#include <allegro5/allegro_primitives.h>

int Rectangle_X = 0;
int Rectangle_Y = 0;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int BOUNCER_SIZE = 4;


using namespace engine;


int main(int argc, char **argv)
{

	float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_dx = -4.0, bouncer_dy = 4.0;

	engine::InitialiseGraphics();
	engine::Audio::Initialise();
	engine::KeyboardInput::Initialise();

	Terrain terrain;
	terrain.Load(".\\..\\configsFiles\\game.cfg");

	Display(terrain.GetScreenWidth(), terrain.GetScreenHeight(), terrain.IsFullScreen());
	

	Bitmap buffer			= LoadBitmap (terrain.GetBackgroundImgPath());
	Bitmap bg				= LoadBitmap (terrain.GetBackgroundImgPath());
	engine::AnimationFilmHolder a(terrain.GetFilmsPath());
	BrickHolder::LoadLevel(&a.GetFilm(terrain.GetBrickFilmID()), terrain.GetNextLevel());


	while(!engine::KeyboardInput::IsKeyActive(engine::KeyboardInput::KEY_ESCAPE)) {
		Clock::SetGameTime();
		engine::KeyboardInput::CheckInput();
		


		if(bouncer_x < 0 || bouncer_x > SCREEN_W - BOUNCER_SIZE) {
			bouncer_dx = -bouncer_dx;
		}
 
		if(bouncer_y < 0 || bouncer_y > SCREEN_H - BOUNCER_SIZE) {
			bouncer_dy = -bouncer_dy;
		}
 
		bouncer_x += bouncer_dx;
		bouncer_y += bouncer_dy;
 
		SetCanvas(buffer);
		DrawBitmap(bg, Point(0, 0));

		//Edw zwgrafizoume sto buffer oti 8eloume
		AnimationFilm  ball = a.GetFilm(terrain.GetBallFilmID());
		MaskedDraw(ball.GetBitmap(), buffer, ball.GetFrameBox(0), Point(bouncer_x, bouncer_y));
		SpriteHolder::Display(buffer);
		terrain.Display(buffer);

		//edw zografizoume sthn o8onh auto pou 8eloume
		SetBufferAsCanvas();
		DrawBitmap(buffer, 0, 0);
		FlipDisplay();
		
		FPSCalculator::CalcFPS();
		std::cout << "FPS: " << FPSCalculator::GetFPS() << std::endl;
	}

	


	SpriteHolder::Clear();
	AnimatorManager::Clear();
	DestructionManager::Commit();



	engine::DestroyDisplay();
	DestroyBitmap(bg);
	DestroyBitmap(buffer);
	
	//engine::CleanUpGraphics();
}

