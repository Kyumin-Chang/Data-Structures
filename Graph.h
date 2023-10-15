#define MAXV 1000

struct Node
{
    int key;
    int weight;
    Node* next;
};

struct Graph
{
    Node* Edge[MAXV + 1];
    int Adjacent[MAXV + 1];
    int vertex_num;
    int edge_num;
    bool directed;
};

void initalize_graph(Graph* g, bool directed);
void insert_edge(Graph* g, int x, int y, bool directed);
void read_graph(Graph* g, bool directed);
void print_graph(Graph* g);