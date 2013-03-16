#ifndef FONT_H
#define FONT_H

#include <string>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

#include "DLLs.h"
#include "Common.h"

namespace engine {

class ENGINE_API Font {
public:
	enum TextAlign {
		TextAlignLEFT	= ALLEGRO_ALIGN_LEFT,
		TextAlignCENTRE	= ALLEGRO_ALIGN_CENTRE,
		TextAlignRIGHT	= ALLEGRO_ALIGN_RIGHT
	};

	Font (const std::string & path, int size, bool isTff = true);
	~Font ();
	///We can not use the name DrawText. It is reserved from widns :S
	void		DrawTextOnScreen(const Color& c, float x, float y, TextAlign align, const std::string& text);
	static void Initialise (void);
	static void CleanUp (void);

private:
	ALLEGRO_FONT*	font;
	static bool		isInitialized;
};


}	//namespace engine

#endif //FONT_H