//
//  EdgeList.hpp
//  sdizo2
//
//  Created by Szymon Kluska on 25/05/2023.
//

#ifndef EdgeList_hpp
#define EdgeList_hpp

#include <stdio.h>
#include "Edge.hpp"
#include <vector>
class EdgeList {
public:
    std::vector<Edge> list;
    void addDirected(int src, int dest, int w);
    void addUndirected(int src, int dest, int w);
    void print();
};

#endif /* EdgeList_hpp */
