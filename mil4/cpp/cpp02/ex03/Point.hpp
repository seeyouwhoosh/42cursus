#pragma once
# include "Fixed.hpp"
# include <iostream>

class Point
{
private:
	const Fixed	x;
	const Fixed	y;
public:
	Point(void);
	Point(const Fixed x, const Fixed y);
	Point(const Point &other);
	Point &operator=(const Point &other);
	Point operator-(const Point &other) const;
	~Point();
	
	static Fixed	dotProd(const Point a, const Point b);
	const Fixed		&get_x() const;
	const Fixed		&get_y() const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

std::ostream &operator<<(std::ostream &os, const Point &a);