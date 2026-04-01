#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	const Point	seg_ab(b - a);
	const Point	seg_bc(c - b);
	const Point	seg_ca(a - c);
 
	const Point	seg_point_a(point - a);
	const Point	seg_point_b(point - b);
	const Point	seg_point_c(point - c);


	return (Point::crossProd(seg_point_a, seg_ab) * Point::crossProd(seg_point_b, seg_bc) > 0 &&  Point::crossProd(seg_point_c, seg_ca) * Point::crossProd(seg_point_b, seg_bc) > 0);
}
