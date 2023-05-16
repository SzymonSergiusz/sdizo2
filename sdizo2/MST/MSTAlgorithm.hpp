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

class MSTAlgorithm {
public:
    void kruskal(AdjMatrixGraph graph);
    void kruskal(AdjListGraph graph);
    void prim(AdjMatrixGraph graph);
    void prim(AdjListGraph graph);
    
    
};

#endif /* MST_hpp */
