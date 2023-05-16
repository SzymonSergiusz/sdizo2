//
//  DisjointSet.hpp
//  sdizo2
//
//  Created by Szymon Kluska on 14/05/2023.
//

#ifndef DisjointSet_hpp
#define DisjointSet_hpp

#include <stdio.h>

class DisjointSet {
//    struct DSNode {
//        DSNode* parent;
//        int rank;
//    };
//private:
//    DSNode* nodes;
private:
    int* parent;
    int* rank;
public:
    DisjointSet(int n);
    
    int findSet(int x);
    void link(int x, int y);
    void union_(int x, int y);
};

#endif /* DisjointSet_hpp */
