#include <stdio.h>
#include <malloc.h>
#include "Graph.h"

void initalize_graph(Graph* g, bool directed)
{
    int i = 0;

    g->vertex_num = 0;
    g->edge_num = 0;
    g->directed = directed;

    for (i = 1; i <= MAXV; i++) g->Edge[i] = NULL;
    for (i = 1; i <= MAXV; i++) g->Adjacent[i] = 0;
}

void insert_edge(Graph* g, int x, int y, bool directed)
{
    Node* p = (Node*)malloc(sizeof(Node));

    p->key = y;
    p->next = g->Edge[x];
    p->weight = NULL;

    g->Edge[x] = p;

    g->Adjacent[x]++;

    if (directed == false)
        insert_edge(g, y, x, true);
    else
        g->edge_num++;
}

void read_graph(Graph* g, bool directed)
{
    int i;
    int x, y;
    int edge_num;

    initalize_graph(g, directed);

    printf("Vertex / Edge : ");
    scanf_s("%d %d", &(g->vertex_num), &edge_num);

    for (i = 1; i <= edge_num; i++)
    {
        printf("Edge(x, y): ");
        scanf_s("%d %d", &x, &y);
        insert_edge(g, x, y, directed);
    }
}

void print_graph(Graph* g)
{
    int i;
    Node* p;

    for (i = 1; i <= g->vertex_num; i++)
    {
        printf("%d: ", i);
        p = g->Edge[i];

        while (p != NULL)
        {
            printf("%d ", p->key);
            p = p->next;
        }
        printf("\n");
    }
}