/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:13:43 by mpazouki          #+#    #+#             */
/*   Updated: 2026/02/17 07:59:57 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

vect2 ::vect2() : x(0), y(0) {};
vect2 ::vect2(int a, int b) : x(a), y(b) {};
vect2 ::vect2(const vect2 &other) : x(other.x), y(other.y) {};
vect2 &vect2 ::operator=(const vect2 &other)
{
    if (this != &other)
    {
        x = other.x;
        y = other.y;
    }
    return *this;
}
vect2& vect2::operator=(int num){
    x = num;
    y = num;
    return *this;
}

vect2 ::~vect2() {};

int &vect2::operator[](int i)
{
    return (i == 0 ? x : y);
}

int vect2 ::operator[](int i) const
{
    return (i == 0 ? x : y);
}

//This function does not modify the object on which it is called
vect2 vect2 :: operator+(const vect2 &rhs) const
{
    return vect2(x + rhs.x, y + rhs.y); //create brand new vector
}
vect2 vect2 :: operator-(const vect2 &rhs) const
{
    return vect2(x - rhs.x, y - rhs.y);//create brand new vector
}

//This function does not modify the object on which it is called
vect2 vect2 ::operator*(int scalar) const
{
    return vect2(scalar * x, scalar * y); //create brand new vector
}


vect2& vect2 ::operator*=(int scalar)
{
    x *= scalar;
    y *= scalar;
    return *this;
}
//-----------------------------------------
vect2& vect2 ::operator+=(const vect2 &rhs)
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

vect2& vect2 ::operator-=(const vect2 &rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}
//------------------------------------------
// unary minus
//Unary minus does not modify anything, so it must return a value.
vect2 vect2 ::operator-() const
{
    return vect2(-x, -y);
}
//---------------------------------------
// increment and decrement
vect2& vect2::operator++(){
    ++x;
    ++y;
    return *this;
}// prefix


vect2 vect2::operator++(int){
    vect2 tmp(*this);
    ++(*this);
    return tmp;
} // postfix

vect2& vect2::operator--(){
    --x;
    --y;
    return *this;
}
vect2 vect2::operator--(int){
    vect2 tmp(*this);
    --(*this);
    return tmp;
}

bool vect2 :: operator==(const vect2& other) const{
    return (x == other.x && y == other.y);
}

bool vect2 :: operator!=(const vect2& other) const{
    return (x != other.x || y != other.y);
}

vect2 operator*(int s, const vect2& v){
    return vect2(v.x * s , v.y *s);
}

std::ostream& operator << (std::ostream& os, const vect2& v){
    os << "{" << v.x << ", " << v.y << "}";
    return os;
}
