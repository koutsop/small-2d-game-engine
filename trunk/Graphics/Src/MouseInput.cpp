#include <allegro5/allegro.h>

#include "MouseInput.h"
#include "GraphicsCommon.h"

namespace engine {

int	MouseInput::old_x;
int	MouseInput::old_y;
bool MouseInput::isInitialised;
bool MouseInput::states[MOUSE_STATE_MAX];

//-----------------------------------------------------------------------

bool MouseInput::HasState (MouseState state) {
	assert(state >= MOUSE_STATE_KEY_LEFT && state < MOUSE_STATE_MAX);
	return states[state];
}

//-----------------------------------------------------------------------

void MouseInput::CheckInput (void) {
	Initialise();
	ALLEGRO_MOUSE_STATE  ret_state;
	al_get_mouse_state(&ret_state);

	//Check mouse buttons state
	states[MOUSE_STATE_KEY_LEFT]	= al_mouse_button_down(&ret_state, MOUSE_STATE_KEY_LEFT);
	states[MOUSE_STATE_KEY_RIGHT]	= al_mouse_button_down(&ret_state, MOUSE_STATE_KEY_RIGHT);
	states[MOUSE_STATE_KEY_MIDLE]	= al_mouse_button_down(&ret_state, MOUSE_STATE_KEY_MIDLE);

	CheckForMovment();
}

//-----------------------------------------------------------------------

void MouseInput::Initialise (void) {
	if (!isInitialised) {
		if (!al_is_mouse_installed())
			CHECK_ALLEGRO_COMPONENT(al_is_mouse_installed());
		
		for (int key = MOUSE_STATE_KEY_LEFT; key < MOUSE_STATE_KEY_MIDLE; ++key)
			states[key] = false;
		al_get_mouse_cursor_position(&old_x, &old_y);
		isInitialised = true;	
	}
}

//-----------------------------------------------------------------------

void MouseInput::CleanUp (void) {
	if (al_is_mouse_installed())
		al_uninstall_mouse();
	isInitialised = false;
}	

//-----------------------------------------------------------------------

void MouseInput::CheckForMovment (void) {
	int x, y;
	al_get_mouse_cursor_position(&x, &y);

	states[MOUSE_STATE_MOVED_LEFT]	= x < old_x;
	states[MOUSE_STATE_MOVED_RIGHT] = x > old_x;
	states[MOUSE_STATE_MOVED_UP]	= y < old_y;
	states[MOUSE_STATE_MOVED_DOWN]	= y > old_y;
}

}