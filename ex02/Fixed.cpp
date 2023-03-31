/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidigov <tidigov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 06:35:56 by tidigov           #+#    #+#             */
/*   Updated: 2023/03/31 14:42:25 by tidigov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	//std::cout<<"Default constructor called\n";
	this->m_value = 0;
}

Fixed::~Fixed(){
	//std::cout<<"Destructor called\n";
}

Fixed::Fixed(Fixed const & src)
{
	//std::cout<<"Copy constructor called\n";
	*this = src;
}

Fixed::Fixed(int const &nb)
{
	//std::cout<<"int constructor called\n";
	this->m_value = nb << this->s_Bits;
}

Fixed::Fixed(float const &nb)
{
	// std::cout<<"float constructor called\n";
	this->m_value = roundf(nb * (1 << s_Bits));
}
////////////////////////////////////////////////////////////////////////////////
void Fixed::setRawBits(int const raw)
{
    m_value = raw;
}

int Fixed::getRawBits()const
{
    // std::cout << "getRawBits member fonction called" << std::endl;
    return this->m_value;
}

Fixed&	Fixed::operator=(Fixed const & rhs){
	//std::cout<<"Copy assignement operator called\n";
	this->m_value = rhs.getRawBits();
	return *this;
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
////////////////////////////////////////////////////////////////////////////////
bool    Fixed::operator>(Fixed const & rhs)
{
    if (m_value > rhs.m_value)
        return 1;
    else
        return 0;
}

bool    Fixed::operator<(Fixed const & rhs)
{
    if (m_value < rhs.m_value)
        return 1;
    else
        return 0;
}

bool    Fixed::operator>=(Fixed const & rhs)
{
    if (m_value >= rhs.m_value)
        return 1;
    else
        return 0;
}

bool    Fixed::operator<=(Fixed const & rhs)
{
    if (m_value <= rhs.m_value)
        return 1;
    else
        return 0;
}

bool    Fixed::operator==(Fixed const & rhs)
{
    if (m_value == rhs.m_value)
        return 1;
    else
        return 0;
}

bool    Fixed::operator!=(Fixed const & rhs)
{
    if (m_value != rhs.m_value)
        return 1;
    else
        return 0;
}
////////////////////////////////////////////////////////////////////////////////
Fixed   Fixed::operator*(const Fixed & rhs)
{
    Fixed   result;
    result = (this->toFloat() * rhs.toFloat());
    return result;
}

Fixed   Fixed::operator/(const Fixed & rhs)
{
    Fixed   result;
    result.m_value = this->m_value / rhs.m_value;
    return result;
}

Fixed   Fixed::operator+(const Fixed & rhs)
{
    Fixed   result;
    result.m_value = this->m_value + rhs.m_value;
    return result;
}

Fixed   Fixed::operator-(const Fixed & rhs)
{
    Fixed   result;
    result.m_value = this->m_value - rhs.m_value;
    return result;
}
////////////////////////////////////////////////////////////////////////////////
Fixed & Fixed::operator++()
{
    m_value++;
    return *this;
}

Fixed & Fixed::operator--()
{
    m_value--;
    return *this;
}

Fixed   Fixed::operator++(int)
{
    Fixed   result(*this);
    ++*this;
    return(result);
}

Fixed   Fixed::operator--(int)
{
    Fixed   result(*this);
    --*this;
    return(result);
}
////////////////////////////////////////////////////////////////////////////////
Fixed const Fixed::min(Fixed const &nb1, Fixed const &nb2)
{
    if (nb1.getRawBits() < nb2.getRawBits())
        return nb1;
    else
        return nb2;
}

Fixed Fixed::min(Fixed &nb1, Fixed &nb2)
{
    if (nb1.getRawBits() < nb2.getRawBits())
        return nb1;
    else
        return nb2;
}

Fixed const Fixed::max(Fixed const &nb1, Fixed const &nb2)
{
    if (nb1.getRawBits() > nb2.getRawBits())
        return nb1;
    else
        return nb2;
}

Fixed Fixed::max(Fixed &nb1, Fixed &nb2)
{
    if (nb1.getRawBits() > nb2.getRawBits())
        return nb1;
    else
        return nb2;
}
