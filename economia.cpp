#define INF 9999
#define MAXV 100

#include<iostream>
#include<list>
using namespace std;

struct Aresta{
    int destino, peso;
};

int prim_lista(list<Aresta> listas_adj[], int vertices, int origem){
    bool visitado[vertices];
    int melhor_aresta[vertices], pai[vertices], atual, melhor_aresta_atual;
    list<Aresta>::iterator it;
    for(int i=0;i<vertices;i++){
        visitado[i] = false;
        pai[i] = -1;
        melhor_aresta[i] = INF;
    }
    atual = origem;
    melhor_aresta[atual] = 0;
    while(!visitado[atual]){
        visitado[atual] = true;
        for(it = listas_adj[atual].begin(); it != listas_adj[atual].end(); it++){
            int destino_adj = it->destino, peso_adj = it->peso;
            if(!visitado[destino_adj] && peso_adj < melhor_aresta[destino_adj]){
                melhor_aresta[destino_adj] = peso_adj;
                pai[destino_adj] = atual;
            }
        }
        melhor_aresta_atual = INF;
        for(int i=0; i<vertices; i++){
            if(!visitado[i] && melhor_aresta[i] < melhor_aresta_atual){
                melhor_aresta_atual = melhor_aresta[i];
                atual = i;
            }
        }
    }
    int soma = 0;
    for(int i=0; i<vertices; i++){
        if(visitado[i]){
            soma += melhor_aresta[i];
        }
    }
    
    return soma;
    
}



int main(){
    list<Aresta> listas_adj[MAXV];
    
    int m, n, x, y, z, soma=0, economia=0;
    
    while(cin >> m >> n && m != 0 && n != 0){
        for(int i=0; i<m; i++ ){
            listas_adj[i].clear();
        }
        for(int i=0; i<n; i++){
            cin >> x >> y >> z;
            listas_adj[x].push_back({y, z});
            listas_adj[y].push_back({x, z});
            soma += z;
        }
        economia += soma - prim_lista(listas_adj, m, 0);
    }
    
    cout << economia << endl;
}