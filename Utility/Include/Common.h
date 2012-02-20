#ifndef COMMON_H
#define COMMON_H

#include <list>
#include <vector>

namespace engine {


struct Rect;
struct Point;
///////////////////////////////////////////////
// Common typedefs
typedef int					Dim;
typedef unsigned char		byte;
typedef std::vector<Rect>	RectVec;
typedef std::list<Rect>		RectList;

///////////////////////////////////////////////
// Common structs

//----------------------------------------------------------

struct Rect {
	Dim x, y, w, h;

	Rect () : x(0), y(0), w(0), h(0) {}
		
	Rect (Dim x_, Dim y_, Dim w_, Dim h_) :
		x(x_),
		y(y_),
		w(w_),
		h(h_)
	{}

	Dim		GetX (void)
				{ return x; }
	void	SetX (Dim x_)
				{ x = x_; }
	
	Dim		GetY (void)
				{ return y; }
	void	SetY (Dim y_)
				{ y = y_; }

	Dim		GetWidth (void)
				{ return w; }
	void	SetWidth (Dim width)
				{ w = width; }

	Dim		GetHeight (void)
				{ return h; }
	void	SetHeight (Dim height)
				{ h = height; }
};

//----------------------------------------------------------

struct Point {
	Dim x, y;
	Point () : x(0), y(0) {}
	Point (Dim x_, Dim y_) : x(x_), y(y_) {}
	Point (const Point &p) : x(p.x), y(p.y) {}

	Dim		GetX (void)
				{ return x; }
	void	SetX (Dim x_)
				{ x = x_; }
	
	Dim		GetY (void)
				{ return y; }
	void	SetY (Dim y_)
				{ y = y_; }
};


}	//namespace engine

#endif