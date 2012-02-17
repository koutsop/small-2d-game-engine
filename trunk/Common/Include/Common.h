#ifndef COMMON_H
#define COMMON_H

#include <list>
#include <vector>

namespace engine {


///////////////////////////////////////////////
// Common structs

//----------------------------------------------------------

struct Rect {
	int x, y, w, h;

	Rect () : x(0), y(0), w(0), h(0) {}
		
	Rect (int x_, int y_, int w_, int h_) :
		x(x_),
		y(y_),
		w(w_),
		h(h_)
	{}

	int		GetX (void)
				{ return x; }
	void	SetX (int x_)
				{ x = x_; }
	
	int		GetY (void)
				{ return y; }
	void	SetY (int y_)
				{ y = y_; }

	int		GetWidth (void)
				{ return w; }
	void	SetWidth (int width)
				{ w = width; }

	int		GetHeight (void)
				{ return h; }
	void	SetHeight (int height)
				{ h = height; }
};

//----------------------------------------------------------

struct Point {
	int x, y;
	Point () : x(0), y(0) {}
	Point (const Point &p) : x(p.x), y(p.y) {}

	int		GetX (void)
				{ return x; }
	void	SetX (int x_)
				{ x = x_; }
	
	int		GetY (void)
				{ return y; }
	void	SetY (int y_)
				{ y = y_; }
};


///////////////////////////////////////////////
// Common typedefs
typedef std::vector<Rect>	RectVec;
typedef std::list<Rect>		RectList;




}	//namespace engine

#endif