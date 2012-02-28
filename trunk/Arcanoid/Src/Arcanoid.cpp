#include <iostream>
#include <assert.h>

#include "Clock.h"
#include "Common.h"
#include "Arcanoid.h"
#include "Utility.h"
#include "BrickHolder.h"
#include "SpriteHolder.h"
#include "KeyboardInput.h"
#include "AnimationFilm.h"
#include "FPSCalculator.h"
#include "CollisionChecker.h"
#include "DestructionManager.h"


Arcanoid::Arcanoid () 
:	isPaused(false),
	terrain (),
	font	(20),
	bg		((engine::Bitmap)0),
	pause	((engine::Bitmap)0),
	gameover((engine::Bitmap)0),
	fps		(),
	films	((engine::AnimationFilmHolder*)0)
{}

void Arcanoid::Start(const std::string& path) {
	Init(path);
	//collision Register
	GameLoop();
	CleanUp();
}


//-----------------------------------------------------------------------

void Arcanoid::GameLoop (void) {
	while (NotFinished()) {
		engine::Clock::SetGameTime();
		DisplayAll();
		InputManagement();
		//AnimationProgress();
		//ArtificialIntelligence()
		//engine::CollisionChecker::Check();
		FPS();
		//SystemLoopDispatching();
	}
}

//-----------------------------------------------------------------------

void Arcanoid::Init (const std::string& path) {
	terrain.Load(path);

	engine::Display(
		terrain.GetScreenWidth(), 
		terrain.GetScreenHeight(), 
		terrain.IsFullScreen()
	);

	bg			= engine::LoadBitmap(terrain.GetBackgroundImgPath());
	pause		= engine::LoadBitmap(terrain.GetPausedImgPath());
	gameover	= engine::LoadBitmap(terrain.GetGameOverImgPath());

	//assert(bg && buffer && pause && gameover);
	films		= new engine::AnimationFilmHolder(terrain.GetFilmsPath());
	BrickHolder::LoadLevel(&films->GetFilm(terrain.GetBrickFilmID()), terrain.GetNextLevel());
}

//-----------------------------------------------------------------------

void Arcanoid::CleanUp (void) {
	delete films;
	//engine::SpriteHolder::Clear();
	//engine::AnimatorManager::Clear();
	//engine::DestructionManager::Commit();
	//engine::DestroyDisplay();
	//engine::DestroyBitmap(bg);
	//engine::DestroyBitmap(buffer);
}

//-----------------------------------------------------------------------

void Arcanoid::DisplayScoreLevelLife (void) {
	font.DrawText(
		engine::Color(255, 255, 255), 
		terrain.GetLifePos().x, 
		terrain.GetLifePos().y, 
		engine::Font::TextAlignLEFT, 
		engine::string_cast<int>(4)
	);

	font.DrawText(
		engine::Color(255, 255, 255), 
		terrain.GetScorePos().x, 
		terrain.GetScorePos().y, 
		engine::Font::TextAlignLEFT, 
		engine::string_cast(1453)
	);

	font.DrawText(
		engine::Color(255, 255, 255), 
		terrain.GetLevelPos().x, 
		terrain.GetLevelPos().y, 
		engine::Font::TextAlignLEFT, 
		engine::string_cast<int>(1)
	);
}

void Arcanoid::DisplayAll (void) {
	if (!isPaused) {
		engine::DrawBitmap(bg, engine::Point(0, 0));

		//Draw Sprites and stats
		for (int i = 0; i < 200; ++i)
			engine::SpriteHolder::Display();
		//DisplayScoreLevelLife();
	}
	else
		engine::DrawBitmap(gameover, engine::Point(0, 0));

	engine::FlipDisplay();
}

//-----------------------------------------------------------------------

void Arcanoid::CollisionRegister (void) {
	//engine::CollisionChecker::Register();
}

//-----------------------------------------------------------------------

void Arcanoid::FPS (void) {
	fps.CalcFPS();
	
	if (fps.GetFPS() > 0)
		std::cout << "FPS: " << fps.GetFPS() << std::endl;
}

//-----------------------------------------------------------------------

bool Arcanoid::NotFinished (void) {
	return !engine::KeyboardInput::IsKeyActive(engine::KeyboardInput::KEY_ESCAPE);
}

//-----------------------------------------------------------------------

void Arcanoid::InputManagement (void) {
	engine::KeyboardInput::CheckInput();
}

//-----------------------------------------------------------------------

void Arcanoid::SystemLoopDispatching (void) {
	engine::DestructionManager::Commit();
}