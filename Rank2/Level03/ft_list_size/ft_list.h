
typedef struct s_list
{
    struct s_list   *next; //this is a self-referential pointer
    void            *data; // generic pointer, it can point to any type of data.
}                   t_list;
