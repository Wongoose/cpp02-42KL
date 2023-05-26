/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:04:27 by zwong             #+#    #+#             */
/*   Updated: 2023/05/26 13:04:36 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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