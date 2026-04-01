#include "Point.hpp"

Point::Point(void): x(Fixed()), y(Fixed()) {}

Point::Point(const Fixed x, const Fixed y) : x(x), y(y) {}

Point::Point(const Point &other): x(other.x), y(other.y)
{
	
}

Point &Point::operator=(const Point &other) 
{
	(void)other;
	return (*this);
}

Point::~Point() {}

Fixed	Point::dotProd(const Point a, const Point b)
{
	return (Fixed(a.x * b.x + a.y * b.x));
}

Point Point::operator-(const Point &other) const
{
	Point	a(this->x - other.x, this->y - other.y);
	return (a);
}

const Fixed	&Point::get_x(void) const
{
	return (this->x);
}
const Fixed	&Point::get_y(void) const
{
	return (this->y);
}

std::ostream &operator<<(std::ostream &os, const Point &a)
{
	os << "(" << a.get_x() << "," << a.get_y() << ")";
	return os;
}