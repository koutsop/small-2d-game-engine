#ifndef ARCANOID_H
#define ARCANOID_H

#include <string>

#include "Font.h"
#include "TerrainLoader.h"
#include "Graphics.h"
#include "FPSCalculator.h"
#include "AnimationFilmHolder.h"

class Arcanoid {
public:
	Arcanoid();
	void Start (const std::string& path);

private:
	void CollisionRegister (void);
	bool NotFinished (void);
	void FPS (void);
	void InputManagement (void);
	void SystemLoopDispatching (void);
	void Init (const std::string& path);
	void CleanUp (void);
	void GameLoop (void);
	void DisplayAll (void);
	void DisplayScoreLevelLife (void);	  //DisplayGamestats

	bool						isPaused;
	TerrainLoader				terrain;
	engine::Font				font;
	engine::Bitmap				bg;
	engine::Bitmap				pause;
	engine::Bitmap				gameover;
	engine::FPSCalculator		fps;
	engine::AnimationFilmHolder*films;
	
};


#endif	//ARCANOID_H