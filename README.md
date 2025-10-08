# Resumo de Teoria dos Grafos

## Conceitos Fundamentais
1. **Estruturas Básicas**
   - Grafo: conjunto de vértices e arestas
   - Representações:
     ```cpp
     // Lista de Adjacência
     list<Aresta> listas_adj[]
     
     // Matriz de Adjacência
     int matriz_adj[MAXV][MAXV]
     ```

2. **Algoritmo de Prim (MST)**
   - **Objetivo**: Encontrar árvore geradora mínima
   - **Estruturas**:
     ```cpp
     bool visitado[]        // Vértices na MST
     int melhor_aresta[]    // Menor peso por vértice
     int pai[]             // Estrutura da MST
     ```
   - **Passos**:
     1. Inicializar vértices como não visitados
     2. Começar da origem
     3. Para cada não visitado:
        - Marcar como visitado
        - Atualizar custos dos vizinhos
        - Escolher próximo com menor custo

3. **Algoritmo de Dijkstra**
   - **Objetivo**: Menor caminho entre vértices
   - **Estruturas**:
     ```cpp
     int melhor_distancia[] // Menor distância
     int pai[]             // Caminho mínimo
     bool visitado[]       // Processados
     ```
   - **Passos**:
     1. Inicializar distâncias = INF
     2. Origem com distância 0
     3. Para cada não visitado:
        - Marcar visitado
        - Atualizar distâncias (relaxamento)
        - Escolher próximo mais próximo

## Diferenças Cruciais
- **Prim**:
  - Soma pesos das arestas na árvore
  - Conecta todos os vértices
  - Gera uma árvore

- **Dijkstra**:
  - Soma pesos no caminho
  - Encontra caminho entre dois pontos
  - Gera caminhos mínimos

## Pontos de Atenção
1. **Inicializações**:
   ```cpp
   #define INF 9999
   #define MAXV 100000
   // Sempre inicializar:
   visitado[] = false
   distancia[] = INF
   pai[] = -1
   ```

2. **Atualizações**:
   ```cpp
   // Prim
   melhor_aresta[v] = peso_aresta
   
   // Dijkstra
   melhor_distancia[v] = dist_atual + peso_aresta
   ```

3. **Complexidade**:
   - Matriz: O(V²)
   - Lista + Heap: O(E log V)

## Casos Especiais
1. **Grafo Desconexo**:
   - Verificar se encontrou solução
   - Tratar INF adequadamente

2. **Restrições**:
   - IDH mínimo: marcar como visitado
   - Verificar condições antes de relaxar

## Checklist para Implementação
- [ ] Inicialização correta das estruturas
- [ ] Tratamento de casos especiais
- [ ] Verificação de conectividade
- [ ] Cálculo correto do resultado final
- [ ] Tratamento de entrada/saída

## Dicas para Prova
1. Faça o passo a passo no papel
2. Verifique inicializações
3. Trate casos especiais
4. Entenda as diferenças entre algoritmos
5. Pratique as variações dos problemas
