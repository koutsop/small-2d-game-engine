#ifndef FILM_LOADER_H
#define FILM_LOADER_H

#include <list>
#include "Film.h"

namespace engine {

class FilmLoader {
public:
	typedef Film::FilmList	FilmList;
	const FilmList Load (const std::string & path);

private:
	FilmList	films;
	std::string path;
};

}	//naemspace engine

#endif	//FILM_LOADER_H