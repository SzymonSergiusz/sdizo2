//
//  MST.hpp
//  sdizo2
//
//  Created by Szymon Kluska on 14/05/2023.
//

#ifndef MSTAlgorithm_hpp
#define MSTAlgorithm_hpp

#include <stdio.h>
#include "AdjListGraph.hpp"
#include "AdjMatrixGraph.hpp"
#include "EdgeList.hpp"
class MSTAlgorithm {
public:
    
    int mstVal = 0;
    EdgeList kruskal(AdjMatrixGraph graph);
    EdgeList kruskal(AdjListGraph graph);
    EdgeList prim(AdjMatrixGraph graph);
    EdgeList prim(AdjListGraph graph);
    
    
};

#endif /* MST_hpp */
