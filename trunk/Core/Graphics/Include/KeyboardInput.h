#ifndef KEYBOARD_INPUT_H
#define KEYBOARD_INPUT_H

#include <allegro5/allegro.h>

#include "DLLs.h"

namespace engine {

class ENGINE_API KeyboardInput {
public:
	enum keyCode {
		KEY_A		= ALLEGRO_KEY_A,
		KEY_B		= ALLEGRO_KEY_B,
		KEY_S		= ALLEGRO_KEY_S,
		KEY_W		= ALLEGRO_KEY_X,
		KEY_ESCAPE	= ALLEGRO_KEY_ESCAPE,
		KEY_SPACE	= ALLEGRO_KEY_SPACE,
		KEY_LEFT	= ALLEGRO_KEY_LEFT,
		KEY_RIGHT	= ALLEGRO_KEY_RIGHT,
		KEY_UP		= ALLEGRO_KEY_UP,
		KEY_DOWN	= ALLEGRO_KEY_DOWN,
		KEY_MAX
	};

	static bool IsKeyActive (keyCode key);
	static void CheckInput (void);
	static void Initialise (void);
	static void CleanUp (void);
	

private:
	KeyboardInput (void);
	static bool isInitialised;
	static bool keys[KEY_MAX];

	
};

}	//namespace engine

#endif //KEYBOARD_INPUT_H