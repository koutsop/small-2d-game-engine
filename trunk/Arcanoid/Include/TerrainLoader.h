#ifndef TERRAIN_H
#define TERRAIN_H

#include <string>
#include "Font.h"
#include "Common.h"
#include "Graphics.h"
#include "ConfigFile.h"


class TerrainLoader {
public:
	TerrainLoader() : font(20) {}

	bool					Load (const std::string& path);
	engine::byte			GetNumberOfLevels (void) const;
	int						GetScreenWidth (void) const;
	int						GetScreenHeight (void) const;
	int						GetMaxScore (void) const;
	bool					IsFullScreen (void) const;
	const engine::Rect&		GetTerrainBoundaries (void) const;
	const engine::Point&	GetScorePos (void) const;
	const engine::Point&	GetLifePos (void) const;
	const engine::Point&	GetLevelPos (void) const;
	const engine::Point&	GetInitBallPosition (void) const;
	const engine::Point&	GetInitBoardPosition (void) const;
	const std::string&		GetNextLevel (void);
	const std::string&		GetFilmsPath (void) const;
	const std::string&		GetBallFilmID (void) const;
	const std::string&		GetBrickFilmID (void) const;
	const std::string&		GetBoardFilmID (void) const;
	const std::string&		GetBackgroundImgPath (void) const;
	const std::string&		GetPausedImgPath (void) const;
	const std::string&		GetGameOverImgPath (void) const;

private:
	void					LoadLifes (engine::ConfigFile& config);
	void					LoadLevels (engine::ConfigFile& config);
	void					DisplayScore (engine::ConfigFile& config);
	void					LoadFilmsInfo (engine::ConfigFile& config);
	void					LoadScreenInfo (engine::ConfigFile& config);
	void					LoadTerrainInfo (engine::ConfigFile& config);
	void					LoadPosition (
								engine::ConfigFile& config ,
								const char*			section, 
								engine::Point&		pos
							);

	struct TerrainInfo {
		int				maxScore;
		engine::Rect	bound;
		std::string		bgImg;
		std::string		pauseImg;
		std::string		gameover;
		TerrainInfo (void) : 
			maxScore(0),
			bound	(), 
			bgImg	(""), 
			pauseImg(""),
			gameover("")
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
		std::string boardFilmID;

		FilmsInfo () :
			filmsPath(""), 
			brickFilmID(""), 
			ballFilmID(""), 
			boardFilmID("") 
		{}
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