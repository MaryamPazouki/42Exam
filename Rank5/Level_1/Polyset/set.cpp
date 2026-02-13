/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:26:12 by mpazouki          #+#    #+#             */
/*   Updated: 2026/01/14 10:48:26 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"
#include <iostream>

set::set(searchable_bag &b): bag(b)
{};

set::set(const set &other): bag(other.bag) 
{};

set& set::operator=(const set &other){
    if (this != &other)
    {
        bag.clear();
        int *tmp = NULL;
        (void)tmp;
    }
    return *this;
};
set :: ~set(){};

/* ========================= */
/*        Methods            */
/* ========================= */

void set :: insert(int value){
    if (!bag.has(value))
        bag.insert(value);
}
void set:: insert(int *array, int size){
    if (!array || size < 0)
        return;
    for (int i = 0; i<size ; i++)
        insert(array[i]);
}

void set :: print() const{
    bag.print();
}
void set :: clear(){
    bag.clear();
}