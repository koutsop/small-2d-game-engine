#ifndef MOUSE_INPOUT_H
#define MOUSE_INPOUT_H

#include "DLLs.h"

namespace engine {

class ENGINE_API MouseInput {
public:
	enum MouseState {
		MOUSE_STATE_KEY_LEFT	= 1,
		MOUSE_STATE_KEY_RIGHT	= 2,
		MOUSE_STATE_KEY_MIDLE	= 3,
		MOUSE_STATE_MOVED_LEFT	= 4,
		MOUSE_STATE_MOVED_RIGHT	= 5,
		MOUSE_STATE_MOVED_UP	= 6,
		MOUSE_STATE_MOVED_DOWN	= 7,
		MOUSE_STATE_MAX
	};

	static bool HasState (MouseState state);
	static void CheckInput (void);
	static void Initialise (void);
	static void CleanUp (void);

private:
	MouseInput (void);
	static int	old_x;
	static int	old_y;
	static bool isInitialised;
	static bool states[MOUSE_STATE_MAX];

	static void CheckForMovment (void);
};

}	//namespace engine

#endif	//MOUSE_INPOUT_H