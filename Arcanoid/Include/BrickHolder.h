#ifndef BRICK_HOLDER_H
#define BRICK_HOLDER_H

#include <map>
#include <string>
#include <utility>
#include <functional>

#include "Brick.h"
#include "Graphics.h"
#include "Animator.h"
#include "Animation.h"
#include "AnimationFilm.h"



class BrickHolder {

public:
	static unsigned int		LoadLevel (engine::AnimationFilm * film, const std::string & path);
	static bool				Cancel (Brick *b);
	static void				Clear (void);
	static BrickList		GetBricks (void);
	static engine::delay_t	GetDelay (void);
	static void				SetDelay (engine::delay_t d);

private:
	typedef std::map<Brick *, engine::Animator *>	Brick2AnimatorMapping;
	
	static engine::delay_t			delay;
	static Brick2AnimatorMapping	bricks;

	struct ClearFunctor : public std::unary_function<std::pair<Brick *, engine::Animator *>, void> {
		void operator() (std::pair<Brick *, engine::Animator *> p);
	};
	
};

#endif	//BRICK_HOLDER_H

