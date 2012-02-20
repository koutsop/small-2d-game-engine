#ifndef LATELY_DESTROOYABLE_H
#define LATELY_DESTROOYABLE_H

#include <assert.h>
#include <functional>
#include "DestructionManager.h"

namespace engine {

class LatelyDestroyable {
public:
	LatelyDestroyable (void) 
		: alive(true), inDestruction(false){}

	LatelyDestroyable(const LatelyDestroyable& src)
		: alive(src.alive), inDestruction(src.inDestruction) {}

	bool IsAlive (void) const;
	void Destroy (void);

protected:
	virtual ~LatelyDestroyable() 
		{ assert(inDestruction); }	//< Lately Destroyable design pattern

private: 
	friend class DestructionManager;
	friend class Delete;

	//--- member variables
	bool alive;
	bool inDestruction;
	
	//----------------------------
	//-- struct LatelyDestroyable::Delete	
	struct Delete : public std::unary_function<LatelyDestroyable*, void>{ 
		void operator()(LatelyDestroyable* o) const; 
	};

};


}	//namespa engine


#endif //LATELY_DESTROOYABLE_H