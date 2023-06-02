/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:04:25 by zwong             #+#    #+#             */
/*   Updated: 2023/06/02 14:32:17 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Objective: Create my own Fixed number class for accurate calculation, functions are still limited in ex00
// Fixed copy constructor AND copy assignment operator
int main(void) {
  Fixed a;
  Fixed b(a);
  b.setRawBits(5);
  Fixed c;

  c = b;


  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;
  return 0;
}
