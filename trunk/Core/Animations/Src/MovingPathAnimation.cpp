#include "MovingPathAnimation.h"

namespace engine {

//-----------------------------------------------------------------------

MovingPathAnimation::MovingPathAnimation (const PathEntryList& _path, animid_t id) :
path(_path), Animation(id){}	

//-----------------------------------------------------------------------

const PathEntryList& MovingPathAnimation::GetPath (void) const 
	{ return path; }

//-----------------------------------------------------------------------

void MovingPathAnimation::SetPath (const PathEntryList& p) 
	{ path.clear(); path = p; }

//-----------------------------------------------------------------------

Animation* MovingPathAnimation::Clone (animid_t newId) const
	{ return new MovingPathAnimation(path, newId); }

}