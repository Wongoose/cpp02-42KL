#ifndef FIXED_H
#define FIXED_H

#include <cmath>
#include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		~Fixed();
		Fixed(const Fixed &fixed);

		// Overload operators
		Fixed &operator=(Fixed fixed);
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
		Fixed operator+=(const Fixed &rhs);
		Fixed operator-=(const Fixed &rhs);
		Fixed operator*=(const Fixed &rhs);
		Fixed operator/=(const Fixed &rhs);

		static Fixed &min(Fixed &f1, Fixed &f2);
		static const Fixed &min(const Fixed &f1, const Fixed &f2);
		static Fixed &max(Fixed &f1, Fixed &f2);
		static const Fixed &max(const Fixed &f1, const Fixed &f2);

		void swap(Fixed &first, Fixed &second);
		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;

	private:
		int raw_value_;
		static const int fractional_bits_ = 8;

};

// OVERLOADED functions - C++ allows to specify more than one function of the same name
// Different result or use depending on the types and number of arguments
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

bool operator==(const Fixed &lhs, const Fixed &rhs);
bool operator!=(const Fixed &lhs, const Fixed &rhs);
bool operator<(const Fixed &lhs, const Fixed &rhs);
bool operator>(const Fixed &lhs, const Fixed &rhs);
bool operator<=(const Fixed &lhs, const Fixed &rhs);
bool operator>=(const Fixed &lhs, const Fixed &rhs);

Fixed operator+(Fixed lhs, const Fixed &rhs);
Fixed operator-(Fixed lhs, const Fixed &rhs);
Fixed operator*(Fixed lhs, const Fixed &rhs);
Fixed operator/(Fixed lhs, const Fixed &rhs);

#endif