#ifndef BBOXES_LOADER_H
#define BBOXES_LOADER_H

#include <string>
#include "DLLs.h"
#include "Common.h"

#ifdef _WIN32
	#pragma warning (disable:4251)
#endif

namespace engine {

class ENGINE_API BBoxesLoader {
public:
	BBoxesLoader (void);
	const RectVec Load (const std::string & path_);

private:
	RectVec		bboxes;
	std::string path;
	
};

}	//namespace engine

#endif	