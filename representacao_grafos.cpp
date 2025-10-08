#define MAXV 1000
#include<iostream>
#include<list>
using namespace std;

struct Aresta{
	int destino, peso;
};

int main(){
	int matriz_adj[MAXV][MAXV];
	int vertices, arestas, origem, destino, peso;
	cin >> vertices >> arestas;
	for(int i=0; i<vertices; i++){
		for(int j=0; j<vertices; j++){
			matriz_adj[i][j] = -1;
		}
	}
	for(int i=0; i<arestas; i++){
		cin >> origem >> destino >> peso;
		origem--;destino--;
		matriz_adj[origem][destino] = peso;
		//matriz_adj[destino][origem] = peso;
	}
	
	for(int i=0; i<vertices; i++){
		cout << i+1 << ": ";
		for(int j=0; j<vertices; j++){
			cout << matriz_adj[i][j] << " ";
		}
		cout << endl;
	}
	
	list<Aresta> listas_adj[MAXV];
	
	cin >> vertices >> arestas;
	
	for(int i=0; i < arestas; i++){
		cin >> origem >> destino >> peso;
		listas_adj[origem].push_back({destino, peso});
		//listas_adj[destino].push_back({origem, peso});
	}
	
	list<Aresta>::iterator it;	
	for(int i=0; i<vertices; i++){
		cout << i << ": ";
		for(it = listas_adj[i].begin(); it != listas_adj[i].end(); it++){
			cout << "(" << it->destino << ", " << it->peso << ") ";
		}
		cout << endl;
	}
	
	return 0;
	
}