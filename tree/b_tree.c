#include "../pub_include.h"


static struct b_tree_node * root;
static int degree = 3;

void b_tree_init(){
    b_tree_create_node(root);
}

void b_tree_create_node(struct b_tree_node * p){
    p = malloc(sizeof(struct b_tree_node));
    p->childs = malloc(sizeof(struct b_tree_node *) * degree * 2);
    p->keys = malloc(sizeof(int) * (degree * 2 - 1));
    p->key_len = 0;
}

void b_tree_insert(int key){

}

void b_tree_delete(struct b_tree_node * p){
}

void b_tree_test(){
}

