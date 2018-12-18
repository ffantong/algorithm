#include "../pub_include.h"

static struct rb_tree_node *root = NULL;

void left_route(struct rb_tree_node * node){
    struct rb_tree_node *p = node->right;
    node->right = p->left;
    if(node->right != NULL) {
        node->right->parent = node;
    }
    p->parent = node->parent;
    if(node == root) {
        root = p;
        p->color = BLACK;
    }else if (node == node->parent->left) {
        node->parent->left = p;
    }else {
        node->parent->right = p;
    }
    node->parent = p;
    p->left = node;
}

void right_route(struct rb_tree_node * node){
    struct rb_tree_node *p = node->left;
    node->left = p->right;
    if(p->left != NULL) {
        p->left->parent = node;
    }
    p->parent = node->parent;
    if(node == root) {
        root = p;
        p->color = BLACK;
    }else if (node == node->parent->left) {
        node->parent->left = p;
    }else {
        node->parent->right = p;
    }
    node->parent = p;
    p->right = node;
}

void rb_insert_fixup(struct rb_tree_node * node) {
    struct rb_tree_node *p;
    while(node->parent != NULL && node->parent->color != BLACK) {
        if(node->parent == node->parent->parent->left) {
            p = node->parent->parent->right;
            if(p != NULL && p->color == RED){
                p->color = BLACK;
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
                root->color = BLACK;
            }else if (node == node->parent->right) {
                node = node->parent;
                left_route(node);
            }else{
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                right_route(node->parent->parent);
            }
        }else {
            p = node->parent->parent->left;
            if(p != NULL && p->color == RED){
                p->color = BLACK;
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
                root->color = BLACK;
            }else if (node == node->parent->left) {
                node = node->parent;
                right_route(node);
            }else{
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                left_route(node->parent->parent);
            }
        }
    }
}


void rb_tree_build(int *array, int len) {
    struct rb_tree_node *p, *q;
    for(int i = 0; i < len; i++) {
        if(root == NULL) {
            root = malloc(sizeof(struct rb_tree_node));
            root->parent = NULL;
            root->left = NULL;
            root->right = NULL;
            root->entity = array[i];
            root->color = BLACK;
        }else {
            q = root;
            p = q;
            while(p != NULL) {
                if(array[i] > p->entity) {
                    q = p;
                    p = p->right;
                }else {
                    q = p;
                    p = p->left;
                }
            }
            if(array[i] > q->entity) {
                q->right = malloc(sizeof(struct binary_tree_node));
                q->right->parent = q;
                q->right->left = NULL;
                q->right->right = NULL;
                q->right->entity = array[i];
                q->right->color = RED;
                p = q->right;
            }else {
                q->left = malloc(sizeof(struct binary_tree_node));
                q->left->parent = q;
                q->left->left = NULL;
                q->left->right = NULL;
                q->left->entity = array[i];
                q->left->color = RED;
                p = q->left;
            }
            rb_insert_fixup(p);
        }
    }
}

void rb_left_traversal(struct rb_tree_node *node){
    if(node == NULL) {
        return;
    }
    rb_left_traversal(node->left);
    printf("%d:%s\t", node->entity, node->color == RED ? "RED" : "BLACK");
    rb_left_traversal(node->right);
}

void rb_center_traversal(struct rb_tree_node *node){
    if(node == NULL) {
        return;
    }
    printf("%d:%s\t", node->entity, node->color == RED ? "RED" : "BLACK");
    rb_center_traversal(node->left);
    rb_center_traversal(node->right);
}

void rb_delete_fixup(struct rb_tree_node *node){
    struct rb_tree_node *p;
    while(node != root && node->color == BLACK) {
        if(node == node->parent->left) {
            p = node->parent->right;
            if (p != NULL && p->color == RED) {
                p->color = BLACK;
                node->parent->color = RED;
                left_route(node->parent);
                p = node->parent->right;
            }
            if(p != NULL && p->left->color == BLACK && p->right->color == BLACK) {
                p->color = RED;
                node = node->parent;
            }else{
                if (p != NULL && p->right->color == BLACK) {
                    p->left->color = BLACK;
                    p->color = RED;
                    right_route(p);
                    p = node->parent->right;
                }
                p->color = node->parent->color;
                node->parent->color = BLACK;
                p->right->color = BLACK;
                left_route(node->parent);
                node = root;
            }
        }else {
            p = node->parent->left;
            if (p != NULL && p->color == RED) {
                p->color = BLACK;
                node->parent->color = RED;
                right_route(node->parent);
                p = node->parent->left;
            }
            if(p != NULL && p->left->color == BLACK && p->right->color == BLACK) {
                p->color = RED;
                node = node->parent;
            }else {
                if (p != NULL && p->left->color == BLACK) {
                    p->right->color = BLACK;
                    p->color = RED;
                    left_route(p);
                    p = node->parent->left;
                }
                p->color = node->parent->color;
                node->parent->color = BLACK;
                p->left->color = BLACK;
                right_route(node->parent);
                node = root;
            }
        }
    }
    node->color = BLACK;
}

void rb_transplant(struct rb_tree_node *x, struct rb_tree_node *y){
    if(x->parent == NULL) {
        root = y;
    }else if(x == x->parent->left) {
        x->parent->left = y;
    }else{
        x->parent->right = y;
    }
    if(y != NULL) {
        y->parent = x->parent;
    }
}

void rb_tree_remove(struct rb_tree_node *node) {
    if(node == NULL) {
        return;
    }
    struct rb_tree_node *p;
    enum color_enum color_before = node->color;
    if(node->left == NULL) {
        p = node->right;
        rb_transplant(node, node->right);
    }else if(node->right == NULL) {
        p = node->left;
        rb_transplant(node, node->left);
    }else {
        p = node->right;
        while(p->left != NULL) {
            p = p->left;
        }
        color_before = p->color;
        struct rb_tree_node *q = p->right;
        if(q == NULL) {
            q = p;
        }
        if(p->parent != node) {
            rb_transplant(p, p->right);
            p->right = node->right;
            p->right->parent = p;
        }
        rb_transplant(node, p);
        p->left = node->left;
        p->left->parent = p;
        p->color = node->color;
        p = q;
    }
    free(node);
    if (color_before == BLACK) {
        rb_delete_fixup(p);
    }
}

struct rb_tree_node * rb_tree_search(int entity) {
    struct rb_tree_node *p = root;
    while(p != NULL) {
        if(entity > p->entity) {
            p = p->right;
        }else if(entity < p->entity) {
            p = p->left;
        }else{
            return p;
        }
    }
    return NULL;
}

void test_rb_tree(){
    int array[] = ARRAY;
    int len = ARRAY_LEN(array);
    rb_tree_build(array, len);
    rb_left_traversal(root);
    printf("\n");
    rb_center_traversal(root);
    struct rb_tree_node *search = rb_tree_search(15);
    if(search != NULL) {
        printf("find node: %d, parent: %d\n", search->entity, search->parent->entity);
        printf("remove node: %d\n", search->entity);
        rb_tree_remove(search);
        rb_left_traversal(root);
        printf("\n");
        rb_center_traversal(root);
    }
}
