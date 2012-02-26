#ifndef BALL_H
#define BALL_H

#include <string>
#include "Common.h"
#include "Brick.h"
#include "Sprite.h"
#include "AnimationFilm.h"

class Ball : public engine::Sprite {
public:
	Ball (
		engine::Dim				x, 
		engine::Dim				y, 
		engine::AnimationFilm*	film,
		const std::string&		id_
	);

	void CollideWithBrick (Brick *b);
	virtual void Move (engine::Dim x, engine::Dim y);
};


#endif	//BALL_H