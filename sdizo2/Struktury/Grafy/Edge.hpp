//
//  Edge.hpp
//  sdizo2
//
//  Created by Szymon Kluska on 14/05/2023.
//

#ifndef Edge_hpp
#define Edge_hpp

#include <stdio.h>
class Edge {
public:
    int src, dest, weight;
    Edge(){};
    Edge(int src, int dest, int weight) : src(src), dest(dest), weight(weight){};
};
#endif /* Edge_hpp */
