#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point	seg_ab(b - a);
	Point	seg_bc(c - b);
	Point	seg_ca(a - c);
}
