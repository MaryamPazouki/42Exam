/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:26:12 by mpazouki          #+#    #+#             */
/*   Updated: 2026/01/08 14:31:41 by mpazouki         ###   ########.fr       */
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

void insert(int value);
void insert(int *array, int size);
void print() const;
void clear();