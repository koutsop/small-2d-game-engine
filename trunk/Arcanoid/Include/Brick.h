#ifndef BRICK_H
#define BRICK_H

#include <list>
#include <string>
#include "Common.h"
#include "Sprite.h"
#include "AnimationFilm.h"

class Brick;
typedef std::list<Brick *> BrickList;

class Brick : public engine::Sprite {
public:
	Brick (
		engine::Dim				x, 
		engine::Dim				y, 
		engine::AnimationFilm*	film,
		engine::byte			frame,
		int						hits_,
		int						score_,
		bool					unbreakable_,
		const std::string&		id_
	);

	int				GetScore (void) const;
	void			Hit (void);
	int				GetHits (void) const; //-1 if is Unbreakable
	bool			IsUnbreakable (void) const;
	virtual void	Move (engine::Dim x, engine::Dim y);

protected:
	virtual ~Brick() {}		//LatelyDestroyable design pattern

private:
	int				score;
	int				hits;
	bool			unbreakable;
};


#endif	//BRICK_H