#include <assert.h>

#include "BBoxesLoader.h"
#include "AnimationFilmHolder.h"

namespace engine {

//-----------------------------------------------------------------------

AnimationFilmHolder::AnimationFilmHolder (const std::string & path) : filmMap(), bitmapLoader() {
	int				nextFilmIndex = 0;
	FilmLoader		filmLoader;
	BBoxesLoader	bbLoader;
	FilmList		films = filmLoader.Load(path);

	assert(films.size() != 0);
	filmMem = new AnimationFilm[films.size()];

	for (FilmList::const_iterator film = films.begin(); film != films.end(); ++film) {
		filmMem[nextFilmIndex]	= AnimationFilm(
									bitmapLoader.Load(film->GetBitmapPath()), 
									bbLoader.Load(film->GetBBoxesPath()), 
									film->GetID()
								  );
		filmMap[film->GetID()]	= &filmMem[nextFilmIndex++];
	}
}

//-----------------------------------------------------------------------

AnimationFilmHolder::~AnimationFilmHolder() { 
	filmMap.clear(); 
	delete[] filmMem; 
}

//-----------------------------------------------------------------------

const AnimationFilm& AnimationFilmHolder::GetFilm (const std::string & id) const {
	FilmMap::const_iterator i = filmMap.find(id);
	assert(i != filmMap.end());
	return *i->second;
}


//-----------------------------------------------------------------------

AnimationFilm& AnimationFilmHolder::GetFilm (const std::string & id){
	FilmMap::iterator i = filmMap.find(id);
	assert(i != filmMap.end());
	return *i->second;
}
}