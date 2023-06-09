/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidigov <tidigov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:57:45 by tidigov           #+#    #+#             */
/*   Updated: 2023/03/23 18:29:15 by tidigov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int m_value;
    static const int s_Bits = 8;

public:
    Fixed();
    Fixed( Fixed const & src);
    
    ~Fixed();

    Fixed & operator=(const Fixed& rhs);

    int getRawBits() const;
    void setRawBits(int const raw);
};

#endif