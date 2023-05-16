//
//  AdjList.cpp
//  sdizo2
//
//  Created by Szymon Kluska on 14/05/2023.
//

#include "AdjListGraph.hpp"
#include <iostream>

AdjListGraph::AdjListGraph(int V, int E) : V(V), E(E){
    adj = new std::vector<std::pair<int, int>>[V];
};

AdjListGraph::AdjListGraph(int V) : V(V) {
    adj = new std::vector<std::pair<int, int>>[V];
};

void AdjListGraph::addUndirected(int src, int dest,int weight) {
    adj[src].push_back(std::make_pair(dest, weight));
    adj[dest].push_back(std::make_pair(src, weight));
}

void AdjListGraph::addDirected(int src, int dest,int weight) {
    adj[src].push_back(std::make_pair(dest, weight));
}

void AdjListGraph::toPrint() {
    std::cout << "\n";
    for (int u = 0; u < V; u++) {
        
        for (int v = 0; v < adj[u].size(); v++) {
            std::cout << u <<" -> " << adj[u].at(v).first << " : " <<adj[u].at(v).second;
            std::cout << "\n";
        }
    }
}
