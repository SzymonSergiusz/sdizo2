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
    int E;
    int** matrix;
    AdjMatrixGraph(int V);
    void addUndirected(int u, int v,int w);
    void addDirected(int u, int v, int w);
    void removeUndirected(int u, int v);
    void removeDirected(int u, int v);
    
    void print();
    
    void loadFromFile(std::string fileName);
    void loadFromFileDijkstra(std::string fileName);
    
    void generateGraphDirected(int V, float density);
    void generateGraphUndirected(int V, float density);
    
    
    int random(int doIlu);
};
#endif /* AdjMatrixGraph_hpp */
