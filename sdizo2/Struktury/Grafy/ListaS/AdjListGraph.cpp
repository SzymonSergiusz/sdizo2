//
//  AdjList.cpp
//  sdizo2
//
//  Created by Szymon Kluska on 14/05/2023.
//

#include "AdjListGraph.hpp"
#include <iostream>
#include <fstream>
#include <random>

AdjListGraph::AdjListGraph(int V, int E) : V(V), E(E){
    adj = new std::vector<std::pair<int, int>>[V];
};

AdjListGraph::AdjListGraph(int V) : V(V) {
    adj = new std::vector<std::pair<int, int>>[V];
};

void AdjListGraph::addUndirected(int src, int dest,int weight) {
    adj[src].push_back(std::make_pair(dest, weight));
    adj[dest].push_back(std::make_pair(src, weight));
}

void AdjListGraph::addDirected(int src, int dest,int weight) {
    adj[src].push_back(std::make_pair(dest, weight));
}

void AdjListGraph::toPrint() {
    std::cout << "\n";
    for (int u = 0; u < V; u++) {
        
        for (int v = 0; v < adj[u].size(); v++) {
            std::cout << u <<" -> " << adj[u].at(v).first << " : " <<adj[u].at(v).second;
            std::cout << "\n";
        }
    }
}

void AdjListGraph::loadFromFile(std::string fileName) {
    std::ifstream inputFile(fileName);
    
    int newE;
    inputFile >> newE;
    int newV;
    inputFile >> newV;
    
    V = newV;
    adj = new std::vector<std::pair<int, int>>[V];

    
    if (inputFile.is_open()) {
        int u;
        int v;
        int w;
        
        while (inputFile >> u and inputFile >> v and inputFile >> w) {
            addUndirected(u, v, w);
        }
        
        inputFile.close();
    } else {
        std::cout << "Nie odnaleziono pliku " <<fileName <<std::endl;
    }
    
}

void AdjListGraph::loadFromFileDijkstra(std::string fileName) {
    std::ifstream inputFile(fileName);
    
    int newE;
    inputFile >> newE;
    int newV;
    inputFile >> newV;
    int src;
    inputFile >> src;
    V = newV;
    adj = new std::vector<std::pair<int, int>>[V];

    
    if (inputFile.is_open()) {
        int u;
        int v;
        int w;
        
        while (inputFile >> u and inputFile >> v and inputFile >> w) {
            addDirected(u, v, w);
        }
        
        inputFile.close();
    } else {
        std::cout << "Nie odnaleziono pliku " <<fileName <<std::endl;
    }
    
}

void AdjListGraph::generateGraphDirected(int nV, float density) {
    V = nV;
    adj = new std::vector<std::pair<int, int>>[V];
   
    
    int nEdges = int((density * float(nV*(nV-1)))/2);
    
    std::cout << "Liczba krawedzi " << nEdges <<"\n";
    
    int countEdges = 0;
    for (int i = 0; i < V-1; i++) {
        
        if (i+1 == V-1) {
            addDirected(i, 0, random(20)+1);
        } else {
            addDirected(i, i+1, random(20)+1);
        }
        countEdges++;
    }
    
    while (nEdges > countEdges) {
        countEdges++;
        
        int src = random(nV-1);
        int dest = random(nV-1);

        while (src == dest) {
            src = random(nV-1);
            dest = random(nV-1);
        }
        addDirected(src, dest, random(nV)+1);
    }
    E = nEdges;
}

void AdjListGraph::generateGraphUndirected(int nV, float density) {
    V = nV;
    adj = new std::vector<std::pair<int, int>>[V];
    
    
    int nEdges = int((density * float(nV*(nV-1)))/2);
    
    std::cout << "Liczba krawedzi " << nEdges <<"\n";
    
    int countEdges = 0;
    for (int i = 0; i < V-1; i++) {
        
        if (i+1 == V-1) {
            addUndirected(i+1, 0, random(20)+1);
        } else {
            addUndirected(i, i+1, random(20)+1);
        }
        countEdges++;
    }
    
    while (nEdges > countEdges) {
        countEdges++;
        
        int src = random(nV-1);
        int dest = random(nV-1);

        while (src == dest) {
            src = random(nV-1);
            dest = random(nV-1);
        }
        addUndirected(src, dest, random(20)+1);
    }
    E = nEdges;
}

int AdjListGraph::random(int doIlu) {
    std::random_device randDev;
    std::mt19937 rng(randDev());
    std::uniform_int_distribution<> distr(0, doIlu);
    
    return distr(rng);
}
