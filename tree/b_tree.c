#include "../pub_include.h"


static struct b_tree_node * root;
static int degree = 3;
static int max;
static int min;

void b_tree_init(){
    root = b_tree_create_node();
    root->is_leaf = true;
    min = degree - 1;
    max = 2 * degree - 1;
}

struct b_tree_node * b_tree_create_node(){
    struct b_tree_node * p = malloc(sizeof(struct b_tree_node));
    p->childs = malloc(sizeof(struct b_tree_node *) * degree * 2);
    for(int i = 0; i < degree * 2; i++) {
        p->childs[i] = NULL;
    }
    p->keys = malloc(sizeof(int) * max);
    p->key_len = 0;
    p->is_leaf = true;
    return p;
}

void b_tree_search(struct b_tree_node * p, int key){
    int index = 0;
    for(; index < p->key_len; index++) {
        if(p->keys[index] >= key) {
            break;
        }
    }
    if(index < p->key_len && p->keys[index] == key) {
        printf("%c fonud\n", key);
    }else if(p->is_leaf) {
        printf("%c not found\n", key);
    }else {
        b_tree_search(p->childs[index], key);
    }
}

static void b_tree_split(struct b_tree_node * parent, struct b_tree_node * p){
    struct b_tree_node *q = b_tree_create_node();
    q->is_leaf = p->is_leaf;
    q->key_len = min;
    p->key_len = min;
    for(int i = 0; i < min; i++) {
        q->keys[i] = p->keys[i];
        p->keys[i] = p->keys[min + i + 1];
        q->childs[i] = p->childs[i];
        p->childs[i] = p->childs[min + i + 1];
        p->childs[min + i + 1] = NULL;
    }
    q->childs[min] = p->childs[min];
    p->childs[min] = p->childs[min + min + 1];
    p->childs[min + min + 1] = NULL;
    if(parent->key_len == 0) {
        parent->keys[0] = p->keys[min];
        parent->childs[0] = q;
        parent->childs[1] = p;
        parent->key_len++;
    }else{
        int i = parent->key_len;
        for(; i >= 0; i++){
            parent->keys[i] = parent->keys[i - 1];
            parent->childs[i + 1] = parent->childs[i];
            if(parent->keys[i - 1] < p->keys[min]) {
                break;
            }
        }
        parent->childs[i] = parent->childs[i - 1];
        parent->keys[i] = p->keys[min];
        parent->childs[i] = q;
        parent->key_len++;
    }
    parent->is_leaf = false;
}

void b_tree_insert(int key){
    struct b_tree_node * parent = NULL, * insert_node = root;
    int index;
    while(insert_node != NULL) {
        if(parent == NULL && root->key_len == max) {
            insert_node = root;
            root = b_tree_create_node();
            b_tree_split(root, insert_node);
            if(key < root->keys[0]) {
                insert_node = root->childs[0];
                index = 0;
                parent = root;
            }else {
                insert_node = root->childs[1];
                index = 1;
                parent = root;
            }
        }else{
            if(insert_node->key_len == max) {
                b_tree_split(parent, insert_node);
                if(key > parent->keys[index]) {
                    index += 1;
                }else{
                    insert_node = parent->childs[index];
                }
            }
            if(insert_node->is_leaf) {
                for(index = insert_node->key_len; index > 0; index--) {
                    if(insert_node->keys[index - 1] < key) {
                        break;
                    }
                    insert_node->keys[index] = insert_node->keys[index - 1];
                }
                insert_node->keys[index] = key;
                insert_node->key_len++;
                break;
            }else {
                for(index = 0; index < insert_node->key_len; index++) {
                    if(insert_node->keys[index] > key) {
                        break;
                    }
                }
                parent = insert_node;
                insert_node = insert_node->childs[index];
            }
        }
    }
}

void b_tree_delete(struct b_tree_node * p){
}

void b_tree_test(){
    b_tree_init();
    for(char i = 'A'; i <= 'Z'; i++) {
        b_tree_insert(i);
    }
    for(int i = 0; i < root->childs[0]->key_len; i++){
        printf("%c\t", root->childs[0]->keys[i]);
    }
    printf("\n");
    for(char i = 'A'; i <= 'Z'; i++) {
        b_tree_search(root, i);
    }
}

