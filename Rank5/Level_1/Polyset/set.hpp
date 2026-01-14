/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:17:00 by mpazouki          #+#    #+#             */
/*   Updated: 2026/01/08 14:25:17 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class set
{
    private:
        searchable_bag& bag;
    public:
        set(searchable_bag& bag);
        set(const set&);
        set& operator=(const set&);
        ~set();

        void insert(int value);
        void insert(int *array, int size);
        void print() const;
        void clear();
    
};


#endif