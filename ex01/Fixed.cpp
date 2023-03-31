/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidigov <tidigov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:01:41 by tidigov           #+#    #+#             */
/*   Updated: 2023/03/26 09:25:27 by tidigov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout<<"Default constructor called\n";
	this->m_value = 0;
}

Fixed::~Fixed(){
	std::cout<<"Destructor called\n";
}

Fixed::Fixed(Fixed const & src)
{
	std::cout<<"Copy constructor called\n";
	*this = src;
}

Fixed::Fixed(int const n)
{
	std::cout<<"Int constructor called\n";
	this->m_value = n << this->s_Bits;
}

Fixed::Fixed(float const n)
{
	std::cout<<"Float constructor called\n";
	this->m_value = int(roundf(n * (1 << s_Bits)));
}

float Fixed::toFloat( void ) const
{
    return ((float)m_value / (1 << s_Bits));
}

int Fixed::toInt(void) const
{
    return m_value >> s_Bits; 
}

std::ostream &	operator<<(std::ostream &o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

Fixed&	Fixed::operator=(Fixed const & rhs){
	std::cout<<"Copy assignement operator called\n";
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