#include <assert.h>
#include <algorithm>

#include "LatelyDestroyable.h"
#include "DestructionManager.h"

namespace engine {

DestructionManager::ObjectList DestructionManager::dead;

//-----------------------------------------------------------------------

void DestructionManager::Register (LatelyDestroyable* o) {
	assert(!o->IsAlive()); 
	dead.push_back(o); 
} 

//-----------------------------------------------------------------------

void DestructionManager::Commit (void) {
	std::for_each(
		dead.begin(), 
		dead.end(), 
		LatelyDestroyable::Delete()
	); 
	dead.clear();
}

}