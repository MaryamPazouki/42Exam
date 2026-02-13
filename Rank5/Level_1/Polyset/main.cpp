/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:49:06 by mpazouki          #+#    #+#             */
/*   Updated: 2026/01/14 11:23:06 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"
#include "set.hpp"
#include <iostream>

int main()
{
    int values[] = {5, 3, 8, 3, 1, 5};

    std::cout << "=== searchable_array_bag ===" << std::endl;
    searchable_array_bag ab;
    ab.insert(values, 6);
    ab.print();
    std::cout << "has 3: " << ab.has(3) << std::endl;
    std::cout << "has 7: " << ab.has(7) << std::endl;

    std::cout << "\n=== searchable_tree_bag ===" << std::endl;
    searchable_tree_bag tb;
    tb.insert(values, 6);
    tb.print();
    std::cout << "has 3: " << tb.has(3) << std::endl;
    std::cout << "has 7: " << tb.has(7) << std::endl;

    std::cout << "\n=== set (array backend) ===" << std::endl;
    searchable_array_bag ab2;
    set s1(ab2);
    s1.insert(values, 6);
    s1.print();

    std::cout << "\n=== set (tree backend) ===" << std::endl;
    searchable_tree_bag tb2;
    set s2(tb2);
    s2.insert(values, 6);
    s2.print();

    
    // Copy behavior test
    searchable_tree_bag t1;
    t1.insert(values, 6);
    searchable_tree_bag t2 = t1;
    t2.print();

    
    // Polymorphism test
    bag *b = new searchable_tree_bag();
    b->insert(values, 6);
    b->print();
    delete b;

    return 0;
}
