/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:48:26 by mpazouki          #+#    #+#             */
/*   Updated: 2026/01/08 11:54:54 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHABLE_TREE_BAG_HPP
#define SEARCHABLE_TREE_BAG_HPP

#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class searchable_tree_bag : 
    public tree_bag,
    public searchable_bag
{
    public:
    searchable_tree_bag();
    searchable_tree_bag(const searchable_tree_bag&);
    searchable_tree_bag& operator=(const searchable_tree_bag&);
    virtual ~searchable_tree_bag();

    bool has(int value) const;
};





#endif