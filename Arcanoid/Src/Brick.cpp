#include <assert.h>
#include "Brick.h"


Brick::Brick (
	engine::Dim				x, 
	engine::Dim				y, 
	engine::AnimationFilm*	film,
	engine::byte			frame,
	int						hits_,
	int						score_,
	bool					unbreakable_,
	const std::string&		id_) 
:	engine::Sprite	(x, y, film, id_),
	hits			(hits_),
	score			(score_),
	unbreakable		(unbreakable_){
	
	assert((unbreakable && hits == -1) || (!unbreakable && hits != -1));
	SetFrame(frame);
}

//---------------------------------------------------

int	Brick::GetScore (void) const
	{ return score; }

//---------------------------------------------------

int	Brick::GetHits (void) const  
	{ return hits; }

//---------------------------------------------------

bool Brick::IsUnbreakable (void) const
{ return unbreakable; }

//---------------------------------------------------

void Brick::Move (engine::Dim x, engine::Dim y) {
	
}