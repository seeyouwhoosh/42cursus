#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";
	this->value = 0;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called\n";
	this->value = n << this->fractional;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called\n";
	this->value = (int)roundf(f * (float)(1 << this->fractional));
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	this->value = other.value;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->value);
}
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	this->value = raw;
}

float	Fixed::toFloat(void) const
{
	float	x;

	x = (float)(this->value - ((this->value >> this->fractional) << this->fractional)) / (float)(1 << this->fractional);
	x += (float)(this->value >> this->fractional);
	return (x);
}

int		Fixed::toInt(void) const
{
	return (this->value >> this->fractional);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}