//
//  DisjointSet.cpp
//  sdizo2
//
//  Created by Szymon Kluska on 14/05/2023.
//

#include "DisjointSet.hpp"

DisjointSet::DisjointSet(int n) {
    parent = new int[n];
    rank = new int[n];
    
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
        rank[i] = 1;
    }
}

int DisjointSet::findSet(int x) {
    if (parent[x] == -1) return x;
    return parent[x] = findSet(parent[x]);
}

void DisjointSet::link(int x, int y) {
        int set1 = findSet(x);
        int set2 = findSet(y);
        if (set1 != set2) {
            if (rank[set1] < rank[set2]) {
                parent[set1] = set2;
            } else if (rank[set1] > rank[set2]) {
                parent[set2] = set1;
            } else {
                parent[set2] = set1;
                rank[set1] += 1;
            }
        }
}

void DisjointSet::union_(int x, int y) {
    link(findSet(x), findSet(y));
}

