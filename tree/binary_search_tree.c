#include "../pub_include.h"

struct binary_tree_node *root = NULL;

void tree_build(int *array, int len) {
    struct binary_tree_node *p, *q;
    for(int i = 0; i < len; i++) {
        if(root == NULL) {
            root = malloc(sizeof(struct binary_tree_node));
            root->parent = NULL;
            root->left = NULL;
            root->right = NULL;
            root->entity = array[i];
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
            }else {
                q->left = malloc(sizeof(struct binary_tree_node));
                q->left->parent = q;
                q->left->left = NULL;
                q->left->right = NULL;
                q->left->entity = array[i];
            }
        }
    }
}

void left_traversal(struct binary_tree_node *node){
    if(node == NULL) {
        return;
    }
    left_traversal(node->left);
    printf("%d\t", node->entity);
    left_traversal(node->right);
}

struct binary_tree_node * tree_search(int entity) {
    struct binary_tree_node *p = root;
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
void tree_remove(struct binary_tree_node *node) {
    if(node == NULL) {
        return;
    }
    struct binary_tree_node *p;
    if(node->left == NULL) {
        p = node->right;;
        node->right->parent = node->parent;
    }else if(node->right == NULL) {
        p = node->left;
        node->left->parent = node->parent;
    }else {
        p = node->right;
        while(p->left != NULL) {
            p = p->left;
        }
        if(p != node->right) {
            p->right = node->right;
        }
        p->left = node->left;
        p->parent = node->parent;
    }
     if(node->parent->left == node){
        node->parent->left = p;
    }else {
        node->parent->right = p;
    }
    free(node);
}

void test_tree(){
    int array[] = ARRAY;
    int len = ARRAY_LEN(array);
    tree_build(array, len);
    left_traversal(root);
    printf("\n");
    struct binary_tree_node *search = tree_search(18);
    if(search != NULL) {
        printf("find node: %d, parent: %d\n", search->entity, search->parent->entity);
        printf("remove node: %d\n", search->entity);
        tree_remove(search);
        left_traversal(root);
    }
}
