#define INF 9999
#define MAXV 200000 // Adjusted for problem constraints

#include <iostream>
#include <list>
using namespace std;

struct Aresta
{
    int destino, peso;
};

// Function to find minimum spanning tree cost using Prim's algorithm
int prim_lista(list<Aresta> listas_adj[], int vertices, int origem)
{
    bool visitado[MAXV];
    int melhor_aresta[MAXV], pai[MAXV], atual, melhor_aresta_atual;
    list<Aresta>::iterator it;

    // Initialize arrays
    for (int i = 0; i < vertices; i++)
    {
        visitado[i] = false;
        pai[i] = -1;
        melhor_aresta[i] = INF;
    }

    atual = origem;
    melhor_aresta[atual] = 0;

    while (!visitado[atual])
    {
        visitado[atual] = true;
        // Check all neighbors of current vertex
        for (it = listas_adj[atual].begin(); it != listas_adj[atual].end(); it++)
        {
            int destino_adj = it->destino;
            int peso_adj = it->peso;
            if (!visitado[destino_adj] && peso_adj < melhor_aresta[destino_adj])
            {
                melhor_aresta[destino_adj] = peso_adj;
                pai[destino_adj] = atual;
            }
        }
        // Find next vertex to visit
        melhor_aresta_atual = INF;
        for (int i = 0; i < vertices; i++)
        {
            if (!visitado[i] && melhor_aresta[i] < melhor_aresta_atual)
            {
                melhor_aresta_atual = melhor_aresta[i];
                atual = i;
            }
        }
    }

    // Calculate total cost of MST
    int total_mst = 0;
    for (int i = 0; i < vertices; i++)
    {
        if (visitado[i])
        {
            total_mst += melhor_aresta[i];
        }
    }

    return total_mst;
}

int main()
{
    list<Aresta> listas_adj[MAXV];
    int m, n, x, y, z;

    while (true)
    {
        // Read number of vertices (m) and edges (n)
        cin >> m >> n;

        // Check for end of input
        if (m == 0 && n == 0)
            break;

        // Clear previous adjacency lists
        for (int i = 0; i < m; i++)
        {
            listas_adj[i].clear();
        }

        // Read edges and calculate total cost
        int total_cost = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y >> z;
            // Add edges to adjacency list (undirected graph)
            listas_adj[x].push_back({y, z});
            listas_adj[y].push_back({x, z});
            total_cost += z; // Add cost of current road
        }

        // Find minimum spanning tree cost
        int mst_cost = prim_lista(listas_adj, m, 0);

        // Calculate and print savings
        cout << total_cost - mst_cost << endl;
    }

    return 0;
}
