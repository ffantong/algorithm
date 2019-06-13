#include "../pub_include.h"
/*
    AA --2-- BB --3-- CC
    |       /  \       |
    |      /    \      |
    |     /      \     |
    2    3        4    2
    |   /          \   |
    |  /            \  |
    | /              \ |
    DD                EE
    | \              / |
    |  \            /  |
    |   \          /   |
    4    3        2    3
    |     \      /     |
    |      \    /      |
    |       \  /       |
    FF --3-- GG --2-- HH
*/

void init_graph(){
    nodes = malloc(sizeof(struct graph_node) * NODE_COUNT);

    nodes[0].node_name = "AA";
    nodes[0].edge_count = 2;
    nodes[0].edges = malloc(sizeof(struct graph_edge) * 2);
    nodes[0].edges[0].length = 2;
    nodes[0].edges[0].to_node = &nodes[3];
    nodes[0].edges[1].length = 2;
    nodes[0].edges[1].to_node = &nodes[1];

    nodes[1].node_name = "BB";
    nodes[1].edge_count = 4;
    nodes[1].edges = malloc(sizeof(struct graph_edge) * 4);
    nodes[1].edges[0].length = 2;
    nodes[1].edges[0].to_node = &nodes[0];
    nodes[1].edges[1].length = 3;
    nodes[1].edges[1].to_node = &nodes[2];
    nodes[1].edges[2].length = 3;
    nodes[1].edges[2].to_node = &nodes[3];
    nodes[1].edges[3].length = 4;
    nodes[1].edges[3].to_node = &nodes[4];

    nodes[2].node_name = "CC";
    nodes[2].edge_count = 2;
    nodes[2].edges = malloc(sizeof(struct graph_edge) * 2);
    nodes[2].edges[0].length = 3;
    nodes[2].edges[0].to_node = &nodes[1];
    nodes[2].edges[1].length = 2;
    nodes[2].edges[1].to_node = &nodes[4];

    nodes[3].node_name = "DD";
    nodes[3].edge_count = 4;
    nodes[3].edges = malloc(sizeof(struct graph_edge) * 4);
    nodes[3].edges[0].length = 2;
    nodes[3].edges[0].to_node = &nodes[0];
    nodes[3].edges[1].length = 3;
    nodes[3].edges[1].to_node = &nodes[1];
    nodes[3].edges[2].length = 4;
    nodes[3].edges[2].to_node = &nodes[5];
    nodes[3].edges[3].length = 3;
    nodes[3].edges[3].to_node = &nodes[6];

    nodes[4].node_name = "EE";
    nodes[4].edge_count = 4;
    nodes[4].edges = malloc(sizeof(struct graph_edge) * 4);
    nodes[4].edges[0].length = 4;
    nodes[4].edges[0].to_node = &nodes[1];
    nodes[4].edges[1].length = 2;
    nodes[4].edges[1].to_node = &nodes[2];
    nodes[4].edges[2].length = 2;
    nodes[4].edges[2].to_node = &nodes[6];
    nodes[4].edges[3].length = 3;
    nodes[4].edges[3].to_node = &nodes[7];

    nodes[5].node_name = "FF";
    nodes[5].edge_count = 2;
    nodes[5].edges = malloc(sizeof(struct graph_edge) * 2);
    nodes[5].edges[0].length = 4;
    nodes[5].edges[0].to_node = &nodes[3];
    nodes[5].edges[1].length = 3;
    nodes[5].edges[1].to_node = &nodes[6];

    nodes[6].node_name = "GG";
    nodes[6].edge_count = 4;
    nodes[6].edges = malloc(sizeof(struct graph_edge) * 4);
    nodes[6].edges[0].length = 3;
    nodes[6].edges[0].to_node = &nodes[5];
    nodes[6].edges[1].length = 3;
    nodes[6].edges[1].to_node = &nodes[3];
    nodes[6].edges[2].length = 2;
    nodes[6].edges[2].to_node = &nodes[4];
    nodes[6].edges[3].length = 2;
    nodes[6].edges[3].to_node = &nodes[7];

    nodes[7].node_name = "HH";
    nodes[7].edge_count = 2;
    nodes[7].edges = malloc(sizeof(struct graph_edge) * 2);
    nodes[7].edges[0].length = 2;
    nodes[7].edges[0].to_node = &nodes[6];
    nodes[7].edges[1].length = 3;
    nodes[7].edges[1].to_node = &nodes[4];
}
