/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:46:32 by fzucconi          #+#    #+#             */
/*   Updated: 2025/03/04 17:46:33 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
private:
    int                 _value;
    static const int    _fractional_bits = 8;
public:
    Fixed( void );
    Fixed( const Fixed& other );
    Fixed &operator=( const Fixed& e );
    ~Fixed( void );

    int     getRawBits ( void ) const;
    void    setRawBits ( int const raw );
};


#endif