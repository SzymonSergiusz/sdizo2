//
//  AdjMatrixGraph.hpp
//  sdizo2
//
//  Created by Szymon Kluska on 14/05/2023.
//

#ifndef AdjMatrixGraph_hpp
#define AdjMatrixGraph_hpp

#include <stdio.h>
#include <string>


class AdjMatrixGraph {
public:
    int V; //liczba wierzchołków
    int** matrix;
    AdjMatrixGraph(int V);
    void addUndirected(int u, int v,int w);
    void addDirected(int u, int v, int w);
    void removeUndirected(int u, int v);
    void removeDirected(int u, int v);
    
    void print();
    
    void loadFromFile(std::string fileName);
    
};
#endif /* AdjMatrixGraph_hpp */
