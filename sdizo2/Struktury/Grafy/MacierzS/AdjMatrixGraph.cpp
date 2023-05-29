//
//  AdjMatrixGraph.cpp
//  sdizo2
//
//  Created by Szymon Kluska on 14/05/2023.
//

#include "AdjMatrixGraph.hpp"
#include "DisjointSet.hpp"
#include <iostream>
#include <fstream>
#include <random>


#include <vector>
#include <algorithm>

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
void AdjMatrixGraph::addDirected(int u, int v, int w) {
    matrix[u][v] = w;
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

void AdjMatrixGraph::loadFromFileDijkstra(std::string fileName) {
    std::ifstream inputFile(fileName);
    
    int newE;
    inputFile >> newE;
    int newV;
    inputFile >> newV;
    int src;
    inputFile >> src;
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
            
            
            addDirected(u, v, w);
        }
        
        inputFile.close();
    } else {
        std::cout << "Nie odnaleziono pliku " <<fileName <<std::endl;
    }
    
    
}
void AdjMatrixGraph::generateGraphDirected(int nV, float density) {
    V = nV;

    matrix = new int*[V];
    for (int i = 0; i < V; i++) {
        matrix[i] = new int[V];

        for (int j = 0; j < V; j++) {
            matrix[i][j] = 0;
        }
    }


    int edges100perc = int((1.0 * float(nV*(nV-1)))/2);
    
    int doUsuniecia = int(((1.0 - density) * float(nV*(nV-1)))/2);
//    std::cout << "Do usuniecia " << doUsuniecia <<"\n";

    
//    int nEdges = int((density * float(nV*(nV-1)))/2);
    int nEdges = edges100perc - doUsuniecia;

//    std::cout << "Liczba krawedzi " << nEdges <<"\n";

    int countEdges = 0;
    for (int i = 0; i < V-1; i++) {

        if (i+1 == V-1) {
            addDirected(i, 0, random(20)+1);
        }else {
            addDirected(i, i+1, random(20)+1);
        }
        countEdges++;

    }


    while (nEdges >= countEdges) {

        int src = random(nV-1);
        int dest = random(nV-1);

        while (src == dest) {
            src = random(nV-1);
            dest = random(nV-1);
        }
        addDirected(src, dest, random(nV)+1);
//        std::cout << "cE: " << countEdges <<"\n";
        countEdges++;
    }
    E = nEdges;
}

void AdjMatrixGraph::generateGraphUndirected(int nV, float density) {
    V = nV;
    
    matrix = new int*[V];
    for (int i = 0; i < V; i++) {
        matrix[i] = new int[V];
        
        for (int j = 0; j < V; j++) {
            matrix[i][j] = 0;
        }
    }
    
    
    int edges100perc = int((1.0 * float(nV*(nV-1)))/2);
    
    int doUsuniecia = int(((1.0 - density) * float(nV*(nV-1)))/2);
//    std::cout << "Do usuniecia " << doUsuniecia <<"\n";

    
//    int nEdges = int((density * float(nV*(nV-1)))/2);
    int nEdges = edges100perc - doUsuniecia;
    
//    std::cout << "Liczba krawedzi " << nEdges <<"\n";
    
    int countEdges = 0;
    for (int i = 0; i < V-1; i++) {
        
        if (i+1 == V-1) {
            addUndirected(i, 0, random(20)+1);
        } else {
            addUndirected(i, i+1, random(20)+1);
        }
        countEdges++;
    }
    
    while (nEdges >= countEdges) {
        countEdges++;
        int src = random(nV-1);
        int dest = random(nV-1);

        while (src == dest) {
            src = random(nV-1);
            dest = random(nV-1);
        }
//        std::cout << "cE: " << countEdges <<"\n";
        
        addUndirected(src, dest, random(20)+1);
    }
    E = nEdges;
}


int AdjMatrixGraph::random(int doIlu) {
    std::random_device randDev;
    std::mt19937 rng(randDev());
    std::uniform_int_distribution<> distr(0, doIlu);
    
    return distr(rng);
}
