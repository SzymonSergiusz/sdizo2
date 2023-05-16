//
//  AdjList.cpp
//  sdizo2
//
//  Created by Szymon Kluska on 14/05/2023.
//

#include "AdjListGraph.hpp"

AdjListGraph::AdjListGraph(int V, int E) : V(V), E(E){};

void AdjListGraph::addUndirected(int u, int v, int w) {
    edges.push_back({u, v, w});
    edges.push_back({v, u, w});
}
void AdjListGraph::addDirected(int u, int v, int w) {
    edges.push_back({u, v, w});
}
