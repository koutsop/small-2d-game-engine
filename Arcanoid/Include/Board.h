#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "Common.h"
#include "Sprite.h"
#include "AnimationFilm.h"


class Board : public engine::Sprite  {
public:
	Ball (
		engine::Dim				x, 
		engine::Dim				y, 
		engine::AnimationFilm*	film,
		const std::string&		id_
	);

	engine::byte	GetSpeed (void) const;
	void			SetSpedd (engine::byte s);
	virtual void	Move (engine::Dim x, engine::Dim y);

private:
	engine::byte player;
	engine::byte speed;
};


#endif	//BOARD_H