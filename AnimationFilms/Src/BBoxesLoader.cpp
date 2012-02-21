#include "ConfigFile.h"
#include "BBoxesLoader.h"

namespace engine {

BBoxesLoader::BBoxesLoader (void) : path(""), bboxes() {}

const RectVec BBoxesLoader::Load (const std::string & path_) {
	if (path != path_) {
		path = path_;
		bboxes.clear();
		ConfigFile config;

		if (config.LoadFile(path)) {
			const char * section = config.GetFistSection();
			while (section) {
				if (strlen(section) > 0) {	//skip global section
					bboxes.push_back(
						Rect(
							atoi(config.GetValue(section, "x")),
							atoi(config.GetValue(section, "y")),
							atoi(config.GetValue(section, "w")),
							atoi(config.GetValue(section, "h"))
						)
					);
				}
				section = config.GetNextSection();
			}
		}
	}
	return bboxes;
}

}	//namespace