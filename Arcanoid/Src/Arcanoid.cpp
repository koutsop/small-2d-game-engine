#include <iostream>
#include <assert.h>
#include <functional>

#include "Clock.h"
#include "Common.h"
#include "Arcanoid.h"
#include "Utility.h"
#include "BrickHolder.h"
#include "SpriteHolder.h"
#include "KeyboardInput.h"
#include "AnimationFilm.h"
#include "FPSCalculator.h"
#include "MovingAnimator.h"
#include "AnimatorManager.h"
#include "MovingAnimation.h"
#include "CollisionChecker.h"
#include "DestructionManager.h"


Arcanoid::Arcanoid () 
:	isPaused(false),
	terrain (),
	font	(20),
	bg		((engine::Bitmap*)0),
	pause	((engine::Bitmap*)0),
	gameover((engine::Bitmap*)0),
	fps		(),
	films	((engine::AnimationFilmHolder*)0)
{}

void Arcanoid::Start(const std::string& path) {
	Init(path);
	CollisionRegister();
	GameLoop();
	CleanUp();
}


//-----------------------------------------------------------------------

void Arcanoid::GameLoop (void) {
	while (NotFinished()) {
		engine::Clock::SetGameTime();
		DisplayAll();
		InputManagement();
		engine::AnimatorManager::Progress(engine::Clock::GetGameTime());
		//AnimationProgress();
		//ArtificialIntelligence()
		engine::CollisionChecker::Check();
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

	CreateTheBall();
	CreateTheBoard();
}

//-----------------------------------------------------------------------

void Arcanoid::CreateTheBall (void) {
	ball = new Ball (
				terrain.GetInitBallPosition().x,
				terrain.GetInitBallPosition().y,
				&films->GetFilm(terrain.GetBallFilmID()),
				"ball",
				terrain.GetTerrainBoundaries()
			);
	engine::SpriteHolder::Register(ball);

	engine::MovingAnimation * animation		= new engine::MovingAnimation(0, 0, 20, true, 0);
	engine::MovingAnimator * ballAnimator	= new engine::MovingAnimator();
	ballAnimator->Start(ball, animation, 0);
	engine::AnimatorManager::Register(ballAnimator);
	engine::AnimatorManager::MarkAsRunning(ballAnimator);
}

//-----------------------------------------------------------------------

void Arcanoid::CreateTheBoard (void) {
	board = new Board (
				terrain.GetInitBoardPosition().x,
				terrain.GetInitBoardPosition().y,
				&films->GetFilm(terrain.GetBoardFilmID()),
				"board",
				terrain.GetTerrainBoundaries()
			);
	engine::SpriteHolder::Register(board);
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
		engine::string_cast(99999999)
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
		engine::SpriteHolder::Display();
		DisplayScoreLevelLife();
	}
	else
		engine::DrawBitmap(gameover, engine::Point(0, 0));

	engine::FlipDisplay();
}

//-----------------------------------------------------------------------

void Arcanoid::CollisionRegister (void) {
	engine::CollisionChecker::Register(
		ball,
		board,
		std::bind(&Ball::CollideWithBoard, ball, std::placeholders::_1)
	);

	BrickList bricks = BrickHolder::GetBricks();
	for (BrickList::iterator i = bricks.begin(); i != bricks.end(); ++i)
		engine::CollisionChecker::Register(
			ball,
			*i,
			std::bind(&Ball::CollideWithBrick, ball, std::placeholders::_1)
		);
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