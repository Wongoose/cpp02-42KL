/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:04:31 by zwong             #+#    #+#             */
/*   Updated: 2023/06/02 14:41:11 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : raw_value_(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) {
	std::cout << "Int constructor called" << std::endl;
	this->raw_value_ = i << fractional_bits_;
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	this->raw_value_ = roundf(f * (1 << this->fractional_bits_));
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

// UNDERSTAND assignment operator logic
Fixed &Fixed::operator=(Fixed fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	swap(*this, fixed);
	return (*this);
}

// Pre-increment
Fixed &Fixed::operator++() {
	this->raw_value_++;
	return (*this);
}

// Post-increment
Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

// Pre-increment
Fixed &Fixed::operator--() {
	this->raw_value_--;
	return (*this);
}

// Post-increment
Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

Fixed Fixed::operator+=(const Fixed &rhs) {
	this->raw_value_ = this->raw_value_ + rhs.raw_value_;
	return (*this);
}

Fixed Fixed::operator-=(const Fixed &rhs) {
	this->raw_value_ = this->raw_value_ - rhs.raw_value_;
	return (*this);
}

Fixed Fixed::operator*=(const Fixed &rhs) {
	this->raw_value_ = ((long long)this->raw_value_ * rhs.getRawBits()) >> fractional_bits_;
	return (*this);
}

Fixed Fixed::operator/=(const Fixed &rhs) {
	this->raw_value_ = ((long long)this->raw_value_ << fractional_bits_) / rhs.getRawBits();
	return (*this);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
	return (f1 < f2 ? f1 : f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
	return (f1 < f2 ? f1 : f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
	return (f1 > f2 ? f1 : f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
	return (f1 > f2 ? f1 : f2);
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->raw_value_);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->raw_value_ = raw;
}

// UNDERSTAND the conversion logic
float Fixed::toFloat(void) const {
	return ((float)this->raw_value_ / (1 << this->fractional_bits_));
}

int Fixed::toInt(void) const {
	return (this->raw_value_ >> fractional_bits_);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}

bool operator==(const Fixed &lhs, const Fixed &rhs) {
	return (lhs.getRawBits() == rhs.getRawBits() ? true : false);
}

bool operator!=(const Fixed &lhs, const Fixed &rhs) {
	return (lhs.getRawBits() != rhs.getRawBits() ? true : false);
}

bool operator<(const Fixed &lhs, const Fixed &rhs) {
	return (lhs.getRawBits() < rhs.getRawBits() ? true : false);
}

bool operator>(const Fixed &lhs, const Fixed &rhs) {
	return (lhs.getRawBits() > rhs.getRawBits() ? true : false);
}

bool operator<=(const Fixed &lhs, const Fixed &rhs) {
	return (lhs.getRawBits() <= rhs.getRawBits() ? true : false);
}

bool operator>=(const Fixed &lhs, const Fixed &rhs) {
	return (lhs.getRawBits() >= rhs.getRawBits() ? true : false);
}

Fixed operator+(Fixed lhs, const Fixed &rhs) {
	lhs += rhs;
	return (lhs);
}

Fixed operator-(Fixed lhs, const Fixed &rhs) {
	lhs -= rhs;
	return (lhs);
}

Fixed operator*(Fixed lhs, const Fixed &rhs) {
	lhs *= rhs;
	return (lhs);
}

Fixed operator/(Fixed lhs, const Fixed &rhs) {
	lhs /= rhs;
	return (lhs);
}
