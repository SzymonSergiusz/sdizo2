//
//  MST.cpp
//  sdizo2
//
//  Created by Szymon Kluska on 14/05/2023.
//

#include "MSTAlgorithm.hpp"
#include "queue"
#include "DisjointSet.hpp"
#include <iostream>
#include <functional>

struct EdgeComparator
{
    bool operator()(const Edge & a, const Edge & b)
    {
        return a.weight>b.weight;
    }
};

bool operator<(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

void MSTAlgorithm::kruskal(AdjListGraph graph) {
    std::priority_queue<Edge, std::vector<Edge>, EdgeComparator> pq;
    for (int i = 0; i < graph.edges.size(); i++) {
        pq.push(graph.edges.at(i));
        
    }
    AdjListGraph lista = AdjListGraph(graph.V, graph.E);
    DisjointSet set = DisjointSet(graph.V);
    int sum = 0;
    
    while (!pq.empty()) {
        auto edge = pq.top();
        pq.pop();
        
        if (set.findSet(edge.src) != set.findSet(edge.dest)) {
            set.union_(edge.src, edge.dest);
            sum += edge.weight;
            lista.addUndirected(edge.src, edge.dest, edge.weight);
        }
    }
    std::cout << "MST sum: " << sum;
}
void MSTAlgorithm::kruskal(AdjMatrixGraph graph) {
    std::priority_queue<Edge, std::vector<Edge>, EdgeComparator> pq;

    //macierz
    for (int i = 0; i < graph.V; i++) {
        for (int j = 0; j < graph.V; j++) {
            if (graph.matrix[i][j] != 0) {
                pq.push(Edge(i, j, graph.matrix[i][j]));
            }
        }
    }
    
    AdjMatrixGraph macierz = AdjMatrixGraph(graph.V);
    DisjointSet set = DisjointSet(graph.V);
    int sum = 0;
    
    while (!pq.empty()) {
        auto edge = pq.top();
        pq.pop();
        
        if (set.findSet(edge.src) != set.findSet(edge.dest)) {
            set.union_(edge.src, edge.dest);
            sum += edge.weight;
            macierz.addUndirected(edge.src, edge.dest, edge.weight);
        }
    }
    std::cout << "MST sum: " << sum;
    
}


void MSTAlgorithm::prim(AdjMatrixGraph graph) {
    AdjMatrixGraph macierz = AdjMatrixGraph(graph.V);
    int sum = 0;
    
    int currentEdge = 0;
    int selected[graph.V];
    for (int i = 0; i < graph.V; i++) {
        selected[i] = false;
    }
    
    selected[0] = true;
    
    while (currentEdge < graph.V - 1) {
        int min = INT_MAX;
        int u = 0;;
        int v = 0;
        
        for (int i = 0; i < graph.V; i++) {
            if (selected[i]) {
                for (int j = 0; j < graph.V; j++) {
                    if (!selected[j] && graph.matrix[i][j]) {
                        if (min > graph.matrix[i][j]) {
                            min = graph.matrix[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }
            }
        }
        
        selected[v] = true;
        currentEdge++;
        sum += min;
        macierz.addUndirected(u, v, min);
        
    }
    
    std::cout << "PRIM MST: " << sum <<"\n";
    macierz.print();

};
void MSTAlgorithm::prim(AdjListGraph graph) {
    
};

int MSTAlgorithm::minKey(int key[], bool mstSet[], int V)
{
    // Initialize min value
    int min = INT_MAX;
    int min_index = 0;
 
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
            
 
    return min_index;
}
