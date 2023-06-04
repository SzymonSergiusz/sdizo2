//
//  ShortestPath.cpp
//  sdizo2
//
//  Created by Szymon Kluska on 25/05/2023.
//

#include "ShortestPath.hpp"
#include "Edge.hpp"
#include <queue>
#include <iostream>
#include <vector>

class Verticle {
public:
    int u, d;
    Verticle(int u, int d) :u(u), d(d){};
};

struct VertComparator
{
    bool operator()(const Verticle &a, const Verticle &b)
    {
        return a.d>b.d;
    }
};

bool operator<(const Verticle& v1, const Verticle& v2) {
    return v1.d < v2.d;
}

void ShortestPath::dijkstra(AdjListGraph graph, int src) {
    std::priority_queue<Verticle, std::vector<Verticle>, VertComparator> pq;
    
    distance = new int[graph.V];
    parent = new int[graph.V];
    for (int v = 0; v < graph.V; v++) {
        distance[v] = INT_MAX;
        parent[v] = -1;
    }
    distance[src] = 0;
    pq.push(Verticle(src, distance[src]));
    
    
    while (!pq.empty()) {
        
        Verticle vert = pq.top();
        pq.pop();
        int u = vert.u;
        
        
        for (auto pair : graph.adj[u]) {
            int v = pair.first;
            int w = pair.second;
            if (distance[v] > distance[u] + w) {
                
                
                distance[v] = distance[u] + w;
                parent[v] = u;
                pq.push(Verticle(v, distance[v]));
                
            }
        }
    }
    distSize =graph.V;
}

void ShortestPath::dijkstra(AdjMatrixGraph graph, int src) {
    std::priority_queue<Verticle, std::vector<Verticle>, VertComparator> pq;
    
    distance = new int[graph.V];
    parent = new int[graph.V];

    for (int v = 0; v < graph.V; v++) {
        distance[v] = INT_MAX;
        parent[v] = -1;
    }
    distance[src] = 0;
    pq.push(Verticle(src, distance[src]));
    
    
    while (!pq.empty()) {
        
        Verticle vert = pq.top();
        pq.pop();
        int u = vert.u;
        
        
        for (int v = 0; v < graph.V; v++) {
            int w = graph.matrix[u][v];
            
            if ( w != 0 && distance[v] > distance[u] + w) {
                parent[v] = u;
                distance[v] = distance[u] + w;
                pq.push(Verticle(v, distance[v]));
                
            }
        }
    }
    distSize =graph.V;
}

bool ShortestPath::belford(AdjMatrixGraph graph, int src) {
    distSize = graph.V;
    distance = new int[graph.V];
    parent = new int[graph.V];
    for (int v = 0; v < graph.V; v++) {
        distance[v] = INT_MAX;
        parent[v] = -1;
    }
    distance[src] = 0;

    for (int i = 0; i < graph.V-1 ; i++) {
        for (int u = 0; u < graph.V; u++) {
            for (int v = 0; v < graph.V; v++) {
                int w = graph.matrix[u][v];
                
                if (w != 0 && distance[u] != INT_MAX && distance[v] > distance[u] + w) {
                    distance[v] = distance[u] + w;
                    parent[v] = u;
                }
            }
        }
    }

    for (int u = 0; u < graph.V; u++) {
        for (int v = 0; v < graph.V; v++) {
            int w = graph.matrix[u][v];
            if (w != 0 && distance[u] != INT_MAX && distance[v] > distance[u] + w) {
                distSize = -1;
                return false;

            }
        }
    }
    return true;
}


bool ShortestPath::belford(AdjListGraph graph, int src) {
    distSize = graph.V;
    distance = new int[graph.V];
    parent = new int[graph.V];
    for (int v = 0; v < graph.V; v++) {
        distance[v] = INT_MAX;
        parent[v] = -1;
    }
    distance[src] = 0;
    
    for (int i = 0; i < graph.V-1 ; i++) {
        for (int u = 0; u < graph.V; u++) {
            for (auto pair : graph.adj[u]) {
                int v = pair.first;
                int w = pair.second;

                if (distance[u] != INT_MAX && distance[v] > distance[u] + w) {
                    distance[v] = distance[u] + w;
                    parent[v] = u;
                }
            }
        }
    }

    for (int u = 0; u < graph.V; u++) {
        for (auto pair : graph.adj[u]) {
            int v = pair.first;
            int w = pair.second;

            if (distance[u] != INT_MAX && distance[v] > distance[u] + w) {
                distSize = -1;
                return false;
            }
        }
    }
    return true;
}

void ShortestPath::print() {
    
    std::cout << "Wierzchołek   Dystans od 0\n";
    for (int i = 0; i < distSize; i++) {
        std::cout << i << "             " <<  distance[i] << "\n";
        
        std::cout <<"Droga: ";
        
        std::string s = std::to_string(i);
        int v = i;
        while (parent[v] > -1) {
            s = std::to_string(parent[v])+ " -> "+ s;
            v = parent[v];
        }
        std::cout << s <<"\n______________________________\n";

    }
}

