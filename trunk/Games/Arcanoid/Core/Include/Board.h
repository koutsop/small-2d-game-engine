#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "Common.h"
#include "Sprite.h"
#include "AnimationFilm.h"


class Board : public engine::Sprite  {
public:
	Board (
		engine::Dim				x_, 
		engine::Dim				y_, 
		engine::AnimationFilm*	film,
		const std::string&		id_,
		const engine::Rect&		terrainBoundaries
	);

	bool			IsStoped(void) const;
	bool			IsGoingLeft (void) const;
	bool			IsGoingRight (void) const;
	engine::byte	GetSpeed (void) const;
	void			SetSpeed (engine::byte s);
	virtual void	Move (engine::Dim x, engine::Dim y);

private:
	engine::Dim		CalcNewX (void) const;
	bool			IsKeyPresed (void) const;
	

	bool			stopted;
	bool			goingLeft;
	engine::Rect	boundaries;
	engine::byte	speed;
};


#endif	//BOARD_H