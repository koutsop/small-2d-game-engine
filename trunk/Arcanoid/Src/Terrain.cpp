#include <stdlib.h>
#include <assert.h>
#include "Utility.h"
#include "Terrain.h"
#include "BBoxesLoader.h"
#include "BitmapLoader.h"


bool Terrain::Load (const std::string& path) {
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

void Terrain::Display(engine::Bitmap dest) {
	font.DrawTextW(
		engine::Color(255, 255, 255), 
		lifes.pos.x, 
		lifes.pos.y, 
		engine::Font::TextAlignLEFT, 
		engine::string_cast<int>(lifes.lifes)
	);

	font.DrawTextW(
		engine::Color(255, 255, 255), 
		scorePos.x, 
		scorePos.y, 
		engine::Font::TextAlignLEFT, 
		engine::string_cast(1453)
	);

	font.DrawTextW(
		engine::Color(255, 255, 255), 
		levels.pos.x, 
		levels.pos.y, 
		engine::Font::TextAlignLEFT, 
		engine::string_cast<int>(levels.crrLevel)
	);
}
	
//-----------------------------------------------------------------------

void Terrain::LoadScreenInfo (engine::ConfigFile& config) {
	screen.w			= atoi(config.GetValue("RESOLUTION", "w"));
	screen.h			= atoi(config.GetValue("RESOLUTION", "h"));
	screen.fullScreen	= engine::StringToBool(config.GetValue("RESOLUTION", "fullScreen"));
}

//-----------------------------------------------------------------------

void Terrain::LoadTerrainInfo (engine::ConfigFile& config) {
	assert(config.IsLoaded());

	terrain.x			= atoi(config.GetValue("TERRAIN", "x"));
	terrain.y			= atoi(config.GetValue("TERRAIN", "y"));
	terrain.w			= atoi(config.GetValue("TERRAIN", "w"));
	terrain.h			= atoi(config.GetValue("TERRAIN", "h"));
	terrain.bgImg		= config.GetValue("TERRAIN", "bgImg");
	terrain.pauseImg	= config.GetValue("TERRAIN", "pauseImg");
}

//-----------------------------------------------------------------------

void Terrain::LoadFilmsInfo (engine::ConfigFile& config) {
	films.filmsPath		= config.GetValue("FILMS", "path");	
	films.ballFilmID	= config.GetValue("FILMS", "ball");	
	films.brickFilmID	= config.GetValue("FILMS", "brick");	
}

//-----------------------------------------------------------------------

void Terrain::LoadPosition (
		engine::ConfigFile& config ,
		const char*			section, 
		engine::Point&		pos
	) {
	assert(config.IsLoaded());
	pos.x = atoi(config.GetValue(section, "x"));
	pos.y = atoi(config.GetValue(section, "y"));
}

//-----------------------------------------------------------------------

void Terrain::LoadLifes (engine::ConfigFile& config) {
	LoadPosition(config, "LIFE", lifes.pos);
	lifes.lifes	= atoi(config.GetValue("LIFE", "lifes"));
}

//-----------------------------------------------------------------------

void Terrain::LoadLevels (engine::ConfigFile& config) {
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

engine::byte Terrain::GetNumberOfLevels (void) const
	{ return levels.crrLevel; }

//-----------------------------------------------------------------------

int Terrain::GetScreenWidth (void) const
	{ return screen.w; }

//-----------------------------------------------------------------------

int Terrain::GetScreenHeight (void) const
	{ return screen.h; }

//-----------------------------------------------------------------------

bool Terrain::IsFullScreen (void) const
	{ return screen.fullScreen; }

//-----------------------------------------------------------------------

const engine::Point Terrain::GetInitBallPosition (void) const
	{ return ballPos; }

//-----------------------------------------------------------------------

const engine::Point	Terrain::GetInitBoardPosition (void) const
	{ return boardPos; }

//-----------------------------------------------------------------------

const std::string& Terrain::GetNextLevel (void) {
	assert (levels.crrLevel + 1 < levels.levelsPath.size());
	return levels.levelsPath[levels.crrLevel++];
}

//-----------------------------------------------------------------------

const std::string& Terrain::GetFilmsPath (void) const
	{ return films.filmsPath; }

//-----------------------------------------------------------------------

const std::string& Terrain::GetBallFilmID (void) const
	{ return films.ballFilmID; }

//-----------------------------------------------------------------------

const std::string& Terrain::GetBrickFilmID (void) const
	{ return films.brickFilmID; }

//-----------------------------------------------------------------------

const std::string& Terrain::GetBackgroundImgPath (void) const
	{ return terrain.bgImg; }

//-----------------------------------------------------------------------

const std::string& Terrain::GetPausedImgPath (void) const
	{ return terrain.pauseImg; }

