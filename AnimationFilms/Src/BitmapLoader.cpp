#include <assert.h>
#include "BitmapLoader.h"

namespace engine {

//---------------------------------------------------

BitmapLoader::~BitmapLoader() { 
	for (BitmapMap::iterator i = bitmaps.begin(); i != bitmaps.end(); ++i) {
		DestroyBitmap(i->second);
		i->second = (Bitmap)0;
	}
	
	bitmaps.clear();
}

//---------------------------------------------------

Bitmap BitmapLoader::Load (const std::string& path) {
	Bitmap b = GetBitmap(path);
	if (!b) {
		bitmaps[path] = (b = LoadBitmap(path));
		assert(b);
	}
	return b;
}

//---------------------------------------------------

Bitmap BitmapLoader::GetBitmap (const std::string path) const {
	BitmapMap::const_iterator i = bitmaps.find(path);
	return i != bitmaps.end() ? i->second : (Bitmap) 0;
}

}	//namespace engine