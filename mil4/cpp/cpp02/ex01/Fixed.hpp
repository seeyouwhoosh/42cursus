#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					value;
		static const int	fractional = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		Fixed(const int n);
		Fixed(const float n);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);