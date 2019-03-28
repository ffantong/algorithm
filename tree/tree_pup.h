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
void transplant(struct binary_tree_node *, struct binary_tree_node *);

enum color_enum {
    RED, BLACK
};

struct rb_tree_node {
    int entity;
    enum color_enum color;
    struct rb_tree_node *parent;
    struct rb_tree_node *left;
    struct rb_tree_node *right;
};
void test_rb_tree();
struct rb_tree_node * rb_tree_search(int);
void rb_tree_remove(struct rb_tree_node *);
void rb_center_traversal(struct rb_tree_node *);
void rb_left_traversal(struct rb_tree_node *);
void rb_tree_build(int *, int);
void rb_insert_fixup(struct rb_tree_node *);
void right_route(struct rb_tree_node *);
void left_route(struct rb_tree_node *);
void rb_delete_fixup(struct rb_tree_node *, struct rb_tree_node *, bool);
void rb_transplant(struct rb_tree_node *, struct rb_tree_node *);


struct b_tree_node {
    int key_len;
    int *keys;
    bool is_leaf;
    struct b_tree_node ** childs;
};
void b_tree_init();
void b_tree_create_node(struct b_tree_node *);
void b_tree_insert(int);
void b_tree_delete(struct b_tree_node *);
void b_tree_test();

#endif // TREE_PUB
