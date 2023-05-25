#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		~Fixed();
		Fixed(const Fixed &fixed);
		Fixed &operator=(Fixed fixed);

		void swap(Fixed &first, Fixed &second);
		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;

	private:
		int raw_value_;
		static const int fractional_bits_ = 8;

};

// OVERLOAD operation
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif