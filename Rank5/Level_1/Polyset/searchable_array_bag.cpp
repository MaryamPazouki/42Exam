/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:36:12 by mpazouki          #+#    #+#             */
/*   Updated: 2026/01/07 11:45:36 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_array_bag.hpp"
#include<iostream>

searchable_array_bag:: searchable_array_bag(): array_bag() {};
searchable_array_bag :: searchable_array_bag(const searchable_array_bag&other)
    :array_bag(other)    
{
    std::cout << "copy assinment" << std::endl;
}

searchable_array_bag& searchable_array_bag::operator = (const searchable_array_bag &other){
    if (this != &other)
        array_bag::operator=(other);
    return *this;
} 

searchable_array_bag :: ~searchable_array_bag (){};

/* ========================= */
/*        Methods            */
/* ========================= */
bool searchable_array_bag ::has(int value) const{
    
    for (int i = 0; i< size; i++)
    {    
        if (data[i] == value)
            return true; 
    }
    return false;
}

