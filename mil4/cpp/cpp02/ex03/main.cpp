#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void )
{
	const Point	a(Fixed(0), Fixed(0));
	const Point	b(Fixed(3), Fixed(0));
	const Point	c(Fixed(0), Fixed(4));

	Point	point1(Fixed(-1), Fixed(-1));

	std::cout << "Point " << point1 << " not in the triangle: " << bsp(a, b, c, point1) << "\n";

	Point	point2(Fixed(0), Fixed(0));
	std::cout << "Point " << point2 << " not in the triangle: " << bsp(a, b, c, point2) << "\n";

	Point	point3(Fixed(0), Fixed(3));
	std::cout << "Point " << point3 << " not in the triangle: " << bsp(a, b, c, point3) << "\n";

	Point	point4(Fixed(3), Fixed(3));
	std::cout << "Point " << point4 << " not in the triangle: " << bsp(a, b, c, point4) << "\n";

	Point	point5(Fixed(1), Fixed(1));
	std::cout << "Point " << point5 << " in the triangle: " << bsp(a, b, c, point5) << "\n";
	
	Point	point6(Fixed(2), Fixed(1));
	std::cout << "Point " << point6 << " in the triangle: " << bsp(a, b, c, point6) << "\n";

	Point	point7(Fixed(2.9f), Fixed(0.1f));
	std::cout << "Point " << point7 << " in the triangle: " << bsp(a, b, c, point7) << "\n";

	return 0;
}
