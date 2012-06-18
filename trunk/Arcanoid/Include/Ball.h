#ifndef BALL_H
#define BALL_H

#include <string>
#include "Board.h"
#include "Brick.h"
#include "Sprite.h"
#include "Common.h"
#include "AnimationFilm.h"


#include <iostream>
class Ball : public engine::Sprite {
public:
	Ball (
		engine::Dim				x_, 
		engine::Dim				y_, 
		engine::AnimationFilm*	film,
		const std::string&		id_,
		const engine::Rect&		terrainBoundaries
	);

	virtual void	Move (engine::Dim x, engine::Dim y);

	void			SetUnstoppable (bool b);
	bool			IsUnstoppable (void) const;
	void			CollideWithBoard (engine::Sprite* s);
	void			CollideWithBrick (engine::Sprite* s);
	void			SetSpeed (engine::byte s);
	engine::byte	GetSpeed (void) const;


private:
	bool			IsGoingUp (void) const;
	bool			IsGoingLeft (void) const;
	void			ReverseHorizon (void);
	void			ReverseVertical (void);
	void			DestroyBrick (Brick *b);
	void			RotateTheBall (Brick *b);
	void			CheckCoordinates(void);

	bool			goingLeft, goingUp, unstoppable;
	engine::byte	speed;
	engine::Rect	boundaries;
};


#endif	//BALL_H