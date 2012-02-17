#ifndef BBOXES_LOADER_H
#define BBOXES_LOADER_H

#include <string>
#include "Common.h"
namespace engine {

class BBoxesLoader {
public:
	BBoxesLoader (void);
	const RectVec Load (const std::string & path_);

private:
	RectVec		bboxes;
	std::string path;
	
};

}	//namespace engine

#endif	