#include "bag.hpp"

class tree_bag : virtual public bag
{
protected:
    struct node
    {
        node* l;
        node* r;
        int   value;
    };

    node* tree;

private:
    static void destroy_tree(node*);
    static void print_node(node*);
    static node* copy_node(node*);

public:
    tree_bag();
    tree_bag(const tree_bag&);
    tree_bag& operator=(const tree_bag&);
    virtual ~tree_bag();

    node* extract_tree();
    void set_tree(node*);

    void insert(int);
    void insert(int* array, int size);
    void print() const;
    void clear();
};
