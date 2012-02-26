#include <assert.h>
#include <allegro5/allegro_ttf.h>
#include "Font.h"


namespace engine {

//-----------------------------------------------------------------------

Font::Font (int size) : font ((ALLEGRO_FONT*)0) {
	font = al_load_ttf_font(
				"./../../Graphics/Fonts/AirmoleAntique.ttf", 
				size, 
				ALLEGRO_TTF_NO_KERNING
			);
	assert(font);
}

//-----------------------------------------------------------------------

Font::Font (const std::string & path, int size, bool isTff) : font ((ALLEGRO_FONT*)0) {
	if (isTff)
		font = al_load_ttf_font(path.c_str(), size, ALLEGRO_TTF_NO_KERNING);
	else
		font = al_load_font(path.c_str(), size, 0);
	assert(font);
}
	
//-----------------------------------------------------------------------

Font::~Font () 
	{ al_destroy_font(font); }

//-----------------------------------------------------------------------

void Font::DrawText(const Color& c, float x, float y, TextAlign align, const std::string& text) {
	al_draw_text(
		font,
		al_map_rgba(c.red, c.green, c.blue, c.alpha),
		x,
		y, 
		align, 
		text.c_str()
	);
}

}	//namespace engine