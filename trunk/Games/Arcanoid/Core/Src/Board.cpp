#include "Board.h"
#include "KeyboardInput.h"

Board::Board (
	engine::Dim				x_, 
	engine::Dim				y_, 
	engine::AnimationFilm*	film,
	const std::string&		id_,
	const engine::Rect&		terrainBoundaries)
:	engine::Sprite(x_, y_, film, id_),
	stopted(true),
	goingLeft(false)
{}

	


bool Board::IsStoped(void) const
	{ return stopted; }

bool Board::IsGoingLeft (void) const
	{ return !IsStoped() && goingLeft; }

bool Board::IsGoingRight (void) const 
	{ return !IsStoped() && !goingLeft; }

engine::byte Board::GetSpeed (void) const 
	{ return speed; }

void Board::SetSpeed (engine::byte s) 
	{ speed = s; }

void Board::Move (engine::Dim x, engine::Dim y) {
	//oldPosition = GetPosition();

	if (IsKeyPresed())
		SetPosition(CalcNewX(), GetY());
}

bool Board::IsKeyPresed (void) const {
	return	engine::KeyboardInput::IsKeyActive(engine::KeyboardInput::KEY_LEFT) ||
			engine::KeyboardInput::IsKeyActive(engine::KeyboardInput::KEY_RIGHT);
}

engine::Dim Board::CalcNewX (void) const {
	assert(!IsStoped());

	if (IsGoingLeft())          //aristero collision
		return GetX() - speed > boundaries.x ? GetX() - speed : boundaries.x; 
	
	return GetX() + speed + GetWidth() > (boundaries.x + boundaries.w) //de3i collision 
			? (boundaries.x + boundaries.w) - GetWidth() 
			: GetX() + speed;
}

//int Board::GetMouseCoordinates(int dx){
//        int x           = Terrain::coordinates.GetX();
//        int w           = Terrain::width;
//
//        if( dx < x ) { return x; }                                                                      //aristero collision
//        else if ( dx > (x + w) - GetWidth()) { return (x + w) - GetWidth(); } //de3i collision
//        else { return dx; }
//}