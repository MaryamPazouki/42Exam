/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:55:06 by mpazouki          #+#    #+#             */
/*   Updated: 2026/01/08 12:04:40 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_tree_bag.hpp"
#include <iostream>

searchable_tree_bag:: searchable_tree_bag() : tree_bag(){}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag&other)
    :tree_bag(other)
    {   
    }
searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& other)
{
    if (this != &other)
        tree_bag::operator=(other);
    return *this;
}

searchable_tree_bag :: ~searchable_tree_bag()
{
}

/* ========================= */
/*        Methods            */
/* ========================= */

bool searchable_tree_bag :: has(int value) const 
{
    node* current = tree;
    while(current)
    {
        if(value == current -> value)
            return true;
        if (value < current -> value)
            current  = current -> l;
        else 
            current = current ->r;
    }
    return false;
}