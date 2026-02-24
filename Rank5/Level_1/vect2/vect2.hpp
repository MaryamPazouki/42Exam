/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:13:38 by mpazouki          #+#    #+#             */
/*   Updated: 2026/02/17 07:57:52 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef VECT2_HPP
#define VECT2_HPP


#include <iostream>

//#include <vector>


class vect2{
    private:
        int x;
        int y;
        
    public:
        vect2();
        vect2(int a, int b);
        vect2(const vect2& other);
        vect2& operator=(const vect2& other);
        vect2& operator=(int a);
        ~vect2();

        // Access operator
        int& operator [](int i);
        int operator [] (int i) const;

        // Arithmetic with vectors 
        vect2 operator+(const vect2& rhs) const; 
        vect2 operator-(const vect2& rhs) const; 
        
        // Scalar multiplication : v *scalar
        vect2 operator*(int scalar) const; 
        vect2& operator*=(int scalar); 
        
        // Compound assignment 
        vect2& operator+=(const vect2& rhs); 
        vect2& operator-=(const vect2& rhs);
        
        
        //unary minus
        vect2 operator-() const;
        
        //increment, decrement 
        //++ (prefix, postfix), -- (prefix, postfix),
        vect2& operator++();  //prefix
        vect2 operator++(int);  //postfix
        vect2& operator--();
        vect2 operator--(int);     
        

        //comparision
        // ==, != 
        bool operator==(const vect2& other) const;
        bool operator!=(const vect2& other) const;   

        // Friend for scalar * vect2
        friend vect2 operator*(int s, const vect2& v);

        //printing
        friend std::ostream& operator <<(std::ostream& os, const vect2& v);

};

#endif 
 