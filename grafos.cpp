#define MAXV 1000
#define INF 9999
#include<iostream>
#include<list>
using namespace std;

struct Aresta{
	int destino, peso;
};

void dfs_lista(list<Aresta> listas_adj[], bool visitado[], int vertices, int atual){
    visitado[atual] = true;
    cout << atual << " ";
    list<Aresta>::iterator it;
    for(it = listas_adj[atual].begin(); it != listas_adj[atual].end(); it++){
        if(!visitado[it->destino]){
            dfs_lista(listas_adj, visitado, vertices, it->destino);
        }
    }
}

void dfs_matriz(int matriz_adj[MAXV][MAXV], bool visitado[], int vertices, int atual){
    visitado[atual] = true;
    cout << atual << " ";
    for(int j=0; j<vertices; j++){
        if(!visitado[j] && matriz_adj[atual][j] != -1){
            dfs_matriz(matriz_adj, visitado, vertices, j);
        }
    }
}


int dijkstra_lista(list<Aresta> listas_adj[], int vertices, int origem, int destino){
    bool visitado[vertices];
    int atual, melhor_distancia_atual, pai[vertices], melhor_distancia[vertices];

    for(int i=0; i<vertices; i++){
        visitado[i] = false;
        pai[i] = -1;
        melhor_distancia[i] = INF;
    }
    list<Aresta>::iterator it;
    atual = origem;
    melhor_distancia[atual] = 0;
    while(!visitado[atual]){
        visitado[atual] = true;
        for(it = listas_adj[atual].begin(); it != listas_adj[atual].end(); it++){
            if(!visitado[it->destino]){
                if( it->peso + melhor_distancia[atual] < melhor_distancia[it->destino]){
                    melhor_distancia[it->destino] = it->peso + melhor_distancia[atual];
                    pai[it->destino] = atual;
                }
            }
        }
        melhor_distancia_atual = INF;
        for(int i=0; i<vertices; i++){
            if(!visitado[i] && melhor_distancia[i] < melhor_distancia_atual){
                melhor_distancia_atual = melhor_distancia[i];
                atual = i;
            }
        }
    }
    atual = destino;
    while(pai[atual] != -1){
        cout << atual << " <- ";
        atual = pai[atual];
    }
    cout << atual << endl;
    return melhor_distancia[destino];

}

int dijkstra_matriz(int matriz_adj[MAXV][MAXV], int vertices, int origem, int destino){
    bool visitado[vertices];
    int atual, melhor_distancia_atual, pai[vertices], melhor_distancia[vertices];

    for(int i=0; i<vertices; i++){
        visitado[i] = false;
        pai[i] = -1;
        melhor_distancia[i] = INF;
    }

    atual = origem;
    melhor_distancia[atual] = 0;
    while(!visitado[atual]){
        visitado[atual] = true;
        for(int j=0; j<vertices; j++){
            if(!visitado[j] && matriz_adj[atual][j] != -1){
                if(matriz_adj[atual][j] + melhor_distancia[atual] < melhor_distancia[j]){
                    melhor_distancia[j] = matriz_adj[atual][j] + melhor_distancia[atual];
                    pai[j] = atual;
                }
            }
        }
        melhor_distancia_atual = INF;
        for(int i=0; i<vertices; i++){
            if(!visitado[i] && melhor_distancia[i] < melhor_distancia_atual){
                melhor_distancia_atual = melhor_distancia[i];
                atual = i;
            }
        }
    }
    atual = destino;
    while(pai[atual] != -1){
        cout << atual << " <- ";
        atual = pai[atual];
    }
    cout << atual << endl;
    return melhor_distancia[destino];

}

int prim_matriz(int matriz_adj[MAXV][MAXV], int vertices, int origem){
    bool visitado[vertices];
    int atual, melhor_peso_atual, pai[vertices], melhor_peso[vertices];

    for(int i=0; i<vertices; i++) {
        visitado[i] = false;
        pai[i] = -1;
        melhor_peso[i] = INF;
    }

    atual = origem;
    melhor_peso[origem] = 0;

    while(!visitado[atual]){
        visitado[atual] = true;
        for(int j=0; j < vertices; j++){
            int destino = j, peso = matriz_adj[atual][j];
            if(!visitado[destino] && matriz_adj[atual][j] != -1  && peso < melhor_peso[destino]){
                melhor_peso[destino] = peso;
                pai[destino] = atual;
            }
        }
        melhor_peso_atual = INF;
        for(int i=0; i<vertices; i++){
            if(!visitado[i] && melhor_peso[i] < melhor_peso_atual){
                melhor_peso_atual = melhor_peso[i];
                atual = i;
            }
        }
    }
    melhor_peso_atual = 0;
    for(int i=0; i<vertices; i++){
        if(visitado[i])
            melhor_peso_atual += melhor_peso[i];
    }
    return melhor_peso_atual;
}


int prim_lista(list<Aresta> listas_adj[], int vertices, int origem){
    bool visitado[vertices];
    int atual, melhor_peso_atual, pai[vertices], melhor_peso[vertices];

    for(int i=0; i<vertices; i++) {
        visitado[i] = false;
        pai[i] = -1;
        melhor_peso[i] = INF;
    }

    atual = origem;
    melhor_peso[origem] = 0;

    list<Aresta>::iterator it;

    while(!visitado[atual]){
        visitado[atual] = true;
        for(it = listas_adj[atual].begin(); it != listas_adj[atual].end(); it++){
            int destino = it->destino, peso = it->peso;
            if(!visitado[destino] && peso < melhor_peso[destino]){
                melhor_peso[destino] = peso;
                pai[destino] = atual;
            }
        }
        melhor_peso_atual = INF;
        for(int i=0; i<vertices; i++){
            if(!visitado[i] && melhor_peso[i] < melhor_peso_atual){
                melhor_peso_atual = melhor_peso[i];
                atual = i;
            }
        }
    }
    melhor_peso_atual = 0;
    for(int i=0; i<vertices; i++){
        if(visitado[i])
            melhor_peso_atual += melhor_peso[i];
    }
    return melhor_peso_atual;
}


void bfs_matriz(int matriz_adj[MAXV][MAXV], int vertices, int origem){
    bool visitado[vertices];
    int atual;
    list<int> fila_visitacao;

    for(int i=0; i<vertices; i++) visitado[i] = false;

    fila_visitacao.push_back(origem);
    visitado[origem] = true;
    cout << origem+1 << " ";

    while(!fila_visitacao.empty()){
        atual = fila_visitacao.front();
        for(int j=0; j<vertices; j++){
            if(matriz_adj[atual][j] != -1 && !visitado[j]){
                fila_visitacao.push_back(j);
                visitado[j] = true;
                cout << j+1 << " ";
            }
        }
        fila_visitacao.pop_front();
    }
    cout << endl;
    return;
}

int main(){
// 	int matriz_adj[MAXV][MAXV];
	int vertices, arestas, origem, destino, peso;
// 	cin >> vertices >> arestas;
// 	for(int i=0; i<vertices; i++){
// 		for(int j=0; j<vertices; j++){
// 			matriz_adj[i][j] = -1;
// 		}
// 	}
// 	for(int i=0; i<arestas; i++){
// 		cin >> origem >> destino >> peso;
// 		origem--;destino--;
// 		matriz_adj[origem][destino] = peso;
// 		matriz_adj[destino][origem] = peso;
// 	}

// 	for(int i=0; i<vertices; i++){
// 		cout << i+1 << ": ";
// 		for(int j=0; j<vertices; j++){
// 			cout << matriz_adj[i][j] << " ";
// 		}
// 		cout << endl;
// 	}

// 	bfs_matriz(matriz_adj, vertices, 0);

	list<Aresta> listas_adj[MAXV];

	cin >> vertices >> arestas;

	for(int i=0; i < arestas; i++){
		cin >> origem >> destino >> peso;
		origem--; destino--;
		listas_adj[origem].push_back({destino, peso});
		listas_adj[destino].push_back({origem, peso});
	}

	list<Aresta>::iterator it;
	for(int i=0; i<vertices; i++){
		cout << i << ": ";
		for(it = listas_adj[i].begin(); it != listas_adj[i].end(); it++){
			cout << "(" << it->destino+1 << ", " << it->peso << ") ";
		}
		cout << endl;
	}

	cout << prim_lista(listas_adj, vertices, 0) << endl;

	cout << dijkstra_lista(listas_adj, vertices, 0, 4) << endl;

	bool visitado[vertices];

	dfs_lista(listas_adj, visitado, vertices, 5);

	cout << endl;
	
	return 0;
	
}