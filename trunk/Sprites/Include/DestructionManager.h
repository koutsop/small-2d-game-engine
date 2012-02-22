#ifndef DESTRUCTION_MANAGER_H
#define	DESTRUCTION_MANAGER_H

#include <list>

namespace engine {
class LatelyDestroyable;

class DestructionManager {
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