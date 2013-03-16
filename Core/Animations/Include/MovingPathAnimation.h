#ifndef MOVING_PATH_ANIMATION_H
#define MOVING_PATH_ANIMATION_H

#include <list>
#include "Animation.h"

namespace engine {

struct ENGINE_API PathEntry {
    offset_t 	dx, dy;
    frame_t 	frame;
    delay_t		delay;
    PathEntry (void) : dx(0), dy(0), frame(0xff), delay(0){}
    PathEntry (const PathEntry& p) :
		dx(p.dx), dy(p.dy), frame(p.frame),delay(p.delay){}
};

typedef std::list<PathEntry> PathEntryList;

class ENGINE_API MovingPathAnimation : public Animation {
public:
    MovingPathAnimation (const PathEntryList& _path, animid_t id);

    const PathEntryList&	GetPath (void) const;
    void					SetPath (const PathEntryList& p);
	Animation*				Clone (animid_t newId) const;

protected:
	virtual					~MovingPathAnimation() {} 			//LatelyDestroyable design pattern

private:
	PathEntryList			path;
};

}	//namespace engine

#endif	//MOVING_PATH_ANIMATION_H