/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_bag.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:06:44 by mpazouki          #+#    #+#             */
/*   Updated: 2026/01/07 11:27:22 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_bag.hpp"
#include <iostream>

/* ========================= */
/*   Orthodox Canonical      */
/* ========================= */

array_bag ::array_bag() : data(NULL), size(0)
{
}

array_bag::array_bag(const array_bag &other) : data(NULL), size(0)
{
    if (other.size > 0)
    {
        data = new int[other.size];
        for (int i = 0; i < other.size; i++)
        {
            data[i] = other.data[i];
        }
        size = other.size;
    }
}

array_bag &array_bag::operator=(const array_bag &other)
{
    if (this != &other)
    {
        clear();
        if (other.size > 0)
        {
            data = new int[other.size];
            for (int i = 0; other.size; i++)
                data[i] = other.data[i];
            size = other.size;
        }
    }
    return *this;
}

array_bag::~array_bag()
{
    clear();
}

/* ========================= */
/*        Methods            */
/* ========================= */

void array_bag :: insert(int value){
    int* new_data = new int[size + 1];

    for (int i = 0; i< size ; i ++)
        new_data[i] = data[i];
    new_data[size ] = value; 

    delete[] data;
    data = new_data;
    size ++;
}

void array_bag :: insert(int* array, int n){
    if (!array || n <= 0) 
        return;
    for (int i= 0; i< n ; i++)
        insert(array[i]);
    std::cout << std::endl;
}

void array_bag :: print() const {
    for (int i = 0; i < size; i ++)
        std::cout << data[i] << " ";
    std::cout << std::endl;
}

void array_bag :: clear()
{
    delete[] data;
    data = NULL;
    size = 0;
}