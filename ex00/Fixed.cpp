/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:04:22 by zwong             #+#    #+#             */
/*   Updated: 2023/05/26 13:04:36 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : raw_value_(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Default destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	this->raw_value_ = fixed.getRawBits();
}

void Fixed::swap(Fixed &first, Fixed &second) {
	std::swap(first.raw_value_, second.raw_value_);
}

Fixed &Fixed::operator=(Fixed fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	swap(*this, fixed);
	return (*this);
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->raw_value_);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->raw_value_ = raw;
}
