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

void graph_init(){
    graph_nodes = malloc(sizeof(struct graph_node) * NODE_COUNT);

    graph_nodes[0].node_name = "AA";
    graph_nodes[0].edge_count = 2;
    graph_nodes[0].edges = malloc(sizeof(struct graph_edge) * 2);
    graph_nodes[0].edges[0].length = 2;
    graph_nodes[0].edges[0].to_node = &graph_nodes[3];
    graph_nodes[0].edges[1].length = 2;
    graph_nodes[0].edges[1].to_node = &graph_nodes[1];

    graph_nodes[1].node_name = "BB";
    graph_nodes[1].edge_count = 4;
    graph_nodes[1].edges = malloc(sizeof(struct graph_edge) * 4);
    graph_nodes[1].edges[0].length = 2;
    graph_nodes[1].edges[0].to_node = &graph_nodes[0];
    graph_nodes[1].edges[1].length = 3;
    graph_nodes[1].edges[1].to_node = &graph_nodes[2];
    graph_nodes[1].edges[2].length = 3;
    graph_nodes[1].edges[2].to_node = &graph_nodes[3];
    graph_nodes[1].edges[3].length = 4;
    graph_nodes[1].edges[3].to_node = &graph_nodes[4];

    graph_nodes[2].node_name = "CC";
    graph_nodes[2].edge_count = 2;
    graph_nodes[2].edges = malloc(sizeof(struct graph_edge) * 2);
    graph_nodes[2].edges[0].length = 3;
    graph_nodes[2].edges[0].to_node = &graph_nodes[1];
    graph_nodes[2].edges[1].length = 2;
    graph_nodes[2].edges[1].to_node = &graph_nodes[4];

    graph_nodes[3].node_name = "DD";
    graph_nodes[3].edge_count = 4;
    graph_nodes[3].edges = malloc(sizeof(struct graph_edge) * 4);
    graph_nodes[3].edges[0].length = 2;
    graph_nodes[3].edges[0].to_node = &graph_nodes[0];
    graph_nodes[3].edges[1].length = 3;
    graph_nodes[3].edges[1].to_node = &graph_nodes[1];
    graph_nodes[3].edges[2].length = 4;
    graph_nodes[3].edges[2].to_node = &graph_nodes[5];
    graph_nodes[3].edges[3].length = 3;
    graph_nodes[3].edges[3].to_node = &graph_nodes[6];

    graph_nodes[4].node_name = "EE";
    graph_nodes[4].edge_count = 4;
    graph_nodes[4].edges = malloc(sizeof(struct graph_edge) * 4);
    graph_nodes[4].edges[0].length = 4;
    graph_nodes[4].edges[0].to_node = &graph_nodes[1];
    graph_nodes[4].edges[1].length = 2;
    graph_nodes[4].edges[1].to_node = &graph_nodes[2];
    graph_nodes[4].edges[2].length = 2;
    graph_nodes[4].edges[2].to_node = &graph_nodes[6];
    graph_nodes[4].edges[3].length = 3;
    graph_nodes[4].edges[3].to_node = &graph_nodes[7];

    graph_nodes[5].node_name = "FF";
    graph_nodes[5].edge_count = 2;
    graph_nodes[5].edges = malloc(sizeof(struct graph_edge) * 2);
    graph_nodes[5].edges[0].length = 4;
    graph_nodes[5].edges[0].to_node = &graph_nodes[3];
    graph_nodes[5].edges[1].length = 3;
    graph_nodes[5].edges[1].to_node = &graph_nodes[6];

    graph_nodes[6].node_name = "GG";
    graph_nodes[6].edge_count = 4;
    graph_nodes[6].edges = malloc(sizeof(struct graph_edge) * 4);
    graph_nodes[6].edges[0].length = 3;
    graph_nodes[6].edges[0].to_node = &graph_nodes[5];
    graph_nodes[6].edges[1].length = 3;
    graph_nodes[6].edges[1].to_node = &graph_nodes[3];
    graph_nodes[6].edges[2].length = 2;
    graph_nodes[6].edges[2].to_node = &graph_nodes[4];
    graph_nodes[6].edges[3].length = 2;
    graph_nodes[6].edges[3].to_node = &graph_nodes[7];

    graph_nodes[7].node_name = "HH";
    graph_nodes[7].edge_count = 2;
    graph_nodes[7].edges = malloc(sizeof(struct graph_edge) * 2);
    graph_nodes[7].edges[0].length = 2;
    graph_nodes[7].edges[0].to_node = &graph_nodes[6];
    graph_nodes[7].edges[1].length = 3;
    graph_nodes[7].edges[1].to_node = &graph_nodes[4];

    graph_map = malloc(NODE_COUNT * sizeof(int*));
    for(int i = 0; i < NODE_COUNT; i++) {
        graph_map[i] = malloc(NODE_COUNT * sizeof(int*));
        for(int j = 0; j < NODE_COUNT; j++) {
            graph_map[i][j] = -1;
        }
    }
    graph_map[0][1] = graph_map[1][0] = 2;
    graph_map[1][2] = graph_map[2][1] = 3;
    graph_map[0][3] = graph_map[3][0] = 2;
    graph_map[1][3] = graph_map[3][1] = 3;
    graph_map[1][4] = graph_map[4][1] = 4;
    graph_map[2][4] = graph_map[4][2] = 2;
    graph_map[3][5] = graph_map[5][3] = 4;
    graph_map[3][6] = graph_map[6][3] = 3;
    graph_map[4][6] = graph_map[6][4] = 2;
    graph_map[4][7] = graph_map[7][4] = 3;
    graph_map[5][6] = graph_map[6][5] = 3;
    graph_map[6][7] = graph_map[7][6] = 2;
}

void graph_destroy(){
    for(int i = 0; i < NODE_COUNT; i++) {
        free(graph_nodes[i].edges);
        free(graph_map[i]);
    }
    free(graph_nodes);
    free(graph_map);
}
