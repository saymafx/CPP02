/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidigov <tidigov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:57:45 by tidigov           #+#    #+#             */
/*   Updated: 2023/03/22 20:05:41 by tidigov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int m_value;
    static const int s_fractionalBits = 8;

public:
    Fixed();
    
    ~Fixed();

    Fixed(const Fixed& other) : m_value(other.m_value) {}

    Fixed& operator=(const Fixed& other) {
        if (this != &other) {
            m_value = other.m_value;
        }
        return *this;
    }

    int getRawBits() const;
    void setRawBits(int const raw);
};

#endif