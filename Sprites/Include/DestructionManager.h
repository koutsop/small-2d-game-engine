#ifndef DESTRUCTION_MANAGER_H
#define	DESTRUCTION_MANAGER_H

#include <list>

namespace engine {
class LatelyDestroyable;

class DestructionManager {
public:
	static void Register (LatelyDestroyable* o);
	static void Commit (void);

private:
	//--- private Member Variables
	typedef std::list<LatelyDestroyable*> ObjectList;
	
	static ObjectList dead;
};

}	//namespace engine

#endif	//DESTRUCTION_MANAGER_H