#pragma once
# include "Fixed.hpp"

class Point
{
private:
	const Fixed	x;
	const Fixed	y;
public:
	Point(void);
	Point(const Fixed x, const Fixed y);
	Point(Point &other);
	Point &operator=(Point &other);
	Point operator-(Point &other) const;
	~Point();

	Fixed	dotProd(const Point a, const Point b);
};

