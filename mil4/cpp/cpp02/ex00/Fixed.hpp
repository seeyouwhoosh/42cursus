#pragma once
#include <iostream>

class Fixed
{
	private:
		int					value;
		static const int	fractional = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();

		int	getRawBits(void) const;
		void setRawBits(int const raw);
};
