#include <stdlib.h>
#include <allegro5/allegro.h>

#include "BBoxesLoader.h"

namespace engine {

BBoxesLoader::BBoxesLoader (void) : path(""), bboxes() {}

const RectVec BBoxesLoader::Load (const std::string & path_) {
	if (path != path_) {
		path = path_;
		bboxes.clear();

		ALLEGRO_CONFIG * file = al_load_config_file(path.c_str());
		if (file) {
			ALLEGRO_CONFIG_SECTION * nextSection;
			const char * section = al_get_first_config_section(file, &nextSection);
		
			while (section) {
				if (strlen(section) > 0) {	//skip global section
					bboxes.push_back(
						Rect(
							atoi(al_get_config_value(file, section, "x")),
							atoi(al_get_config_value(file, section, "y")),
							atoi(al_get_config_value(file, section, "w")),
							atoi(al_get_config_value(file, section, "h"))
						)
					);
				}
				section = al_get_next_config_section(&nextSection);
			}
		}
	}
	return bboxes;
}

}	//namespace