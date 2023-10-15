#include <stdio.h>
#include <queue>
#include "Graph.h"
using namespace std;

bool discovered[MAXV + 1];
bool processed[MAXV + 1];
int parent[MAXV + 1];

void initalize_search(Graph* g)
{
    int i;

    for (i = 1; i <= g->vertex_num; i++)
    {
        processed[i] = discovered[i] = false;
        parent[i] = -1;
    }
}

void process_vertex_early(int v)
{
    printf("Processed Vertex %d\n", v);
}

void process_edge(int v, int key)
{
    printf("Processed Edge : (%d, %d)\n", v, key);
}

void process_vertex_late(int v)
{
}

void print_parent(Graph* g)
{
    int i;

    for (int i = 1; i <= g->vertex_num; i++)
        printf("Vertex : %d, Parent: %d\n", i, parent[i]);
}

void find_path(int start, int end, int parents[])
{
    if ((start == end) || (end == -1))
        printf("\n%d", start);
    else
    {
        find_path(start, parents[end], parents);
        printf(" %d", end);
    }
}

void BFS(Graph* g, int start)
{
    queue<int> q;
    int v;
    int key;
    Node* p;

    q.push(start);
    discovered[start] = true;

    while (!q.empty())
    {
        v = q.front();
        q.pop();
        process_vertex_early(v);
        p = g->Edge[v];
        while (p != NULL)
        {
            key = p->key;
            if (processed[key] == false || g->directed)
                process_edge(v, key);
            if (discovered[key] == false)
            {
                q.push(key);
                discovered[key] = true;
                parent[key] = v;
            }
            p = p->next;
        }
        processed[v] = true;
        process_vertex_late(v);
    }
}

void connected_component(Graph* g)
{
    int c = 0;    /* component number */
    int i;

    initalize_search(g);

    for (i = 1; i <= g->vertex_num; i++)
    {
        if (discovered[i] == false)
        {
            c = c + 1;
            printf("Component %d :", c);
            BFS(g, i);
            printf("\n");
        }
    }
}

int main()
{
    Graph* g = (Graph*)malloc(sizeof(Graph));

    read_graph(g, true);
    print_graph(g);

    connected_component(g);

    return 0;
}