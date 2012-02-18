#include <iostream>
#include <allegro5/allegro.h>

#include "FilmLoader.h"

namespace engine {

const Film::FilmList FilmLoader::Load (const std::string & path_) {
	if (path != path_) {
		path = path_;
		films.clear();
	
		ALLEGRO_CONFIG * file = al_load_config_file(path.c_str());
		if (file) {
			ALLEGRO_CONFIG_SECTION * nextSection;
			const char * section = al_get_first_config_section(file, &nextSection);
		
			while (section) {
				if (strlen(section) > 0) {	//skip global section
					films.push_back(
						Film(
							al_get_config_value(file, section, "id"),
							al_get_config_value(file, section, "bitmap"),
							al_get_config_value(file, section, "bboxes")
						)
					);
				}
				section = al_get_next_config_section(&nextSection);
			}
		}
	}
	return films;
}

}	//namespace