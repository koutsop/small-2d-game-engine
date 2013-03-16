#ifndef BITMAP_LOADER_H
#define BITMAP_LOADER_H

#include <map>
#include <string>
#include "DLLs.h"
#include "Graphics.h"

#ifdef _WIN32
	#pragma warning (disable:4251)
#endif

namespace engine {

class ENGINE_API BitmapLoader {
public:
    BitmapLoader (void){}
	~BitmapLoader();

	Bitmap* Load (const std::string& path);


private:
    typedef std::map<std::string, Bitmap*> BitmapMap;
    BitmapMap bitmaps;

    Bitmap*	GetBitmap (const std::string path) const;
};


}
#endif
