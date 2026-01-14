/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_bag.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:00:44 by mpazouki          #+#    #+#             */
/*   Updated: 2026/01/08 11:43:25 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree_bag.hpp"
#include<iostream>

/* ========================= */
/*   Utility (private)      */
/* ========================= */


void tree_bag :: destroy_tree(node* n)
{
    if (!n)
        return;
    destroy_tree(n->l);
    destroy_tree(n->r);
    delete n;
}

void tree_bag :: print_node(node* n)
{
    if (!n)
        return;
    print_node(n->l);
    std::cout << n->value << " ";
    print_node(n->r);
}

tree_bag :: node* tree_bag :: copy_node(node* n)
{
    if (!n)
        return NULL;
    node* new_node = new node;
    new_node->value = n->value;
    new_node -> l = copy_node(n->l);
    new_node -> r = copy_node(n-> r);
    return new_node;
}





/* ========================= */
/*   Orthodox Canonical     */
/* ========================= */

tree_bag :: tree_bag() : tree(NULL) {}

tree_bag :: tree_bag(const tree_bag& other) :tree(NULL)
{
    tree = copy_node(other.tree);
}

tree_bag & tree_bag :: operator=(const tree_bag& other)
{
    if (this != &other)
    {
        clear();
        tree = copy_node(other.tree);
    }
    return *this;
}

tree_bag :: ~tree_bag()
{
    clear();
}


/* ========================= */
/*   Tree access helpers    */
/* ========================= */

tree_bag::node* tree_bag:: extract_tree()
{
    node* tmp = tree;
    tree = NULL;
    return tmp;
}

void tree_bag::set_tree(node* n)
{
    clear();
    tree = n;
}

/* ========================= */
/*        Methods            */
/* ========================= */

void tree_bag :: insert(int value)
{
    node ** current = &tree;

    while(*current)
    {
        if (value < (*current) -> value)
            current = &((*current) -> l);
        else 
            current = &((*current) -> r);
    }
    *current  = new node;
    (*current) -> value = value;
    (*current ) -> l = NULL;
    (*current) -> r = NULL;
}

void tree_bag :: insert(int* array, int size){
    if (!array || size < 0)
        return;
    for (int i = 0; i < size; i ++ )
        insert (array[i]);
}

void tree_bag :: print() const{
    print_node(tree);
    std::cout << std::endl;
}

void tree_bag:: clear(){
    destroy_tree(tree);
    tree = NULL;
}

