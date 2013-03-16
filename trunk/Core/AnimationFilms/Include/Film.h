#ifndef	FILM_H
#define	FILM_H

#include <list>
#include <string>
#include "DLLs.h"

#ifdef _WIN32
	#pragma warning (disable:4251)
#endif

namespace engine {

class ENGINE_API Film {
public:
	typedef std::list<Film> FilmList;

	const std::string & GetID (void) const
							{ return id; }
	const std::string & GetBitmapPath (void) const
							{ return bitmapPath; }
	const std::string & GetBBoxesPath (void) const
							{ return bbxoesPath; }
	Film (const std::string & id_, const std::string & bitmapPath_, const std::string & bboxesPath_);

private:
	std::string id;
	std::string bitmapPath;
	std::string bbxoesPath;
};

}	//namespace engine

#endif	//FILM_H