#ifndef GRAPH
#define GRAPH

struct graph_node {
    char * node_name;
    int edge_count;
    struct graph_edge *edges;
};

struct graph_edge {
    int length;
    struct graph_node * to_node;
};

#define NODE_COUNT 8

struct graph_node * graph_nodes;

int ** graph_map;

void graph_init();
void graph_destroy();

#endif // GRAPH
