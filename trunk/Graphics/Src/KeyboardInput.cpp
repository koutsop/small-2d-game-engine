#include <assert.h>
#include "KeyboardInput.h"
#include "GraphicsCommon.h"

namespace engine {

bool KeyboardInput::isInitialised = false;
bool KeyboardInput::keys[KEY_MAX];


//---------------------------------------------------

bool KeyboardInput::IsKeyActive (keyCode key) {
	assert(key >= KEY_A && key < KEY_MAX);
	return keys[key];
}

//---------------------------------------------------

void KeyboardInput::CheckInput (void) {
	Initialise();

	ALLEGRO_KEYBOARD_STATE  ret_state;
	al_get_keyboard_state(&ret_state);

	for (int key = KEY_A; key != KEY_MAX; ++key)
		keys[key] = al_key_down(&ret_state, key);
}

//---------------------------------------------------

void KeyboardInput::Initialise (void) {
	if (!isInitialised) {
		if (!al_is_keyboard_installed())
			CHECK_ALLEGRO_COMPONENT(al_install_keyboard());

		for (int key = KEY_A; key != KEY_MAX; ++key)
			keys[key] = false;

		isInitialised = true;
	}
}

//---------------------------------------------------

void KeyboardInput::CleanUp (void) {
	if (al_is_keyboard_installed())
		al_uninstall_keyboard();
	isInitialised = false;
}

}