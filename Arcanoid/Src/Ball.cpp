#include <assert.h>
#include "Ball.h"
#include "BrickHolder.H"
#include "CollisionChecker.h"

Ball::Ball (
	engine::Dim				x_, 
	engine::Dim				y_, 
	engine::AnimationFilm*	film,
	const std::string&		id_,
	const engine::Rect&		terrainBoundaries
) : engine::Sprite	(x_, y_, film, id_),
	goingLeft		(false),
	goingUp			(false),
	unstoppable		(false),
	boundaries		(terrainBoundaries)
{}


//-----------------------------------------------------------------------

void Ball::Move (engine::Dim x, engine::Dim y) {
    CheckCoordinates();
    if (goingLeft)   
		SetPosition(GetPosition().GetX() - GetSpeed(), GetPosition().GetY());
    else                    
		SetPosition(GetPosition().GetX() + GetSpeed(), GetPosition().GetY());

    if (goingUp)             
		SetPosition(GetPosition().GetX(), GetPosition().GetY() - GetSpeed());
    else                    
		SetPosition(GetPosition().GetX(), GetPosition().GetY() + GetSpeed());
}

//-----------------------------------------------------------------------

void Ball::CollideWithBrick (engine::Sprite* s) {
	Brick* b = dynamic_cast<Brick*>(s);
	assert(b);
	
	if (!b->IsUnbreakable()) {
		b->Hit();
		if (!b->GetHits()) 
			DestroyBrick (b);
	}

	if (!IsUnstoppable())
		RotateTheBall (b);
}

//-----------------------------------------------------------------------

void Ball::CollideWithBoard (engine::Sprite* s) {
	Board* b = dynamic_cast<Board*>(s);
	assert(b);

	if (!b->IsStoped())
		goingLeft = b->IsGoingLeft();
    goingUp	= true;
}

//-----------------------------------------------------------------------

void Ball::SetUnstoppable (bool b) 
	{ unstoppable = b; }

bool Ball::IsUnstoppable (void) const 
	{ return unstoppable; }

//-----------------------------------------------------------------------

void Ball::SetSpeed (engine::byte s) 
	{ speed = s; }

//-----------------------------------------------------------------------

engine::byte Ball::GetSpeed (void) const 
	{ return speed; }

//-----------------------------------------------------------------------

bool Ball::IsGoingUp (void) const
	{ return goingUp; }

//-----------------------------------------------------------------------

bool Ball::IsGoingLeft (void) const
	{ return goingLeft; }

//-----------------------------------------------------------------------

void Ball::ReverseHorizon (void)
	{ goingLeft = !goingLeft; }

//-----------------------------------------------------------------------

void Ball::ReverseVertical (void)
	{ goingUp = !goingUp; }

//-----------------------------------------------------------------------

void Ball::DestroyBrick (Brick *b) {
		BrickHolder::Cancel(b);
		engine::CollisionChecker::Cancel(this, b);
		b->GetScore();
		//if (b->HasPower())
		//	b->RelasePower();
}

//-----------------------------------------------------------------------

void Ball::RotateTheBall (Brick *b) {
    int ballX2 = GetX() + GetWidth(), ballY2 = GetY() + GetHeight();
	int brickX2 = b->GetX() + b->GetWidth(), brickY2 = b->GetY() + b->GetHeight();

	//Ball is down, brick is up
    if ( (GetX() >= b->GetX() - GetWidth() || GetX() <= brickX2) && //5???? magic number
		 (GetY()-5 >= brickY2 || GetY()+5 >= brickY2) ){
		if(IsGoingUp()) 
			ReverseVertical();
    } 
	else //Ball is up, brick is down
    if ( (GetX() >= b->GetX()- GetWidth() || GetX() <=brickX2) && 
		 (ballY2-5 <= b->GetY() || ballY2+5 <= b->GetY()) ){
		if(!IsGoingUp())
			ReverseVertical();
    }
	else //Ball is right, brick is left
    if ( (GetY() >= b->GetY() - GetHeight() || GetY() <= brickY2) && 
		 (GetX()-5 >= brickX2 || GetX()+5 >= brickX2)){
		if(IsGoingLeft()) 
			ReverseHorizon();
    } 
	else //Ball is left, brick is right
    if ( (GetY() >= b->GetY() - GetHeight() || GetY() <= brickY2) && 
		 (ballX2-5 <= b->GetX() || ballX2+5 <= b->GetX()) ){
		if (!IsGoingLeft())
			ReverseHorizon();
    }	
}

//-----------------------------------------------------------------------

void Ball::CheckCoordinates(void) {
        int x			= GetPosition().GetX();
        int y           = GetPosition().GetY();
        int terrainX    = boundaries.GetX();
        int terrainY    = boundaries.GetY();
		int terrainW    = boundaries.GetWidth();
		int terrainH    = boundaries.GetHeight();

        if( ((x+GetWidth()) >= (terrainW+terrainX)) && goingUp && !goingLeft ){
                goingUp         = true;                                         //right wall
                goingLeft       = true;
        }
        else 
		if( ((x+GetWidth()) >= (terrainW+terrainX)) && !goingUp && !goingLeft ){
                goingUp         = false;                                        //right wall
                goingLeft       = true;
        }
        else 
		if( (y <= terrainY) && goingUp && goingLeft ){
                goingUp         = false;                                        //up wall
                goingLeft       = true;
        }
        else 
		if( (y <= terrainY) && goingUp && !goingLeft ){
                goingUp         = false;                                        //up wall
                goingLeft       = false;
        } /* asdasdsd */
        else 
		if( (x <= terrainX) && !goingUp && goingLeft ){
                goingUp         = false;                                        //left wall
                goingLeft       = false;
        }
        else 
		if( (x <= terrainX) && goingUp && goingLeft ){
                goingUp         = true;                                         //left wall
                goingLeft       = false;
        }
        else 
		if( (y+GetHeight()) >= (terrainH+terrainY) ){
                //GameStats::LifeLost();
                goingUp         = true;                                         //bottom wall
        }
}
