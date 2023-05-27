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
    AdjListGraph(int V);
    AdjListGraph(int V, int E);
    
    std::vector<std::pair<int, int>> *adj;
    
    void addUndirected(int src, int dest,int weight);
    void addDirected(int src, int dest,int weight);
    
    void toPrint();
    void loadFromFile(std::string fileName);
    void loadFromFileDijkstra(std::string fileName);
    
    void generateGraphDirected(int V, float density);
    void generateGraphUndirected(int V, float density);

    int random(int doIlu);
};

#endif /* AdjList_hpp */
