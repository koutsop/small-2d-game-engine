#include <assert.h>
#include <allegro5/allegro_ttf.h>
#include "Font.h"
#include "GraphicsCommon.h"


namespace engine {

bool Font::isInitialized = false;

//-----------------------------------------------------------------------

void Font::Initialise (void) {
	if (!isInitialized) {
		al_init_font_addon();
		CHECK_ALLEGRO_COMPONENT(al_init_ttf_addon());
	}
	isInitialized = true;
}

//-----------------------------------------------------------------------

void Font::CleanUp (void){
	isInitialized = false;
	al_shutdown_ttf_addon();
	al_shutdown_font_addon();
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

void Font::DrawTextOnScreen(const Color& c, float x, float y, TextAlign align, const std::string& text) {
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