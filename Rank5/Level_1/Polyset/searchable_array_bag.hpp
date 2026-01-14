/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:06:26 by mpazouki          #+#    #+#             */
/*   Updated: 2026/01/07 11:47:02 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHABLE_ARRAY_BAG_HPP
#define SEARCHABLE_ARRAY_BAG_HPP

#include "array_bag.hpp"
#include "searchable_bag.hpp"

class searchable_array_bag : 
    public array_bag,
    public searchable_bag
{
    public:
        searchable_array_bag();
        searchable_array_bag(const searchable_array_bag&);
        searchable_array_bag& operator= (const searchable_array_bag&);
        virtual ~searchable_array_bag();

        bool has(int value) const;   
};


#endif

/* Inheritance

array_bag already implements all bag methods

searchable_bag only adds has()

This class only needs to implement has() */