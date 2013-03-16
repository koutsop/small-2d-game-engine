#include "ConfigFile.h"
#include "FilmLoader.h"

namespace engine {

const Film::FilmList FilmLoader::Load (const std::string & path_) {
	if (path != path_) {
		path = path_;
		films.clear();
		ConfigFile config;
	
		if (config.LoadFile(path)) {
			const char * section = config.GetFistSection();
		
			while (section) {
				if (strlen(section) > 0) {	//skip global section
					films.push_back(
						Film(
							config.GetValue(section, "id"),
							config.GetValue(section, "bitmap"),
							config.GetValue(section, "bboxes")
						)
					);
				}
				section = config.GetNextSection();
			}
		}
	}
	return films;
}

}	//namespace