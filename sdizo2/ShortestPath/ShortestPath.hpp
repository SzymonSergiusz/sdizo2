//
//  ShortestPath.hpp
//  sdizo2
//
//  Created by Szymon Kluska on 25/05/2023.
//

#ifndef ShortestPath_hpp
#define ShortestPath_hpp

#include <stdio.h>
#include "EdgeList.hpp"
#include "AdjListGraph.hpp"
#include "AdjMatrixGraph.hpp"
class ShortestPath {
public:
    int* distance;
    int* parent;
    int distSize;
    void dijkstra(AdjListGraph graph, int src);
    void dijkstra(AdjMatrixGraph graph, int src);
    
    bool belford(AdjMatrixGraph graph, int src);
    bool belford(AdjListGraph graph, int src);
    
    void print();
};


#endif /* ShortestPath_hpp */
