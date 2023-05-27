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
#include "EdgeList.hpp"

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

EdgeList MSTAlgorithm::kruskal(AdjListGraph graph) {
    EdgeList listaKrawedzi;
    std::priority_queue<Edge, std::vector<Edge>, EdgeComparator> pq;
    for (int i = 0; i < graph.V; i++) {
        for (int j = 0; j < graph.adj[i].size(); j++) {
            pq.push(Edge(i, graph.adj[i].at(j).first, graph.adj[i].at(j).second));
        }
    }
    
    DisjointSet set = DisjointSet(graph.V);
    int sum = 0;
    
    while (!pq.empty()) {
        auto edge = pq.top();
        pq.pop();
        
        if (set.findSet(edge.src) != set.findSet(edge.dest)) {
            set.union_(edge.src, edge.dest);
            sum += edge.weight;
            listaKrawedzi.addDirected(edge.src, edge.dest, edge.weight);
        }
    }
    mstVal = sum;
    return listaKrawedzi;

}

EdgeList MSTAlgorithm::kruskal(AdjMatrixGraph graph) {
    EdgeList listaKrawedzi;
    std::priority_queue<Edge, std::vector<Edge>, EdgeComparator> pq;

    for (int i = 0; i < graph.V; i++) {
        for (int j = 0; j < graph.V; j++) {
            if (graph.matrix[i][j] != 0) {
                pq.push(Edge(i, j, graph.matrix[i][j]));
            }
        }
    }
    
    
    DisjointSet set = DisjointSet(graph.V);
    int sum = 0;
    
    while (!pq.empty()) {
        auto edge = pq.top();
        pq.pop();
        
        if (set.findSet(edge.src) != set.findSet(edge.dest)) {
            set.union_(edge.src, edge.dest);
            sum += edge.weight;
            listaKrawedzi.addDirected(edge.src, edge.dest, edge.weight);
        }
    }
    mstVal = sum;
    return listaKrawedzi;

}


EdgeList MSTAlgorithm::prim(AdjMatrixGraph graph) {
    EdgeList listaKrawedzi;
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
        listaKrawedzi.addDirected(u, v, min);
        
    }
    mstVal = sum;
    return listaKrawedzi;

};


EdgeList MSTAlgorithm::prim(AdjListGraph graph) {
    EdgeList listaKrawedzi;
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
                for (int j = 0; j < graph.adj[i].size(); j++) {
                    if (!selected[graph.adj[i].at(j).first] && graph.adj[i].at(j).second) {
                        if (min > graph.adj[i].at(j).second) {
                            min = graph.adj[i].at(j).second;
                            u = i;
                            v = graph.adj[i].at(j).first;
                        }
                    }
                }
            }
        }
        
        selected[v] = true;
        currentEdge++;
        sum += min;
        listaKrawedzi.addDirected(u, v, min);
    }
    
    mstVal = sum;
    return listaKrawedzi;
};

