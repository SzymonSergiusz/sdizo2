//
//  AdjMatrixGraph.cpp
//  sdizo2
//
//  Created by Szymon Kluska on 14/05/2023.
//

#include "AdjMatrixGraph.hpp"
#include <iostream>
#include <fstream>

AdjMatrixGraph::AdjMatrixGraph(int V) : V(V) {
    
    matrix = new int*[V];
    for (int i = 0; i < V; i++) {
        matrix[i] = new int[V];
        
        for (int j = 0; j < V; j++) {
            matrix[i][j] = 0;
        }
    }
}

void AdjMatrixGraph::addUndirected(int u, int v, int w) {
    matrix[u][v] = w;
    matrix[v][u] = w;
}

void AdjMatrixGraph::removeUndirected(int u, int v) {
    matrix[u][v] = 0;
    matrix[v][u] = 0;
}

void AdjMatrixGraph::print() {
    std::cout << "    ";
    for (int i = 0; i < V; i++) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    for (int i = 0; i < V; i++) {
      std::cout << i << " : ";
      for (int j = 0; j < V; j++)
        std::cout << matrix[i][j] << " ";
      std::cout << "\n";
    }
}


void AdjMatrixGraph::loadFromFile(std::string fileName) {
    std::ifstream inputFile(fileName);
    
    int newE;
    inputFile >> newE;
    int newV;
    inputFile >> newV;
    V = newV;
    
    matrix = new int*[V];
    for (int i = 0; i < V; i++) {
        matrix[i] = new int[V];
        
        for (int j = 0; j < V; j++) {
            matrix[i][j] = 0;
        }
    }
    
    if (inputFile.is_open()) {
        int u;
        int v;
        int w;
        
        while (inputFile >> u && inputFile >> v && inputFile >> w) {
            
            
            addUndirected(u, v, w);
        }
        
        inputFile.close();
    } else {
        std::cout << "Nie odnaleziono pliku " <<fileName <<std::endl;
    }
    
}

