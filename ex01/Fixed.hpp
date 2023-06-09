/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidigov <tidigov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:01:43 by tidigov           #+#    #+#             */
/*   Updated: 2023/03/26 09:22:53 by tidigov          ###   ########.fr       */
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
	Fixed(int const nb);
	Fixed(float const nb);
	~Fixed();

    Fixed & operator=(const Fixed& rhs);

    int toInt( void ) const;
    float toFloat( void ) const;

    int		getRawBits(void) const;
    void	setRawBits(int const raw);
};

std::ostream &	operator<<(std::ostream &o, Fixed const & rhs);

#endif