#ifndef	ANIMATION_H
#define	ANIMATION_H

#include <list>

namespace engine {

typedef signed char			offset_t;
typedef unsigned short		delay_t;
typedef unsigned short		animid_t;
typedef unsigned char		frame_t;
typedef std::list<frame_t>	Frame_tList;


class Animation  {
public:
	Animation (animid_t _id) : id(_id){}
	virtual ~Animation(){}

	animid_t			GetId (void) { return id; }
	virtual Animation*	Clone (animid_t newId) const = 0;

private:
	animid_t id;
};
	
}

#endif	//ANIMATION_H