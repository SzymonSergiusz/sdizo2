//
//  AdjList.hpp
//  sdizo2
//
//  Created by Szymon Kluska on 14/05/2023.
//

#ifndef AdjList_hpp
#define AdjList_hpp
#include <vector>
#include <stdio.h>
#include "Edge.hpp"
class AdjListGraph {
public:
    int V;
    int E;
    
    AdjListGraph(int V, int E);
    
    std::vector<Edge> edges;
    
    
    
    void addUndirected(int u, int v,int w);
    void addDirected(int u, int v, int w);
    void removeUndirected(int u, int v);
    void removeDirected(int u, int v);
    void toString();
    
};

#endif /* AdjList_hpp */
