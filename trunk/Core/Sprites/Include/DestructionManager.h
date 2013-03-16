#ifndef DESTRUCTION_MANAGER_H
#define	DESTRUCTION_MANAGER_H

#include <list>
#include "DLLs.h"

#ifdef _WIN32
	#pragma warning (disable:4251)
#endif

namespace engine {
class LatelyDestroyable;

class ENGINE_API DestructionManager {
public:
	///--- class DestructionManager API
	static void Register (LatelyDestroyable* o);
	static void Commit (void);

private:
	///--- class DestructionManager Typedefs
	typedef std::list<LatelyDestroyable*> ObjectList;
	
	///--- private Member Variables
	static ObjectList dead;
};

}	//namespace engine

#endif	//DESTRUCTION_MANAGER_H