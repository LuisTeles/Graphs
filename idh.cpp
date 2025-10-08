#define MAXV 100
#define INF 9999

#include <iostream>
#include <list>
using namespace std;

// Um turista esta planejando seu roteiro de viagem. Considerando que ele só quer visitar uma lista de cidades com um determinado nível de IDH ou maior, desenvolva um código para ajudar ele a definir quanto de combustível ele precisa comprar. Ou seja, dado a cidade de origem e a cidade de destino, calcule e retorne a distância mínima para fazer essa rota.

// A entrada começa com um inteiro C que é o número de cidades a serem consideradas. Nas C linhas seguintes são dadas as informações de cada cidade: uma string contendo o nome da cidade e um número real que é o IDH da cidade (cada cidade deve ter um código automático que um número inteiro de 0 a C-1 dado na ordem em que a cidade foi inserida). Em seguida é informado um numero E, que é o número de estradas que conectam as C cidades. As próximas E linhas contêm três inteiros Co, Cd e D que são respectivamente o código da cidade de origem, o código da cidade de destino e a distância de cada uma das E estradas (todas as estradas permitem navegação nos dois sentidos). Por fim, são informados dois inteiros Vo e Vd que representam o código da cidade origem e o código da cidade de destino da viagem e um número real H que representa o IDH mínimo que uma cidade precisa ter para ser considerada na rota.

// A saída deve ser um inteiro representando a menor rota para sair da cidade Vo e chegar na cidade Vd passando apenas por cidades com um IDH maior que H.

int dijkstra_matriz(int matriz_adj[MAXV][MAXV], int vertices, int origem, int destino, bool visitado[])
{
    int pai[vertices], melhor_distancia[vertices], atual, melhor_distancia_atual;
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
    list<int> caminho;
    atual = destino;
    while (visitado[atual] && pai[atual] != -1)
    {
        caminho.push_front(atual);
        atual = pai[atual];
    }
    cout << origem;
    while (!caminho.empty())
    {
        cout << " -> " << caminho.front();
        caminho.pop_front();
    }
    cout << endl;
    return melhor_distancia[destino];
}

int main()
{

    int matriz_adj[MAXV][MAXV];
    bool visitado[MAXV];

    int c, e, co, cd, d;
    string nome;
    float idh[MAXV], idh_min;

    cin >> c;
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < c; j++)
        {
            matriz_adj[i][j] = -1;
        }
    }

    for (int i = 0; i < c; i++)
    {
        cin >> nome;
        cin >> idh[i];
    }

    cin >> e;
    for (int j = 0; j < e; j++)
    {
        cin >> co >> cd >> d;
        matriz_adj[co][cd] = d;
        matriz_adj[cd][co] = d;
    }

    cin >> co >> cd >> idh_min;

    for (int i = 0; i < c; i++)
    {
        visitado[i] = false;
        if (idh[i] < idh_min)
        {
            visitado[i] = true;
        }
    }

    cout << dijkstra_matriz(matriz_adj, c, co, cd, visitado) << endl;
}