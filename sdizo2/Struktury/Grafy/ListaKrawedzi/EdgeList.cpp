//
//  EdgeList.cpp
//  sdizo2
//
//  Created by Szymon Kluska on 25/05/2023.
//

#include "EdgeList.hpp"
#include "Edge.hpp"
#include <iostream>
void EdgeList::addDirected(int src, int dest, int w) {
    list.push_back(Edge(src, dest, w));
}

void EdgeList::addUndirected(int src, int dest, int w) {
    list.push_back(Edge(src, dest, w));
    list.push_back(Edge(dest, src, w));
}

void EdgeList::print() {
    for (Edge el : list) {
        std::cout <<"("<< el.src << ", " << el.dest << ", " <<el.weight << ")\n";
    }
}
