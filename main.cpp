#define MAXV 100
#define INF 9999

#include <iostream>
#include <list>
#include <string>
using namespace std;

int dijkstra_matriz(int matriz_adj[MAXV][MAXV], int vertices, int origem, int destino, bool visitado[])
{
    int pai[MAXV], melhor_distancia[MAXV], atual, melhor_distancia_atual;

    // Inicialização
    for (int i = 0; i < vertices; i++)
    {
        pai[i] = -1;
        melhor_distancia[i] = INF;
    }

    atual = origem;
    melhor_distancia[atual] = 0;

    while (!visitado[atual])
    {
        visitado[atual] = true;
        // Verificar todos os vizinhos do vértice atual
        for (int destino_adj = 0; destino_adj < vertices; destino_adj++)
        {
            if (!visitado[destino_adj] && matriz_adj[atual][destino_adj] != -1)
            {
                if (matriz_adj[atual][destino_adj] + melhor_distancia[atual] < melhor_distancia[destino_adj])
                {
                    melhor_distancia[destino_adj] = matriz_adj[atual][destino_adj] + melhor_distancia[atual];
                    pai[destino_adj] = atual;
                }
            }
        }
        // Encontrar próximo vértice a ser visitado
        melhor_distancia_atual = INF;
        for (int i = 0; i < vertices; i++)
        {
            if (!visitado[i] && melhor_distancia[i] < melhor_distancia_atual)
            {
                melhor_distancia_atual = melhor_distancia[i];
                atual = i;
            }
        }
    }

    return (melhor_distancia[destino] == INF) ? -1 : melhor_distancia[destino];
}

int main()
{
    int matriz_adj[MAXV][MAXV];
    bool visitado[MAXV];
    string cidade;
    float idh[MAXV], idh_min;

    // Número de cidades
    int C;
    cin >> C;

    // Leitura das cidades e seus IDHs
    for (int i = 0; i < C; i++)
    {
        cin >> cidade >> idh[i];
    }

    // Inicialização da matriz de adjacência
    for (int i = 0; i < C; i++)
    {
        for (int j = 0; j < C; j++)
        {
            matriz_adj[i][j] = -1;
        }
    }

    // Leitura das estradas
    int E, origem, destino, distancia;
    cin >> E;
    for (int i = 0; i < E; i++)
    {
        cin >> origem >> destino >> distancia;
        matriz_adj[origem][destino] = distancia;
        matriz_adj[destino][origem] = distancia; // Estrada bidirecional
    }

    // Leitura da origem, destino e IDH mínimo
    int Vo, Vd;
    cin >> Vo >> Vd >> idh_min;

    // Marca como visitadas as cidades com IDH menor que o mínimo
    for (int i = 0; i < C; i++)
    {
        visitado[i] = (idh[i] < idh_min);
    }

    // Calcula e imprime o resultado
    int resultado = dijkstra_matriz(matriz_adj, C, Vo, Vd, visitado);
    cout << resultado << endl;

    return 0;
}
