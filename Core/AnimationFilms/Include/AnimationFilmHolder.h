#ifndef ANIMATION_FILM_HOLDER_H
#define ANIMATION_FILM_HOLDER_H

#include <map>
#include <string>
#include "DLLs.h"
#include "FilmLoader.h"
#include "BitmapLoader.h"
#include "AnimationFilm.h"

namespace engine {

class ENGINE_API AnimationFilmHolder {
public:
    AnimationFilmHolder (const std::string & path);			// Decoder constructor.
    ~AnimationFilmHolder();

    const AnimationFilm&	GetFilm (const std::string & id) const;
	AnimationFilm&			GetFilm (const std::string & id);

	
private:	
	typedef FilmLoader::FilmList FilmList;
	typedef std::map<std::string, AnimationFilm*> FilmMap;
    FilmMap			filmMap;
    AnimationFilm*	filmMem; // Ola ta films allocated as array
	BitmapLoader	bitmapLoader;

};

}	//namespace engine

#endif
