#include "Point.hpp"

Point::Point(void): x(Fixed()), y(Fixed()) {}

Point::Point(const Fixed x, const Fixed y) : x(x), y(y) {}

Point::Point(Point &other)
{
	*this = other;
}

Point &Point::operator=(Point &other) 
{
	(void)other;
}

Point::~Point() {}

Fixed	Point::dotProd(const Point a, const Point b)
{
	return (Fixed(a.x * b.x + a.y * b.x));
}

Point Point::operator-(Point &other) const
{
	Point	a(this->x - other.x, this->y - other.y);
	return (a);
}