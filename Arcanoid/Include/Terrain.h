#ifndef TERRAIN_H
#define TERRAIN_H

#include <string>
#include "Font.h"
#include "Common.h"
#include "Graphics.h"
#include "ConfigFile.h"


class Terrain {
public:
	Terrain() : font(20) {}

	bool Load (const std::string& path);
	void Display(engine::Bitmap dest);//einai ereto mporei kaina figei

	engine::byte		GetNumberOfLevels (void) const;
	
	int					GetScreenWidth (void) const;
	int					GetScreenHeight (void) const;
	bool				IsFullScreen (void) const;

	const engine::Point	GetScorePos (void) const;
	const engine::Point GetLifePos (void) const;
	const engine::Point GetLevelPos (void) const;

	const engine::Point	GetInitBallPosition (void) const;
	const engine::Point	GetInitBoardPosition (void) const;
	const std::string&	GetNextLevel (void);
	const std::string&	GetFilmsPath (void) const;
	const std::string&	GetBallFilmID (void) const;
	const std::string&	GetBrickFilmID (void) const;
	const std::string&	GetBackgroundImgPath (void) const;
	const std::string&	GetPausedImgPath (void) const;

private:
	void				DisplayLife (engine::Bitmap dest);
	void				DisplayLevel (engine::Bitmap dest);
	void				DisplayScore (engine::Bitmap dest);

	void				LoadLifes (engine::ConfigFile& config);
	void				LoadLevels (engine::ConfigFile& config);
	void				DisplayScore (engine::ConfigFile& config);
	void				LoadFilmsInfo (engine::ConfigFile& config);
	void				LoadScreenInfo (engine::ConfigFile& config);
	void				LoadTerrainInfo (engine::ConfigFile& config);
	void				LoadPosition (
							engine::ConfigFile& config ,
							const char*			section, 
							engine::Point&		pos
						);

	struct TerrainInfo {
		int w, h, x, y;
		std::string	bgImg;
		std::string	pauseImg;
		TerrainInfo (void) : 
			w(0), 
			h(0), 
			x(0), 
			y(0), 
			bgImg(""), 
			pauseImg("") 
		{}
	};

	struct ScreenInfo {
		int w, h;
		bool fullScreen;
		ScreenInfo (): w(0), h(0), fullScreen(false) {}
	};

	struct FilmsInfo {
		std::string filmsPath;
		std::string brickFilmID;
		std::string ballFilmID;
	};

	struct LevelsInfo {
		engine::Point				pos;
		engine::byte				crrLevel;
		std::vector<std::string>	levelsPath;

		LevelsInfo() : pos(), crrLevel(0), levelsPath() {}
	};

	struct LifesInfo {
		engine::Point	pos;
		engine::byte	lifes;
	};

	
	LifesInfo				lifes;
	FilmsInfo				films;
	LevelsInfo				levels;
	ScreenInfo				screen;
	TerrainInfo				terrain;
	engine::Point			ballPos;
	engine::Point			scorePos;
	engine::Point			boardPos;
	engine::Font			font;
	

	
	//scoore info
	//life info
	//level info
};

#endif //TERRAIN_H