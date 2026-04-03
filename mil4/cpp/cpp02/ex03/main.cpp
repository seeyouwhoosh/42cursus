#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main(void)
{
	const Point	a(0, 0);
	const Point	b(3, 0);
	const Point	c(0, 4);

	Point	point1(-1, -1);
	std::cout << "Point " << point1 << " not in the triangle: " << bsp(a, b, c, point1) << "\n";

	Point	point2(0, 0);
	std::cout << "Point " << point2 << " not in the triangle: " << bsp(a, b, c, point2) << "\n";

	Point	point3(0, 3);
	std::cout << "Point " << point3 << " not in the triangle: " << bsp(a, b, c, point3) << "\n";

	Point	point4(3, 3);
	std::cout << "Point " << point4 << " not in the triangle: " << bsp(a, b, c, point4) << "\n";

	Point	point5(1, 1);
	std::cout << "Point " << point5 << " in the triangle: " << bsp(a, b, c, point5) << "\n";
	
	Point	point6(2, 1);
	std::cout << "Point " << point6 << " in the triangle: " << bsp(a, b, c, point6) << "\n";

	Point	point7(2.9f, 0.1f);
	std::cout << "Point " << point7 << " in the triangle: " << bsp(a, b, c, point7) << "\n";

	return 0;
}
