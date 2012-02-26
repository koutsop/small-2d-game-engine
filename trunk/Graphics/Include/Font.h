#ifndef FONT_H
#define FONT_H

#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

#include "Common.h"

namespace engine {

class Font {
public:
	enum TextAlign {
		TextAlignLEFT	= ALLEGRO_ALIGN_LEFT,
		TextAlignCENTRE	= ALLEGRO_ALIGN_CENTRE,
		TextAlignRIGHT	= ALLEGRO_ALIGN_RIGHT
	};

	Font (int size);	//default tff font
	Font (const std::string & path, int size, bool isTff = true);
	~Font ();

	void DrawText(const Color& c, float x, float y, TextAlign align, const std::string& text);

private:
	ALLEGRO_FONT* font;
};


}	//namespace engine

#endif //FONT_H