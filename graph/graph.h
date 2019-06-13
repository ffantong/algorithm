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

struct graph_node * nodes;

void init_graph();

#endif // GRAPH
