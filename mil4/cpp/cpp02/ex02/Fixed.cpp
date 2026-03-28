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


Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	this->value = other.value;
	return (*this);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->value > other.value);
}
bool Fixed::operator<(const Fixed &other) const
{
	return (this->value < other.value);
}
bool Fixed::operator>=(const Fixed &other) const
{
	return (this->value >= other.value);
}
bool Fixed::operator<=(const Fixed &other) const
{
	return (this->value <= other.value);
}
bool Fixed::operator==(const Fixed &other) const
{
	return (other.value == this->value);
}
bool Fixed::operator!=(const Fixed &other) const
{
	return (other.value != this->value);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed	a;
	a.value = this->value + other.value;
	return (a);
}
Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed	a;
	a.value = this->value - other.value;
	return (a);
}
Fixed Fixed::operator*(const Fixed &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}
Fixed Fixed::operator/(const Fixed &other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed	&Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	a = *this;
	
	++(*this);
	return (a);
}

Fixed	&Fixed::operator--()
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	a = *this;
	
	--(*this);
	return (a);
}

Fixed		&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

Fixed		&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
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