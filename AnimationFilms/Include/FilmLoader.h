#ifndef FILM_LOADER_H
#define FILM_LOADER_H

#include <list>
#include "Film.h"

namespace engine {

class FilmLoader {
public:
	typedef Film::FilmList	FilmList;
	static void LoadFilm (const std::string & path, FilmList & films);
};

}	//naemspace engine

#endif	//FILM_LOADER_H