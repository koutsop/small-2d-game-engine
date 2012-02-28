#ifndef BITMAP_LOADER_H
#define BITMAP_LOADER_H

#include <map>
#include <string>
#include "Graphics.h"


namespace engine {

class BitmapLoader {
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
