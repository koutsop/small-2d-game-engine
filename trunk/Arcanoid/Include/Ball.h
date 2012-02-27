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
		const std::string&		id_,
		const engine::Rect&		terrainBoundaries
	);

	void			CollideWithBrick (Brick *b);
	void			IncreaseSpeed (void);
	void			DecreaseSpeed (void);
	virtual void	Move (engine::Dim x, engine::Dim y);

private:
	engine::byte	speed;
	engine::Rect	bound;
};


#endif	//BALL_H