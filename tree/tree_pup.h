#ifndef TREE_PUB
#define TREE_PUB

struct binary_tree_node {
    int entity;
    struct binary_tree_node *parent;
    struct binary_tree_node *left;
    struct binary_tree_node *right;
};

void tree_build(int *, int);
void test_tree();
void left_traversal(struct binary_tree_node *);
struct binary_tree_node * tree_search(int);
void tree_remove(struct binary_tree_node *);

#endif // TREE_PUB
