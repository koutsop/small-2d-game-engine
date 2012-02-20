#include "LatelyDestroyable.h"

namespace engine {


//---------------------------------------------------

void LatelyDestroyable::Delete::operator()(LatelyDestroyable* o) const { 
	o->inDestruction = true; 
	delete o; 
	//o = (LatelyDestroyable*)0;
}

//---------------------------------------------------

bool LatelyDestroyable::IsAlive (void) const 
	{ return alive; }

//---------------------------------------------------

void LatelyDestroyable::Destroy (void) { 
	if (alive) {
		alive = false; 
		DestructionManager::Register(this);
	}
}


}