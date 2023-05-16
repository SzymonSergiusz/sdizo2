//
//  main.cpp
//  sdizo2
//
//  Created by Szymon Kluska on 14/05/2023.
//

#include <stdio.h>
#include "AdjListGraph.hpp"
#include "MSTAlgorithm.hpp"
#include <vector>
int main(int argc, char *argv[]) {
    
    AdjListGraph list = AdjListGraph(8, 16);
    std::vector<std::vector<int>> input = {{0, 1, 5}, {0, 3, 9}, {0, 6, 3}, {1, 2, 9}, {1, 4, 8}, {1, 5, 6}, {1, 7, 7}, {2, 3, 9}, {2, 4, 4}, {2, 6, 5}, {2, 7, 3}, {3, 6, 8}, {4, 5, 2}, {4, 6, 1}, {5, 6, 6}, {6, 7, 9}};

    for (auto i : input)
           list.addUndirected(i[0], i[1], i[2]);
    
    MSTAlgorithm mst;
    mst.kruskal(list);
    
    AdjMatrixGraph macierz = AdjMatrixGraph(8);

    for (auto i : input)
           macierz.addUndirected(i[0], i[1], i[2]);
    
    mst.prim(macierz);
}
