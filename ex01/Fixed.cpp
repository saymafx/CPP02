/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidigov <tidigov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:01:41 by tidigov           #+#    #+#             */
/*   Updated: 2023/03/23 20:02:00 by tidigov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Constructor called" << std::endl;
    this->m_value = 0;
}

Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy Constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignement operator called" << std::endl;
    this->m_value = rhs.getRawBits();
    return *this;
}

void Fixed::setRawBits(int const raw)
{
    m_value = raw;
}

int Fixed::getRawBits()const
{
    std::cout << "getRawBits member fonction called" << std::endl;
    return this->m_value;
}