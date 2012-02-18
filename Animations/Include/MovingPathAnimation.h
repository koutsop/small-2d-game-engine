#ifndef MOVING_PATH_ANIMATION_H
#define MOVING_PATH_ANIMATION_H

#include <list>
#include "Animation.h"

namespace engine {

struct PathEntry {
    offset_t 	dx, dy;
    frame_t 	frame;
    delay_t		delay;
    PathEntry (void) : dx(0), dy(0), frame(0xff), delay(0){}
    PathEntry (const PathEntry& p) :
		dx(p.dx), dy(p.dy), frame(p.frame),delay(p.delay){}
};


class MovingPathAnimation : public Animation {
public:
	typedef std::list<PathEntry> PathEntryList;

    const PathEntryList&	GetPath (void) const 
								{ return path; }
    void					SetPath (const PathEntryList& p) 
								{ path.clear(); path = p; }
    
	Animation*				Clone (animid_t newId) const
								{ return new MovingPathAnimation(path, newId); }

    MovingPathAnimation (const PathEntryList& _path, animid_t id) :
	path(_path), Animation(id){}

private:
	std::list<PathEntry> path;
};

}	//namespace engine

#endif	//MOVING_PATH_ANIMATION_H