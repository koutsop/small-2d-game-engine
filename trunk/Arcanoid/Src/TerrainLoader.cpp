#include <stdlib.h>
#include <assert.h>

#include "Utility.h"
#include "TerrainLoader.h"
#include "BBoxesLoader.h"
#include "BitmapLoader.h"


bool TerrainLoader::Load (const std::string& path) {
	bool result = false;
	engine::ConfigFile config;

	if (config.LoadFile(path)){
		result = true;
		LoadScreenInfo(config);
		LoadTerrainInfo(config);
		LoadFilmsInfo(config);
		LoadPosition(config, "BALL", ballPos);
		LoadPosition(config, "BOARD", boardPos);
		LoadPosition(config, "SCORE", scorePos);
		LoadLifes(config);
		LoadLevels(config);
	}
	return result;
}
	
//-----------------------------------------------------------------------

void TerrainLoader::LoadScreenInfo (engine::ConfigFile& config) {
	screen.w			= atoi(config.GetValue("RESOLUTION", "w"));
	screen.h			= atoi(config.GetValue("RESOLUTION", "h"));
	screen.fullScreen	= engine::StringToBool(config.GetValue("RESOLUTION", "fullScreen"));
}

//-----------------------------------------------------------------------

void TerrainLoader::LoadTerrainInfo (engine::ConfigFile& config) {
	assert(config.IsLoaded());

	terrain.maxScore	= atoi(config.GetValue("TERRAIN", "maxScore"));
	terrain.bound.x		= atoi(config.GetValue("TERRAIN", "x"));
	terrain.bound.y		= atoi(config.GetValue("TERRAIN", "y"));
	terrain.bound.w		= atoi(config.GetValue("TERRAIN", "w"));
	terrain.bound.h		= atoi(config.GetValue("TERRAIN", "h"));
	terrain.bgImg		= config.GetValue("TERRAIN", "bgImg");
	terrain.pauseImg	= config.GetValue("TERRAIN", "pauseImg");
	terrain.gameover	= config.GetValue("TERRAIN", "gameover");
}

//-----------------------------------------------------------------------

void TerrainLoader::LoadFilmsInfo (engine::ConfigFile& config) {
	films.filmsPath		= config.GetValue("FILMS", "path");	
	films.ballFilmID	= config.GetValue("FILMS", "ball");	
	films.brickFilmID	= config.GetValue("FILMS", "brick");	
}

//-----------------------------------------------------------------------

void TerrainLoader::LoadPosition (
		engine::ConfigFile& config ,
		const char*			section, 
		engine::Point&		pos
	) {
	assert(config.IsLoaded());
	pos.x = atoi(config.GetValue(section, "x"));
	pos.y = atoi(config.GetValue(section, "y"));
}

//-----------------------------------------------------------------------

void TerrainLoader::LoadLifes (engine::ConfigFile& config) {
	LoadPosition(config, "LIFE", lifes.pos);
	lifes.lifes	= atoi(config.GetValue("LIFE", "lifes"));
}

//-----------------------------------------------------------------------

void TerrainLoader::LoadLevels (engine::ConfigFile& config) {
	assert(config.IsLoaded());

	//load display pos
	LoadPosition(config, "LEVEL_POS", levels.pos);

	//load paths
	const char * entry = config.GetFistEntry("LEVELS_PATH");
	while (entry) {
		levels.levelsPath.push_back(config.GetValue("LEVELS_PATH", entry));
		entry = config.GetNextEntry();
	}
}

//-----------------------------------------------------------------------

engine::byte TerrainLoader::GetNumberOfLevels (void) const
	{ return levels.crrLevel; }

//-----------------------------------------------------------------------

int TerrainLoader::GetScreenWidth (void) const
	{ return screen.w; }

//-----------------------------------------------------------------------

int TerrainLoader::GetScreenHeight (void) const
	{ return screen.h; }

//-----------------------------------------------------------------------

int TerrainLoader::GetMaxScore (void) const
	{ return terrain.maxScore; }

//-----------------------------------------------------------------------

bool TerrainLoader::IsFullScreen (void) const
	{ return screen.fullScreen; }

//-----------------------------------------------------------------------

const engine::Point& TerrainLoader::GetInitBallPosition (void) const
	{ return ballPos; }

//-----------------------------------------------------------------------

const engine::Point& TerrainLoader::GetInitBoardPosition (void) const
	{ return boardPos; }

//-----------------------------------------------------------------------

const std::string& TerrainLoader::GetNextLevel (void) {
	assert (levels.crrLevel + 1 < levels.levelsPath.size());
	return levels.levelsPath[levels.crrLevel++];
}

//-----------------------------------------------------------------------

const std::string& TerrainLoader::GetFilmsPath (void) const
	{ return films.filmsPath; }

//-----------------------------------------------------------------------

const std::string& TerrainLoader::GetBallFilmID (void) const
	{ return films.ballFilmID; }

//-----------------------------------------------------------------------

const std::string& TerrainLoader::GetBrickFilmID (void) const
	{ return films.brickFilmID; }

//-----------------------------------------------------------------------

const std::string& TerrainLoader::GetBackgroundImgPath (void) const
	{ return terrain.bgImg; }

//-----------------------------------------------------------------------

const std::string& TerrainLoader::GetPausedImgPath (void) const
	{ return terrain.pauseImg; }

//-----------------------------------------------------------------------

const std::string& TerrainLoader::GetGameOverImgPath (void) const
	{ return terrain.gameover; }

//-----------------------------------------------------------------------

const engine::Rect&	TerrainLoader::GetTerrainBoundaries (void) const 
	{ return terrain.bound; }

//-----------------------------------------------------------------------

const engine::Point& TerrainLoader::GetScorePos (void) const
	{ return scorePos; }

//-----------------------------------------------------------------------

const engine::Point& TerrainLoader::GetLifePos (void) const
	{ return lifes.pos; }

//-----------------------------------------------------------------------

const engine::Point& TerrainLoader::GetLevelPos (void) const
	{ return levels.pos; }