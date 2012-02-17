#ifndef BBOXES_LOADER_H
#define BBOXES_LOADER_H

#include <string>
#include "Common.h"
namespace engine {

class BBoxesLoader {
public:
	static void LoadBBodexs (const std::string & path, RectVec & bboxes);
};

}	//namespace engine

#endif	