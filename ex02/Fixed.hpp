/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidigov <tidigov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 06:35:52 by tidigov           #+#    #+#             */
/*   Updated: 2023/03/31 13:08:36 by tidigov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int m_value;
    static const int s_Bits = 8;

public:
    Fixed();
	Fixed(Fixed const &src);
    Fixed(int const &nb);
    Fixed(float const &nb);
	~Fixed();

    Fixed & operator=(Fixed const & rhs);
    bool    operator>(Fixed const & rhs);
    bool    operator<(Fixed const & rhs);
    bool    operator>=(Fixed const & rhs);
    bool    operator<=(Fixed const & rhs);
    bool    operator==(Fixed const & rhs);
    bool    operator!=(Fixed const & rhs);

    
    
    Fixed   operator+(Fixed const & rhs);
    Fixed   operator-(Fixed const & rhs);
    Fixed   operator*(Fixed const & rhs);
    Fixed   operator/(Fixed const & rhs);

    Fixed & operator++();
    Fixed & operator--();
    Fixed   operator++(int);
    Fixed   operator--(int);

    static const Fixed  min(Fixed const &nb1, Fixed const &nb2);
    static Fixed  min(Fixed &nb1, Fixed &nb2);
    static const Fixed  max(Fixed const &nb1, Fixed const &nb2);
    static Fixed  max(Fixed &nb1, Fixed &nb2);

    int toInt( void ) const;
    float toFloat( void ) const;

    int		getRawBits(void) const;
    void	setRawBits(int const raw);
};

std::ostream &	operator<<(std::ostream &o, Fixed const & rhs);

#endif