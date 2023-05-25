#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &fixed);
		Fixed &operator=(Fixed fixed);

		void swap(Fixed &first, Fixed &second);
		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int raw_value_;
		static const int fractional_bits_ = 8;

};


#endif