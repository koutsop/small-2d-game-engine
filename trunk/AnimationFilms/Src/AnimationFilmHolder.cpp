#include <assert.h>

#include "BBoxesLoader.h"
#include "BitmapLoader.h"
#include "AnimationFilmHolder.h"

namespace engine {

//---------------------------------------------------

AnimationFilmHolder::AnimationFilmHolder (const std::string & path) {
	//load Film Info
	FilmList films;
	FilmLoader::LoadFilm(path, films);
	assert(films.size() != 0);
	CreateAnimationFilms(films);
}

//---------------------------------------------------

AnimationFilmHolder::~AnimationFilmHolder() { 
	filmMap.clear(); 
	delete[] filmMem; 
}

//---------------------------------------------------

const AnimationFilm& AnimationFilmHolder::GetFilm (const std::string & id) const {
	FilmMap::const_iterator i = filmMap.find(id);
	assert(i != filmMap.end());
	return *i->second;
}

//---------------------------------------------------
//TODO na dw ti 8a kanw me to path me ta bbxoes kai ta bitmaps
void AnimationFilmHolder::CreateAnimationFilms (const FilmList & films) {
	filmMem = new AnimationFilm[films.size()];
	
	int				nextFilmIndex = 0;
	RectVec			bbs;
	BitmapLoader	bitmapLoader;

	for (FilmList::const_iterator film = films.begin(); film != films.end(); ++film) {
		BBoxesLoader::LoadBBodexs(film->GetBBoxesPath(), bbs);
		Bitmap b				= bitmapLoader.Load(film->GetBitmapPath());
		filmMem[nextFilmIndex]	= AnimationFilm(b, bbs, film->GetID());
		filmMap[film->GetID()]	= &filmMem[nextFilmIndex++];
		bbs.clear();
	}
}


}