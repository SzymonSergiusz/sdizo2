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
#include <iostream>
using namespace std;

void displayMenu(string info)
{
    cout << endl;
    cout << info << endl;
    cout << "1.Wczytaj z pliku" << endl;
    cout << "2.Prim" << endl;
    cout << "3.Kruskal" << endl;
    cout << "5.Utworz losowo" << endl;
    cout << "6.Wyswietl" << endl;
    cout << "7.Test (pomiary)" << endl;
    cout << "0.Powrot do menu" << endl;
    cout << "Podaj opcje:";
}
AdjListGraph adjList(0);
AdjMatrixGraph adjMatrix(0);
void menu_mst() {
    char option;
    string fileName;
    MSTAlgorithm mst;
    do{
        displayMenu("--- MST ---");
        cin >> option;
        cout << endl;
        switch (option) {
            case '1':
                cout << " Podaj nazwę pliku:";
                cin >> fileName;
                
                adjMatrix.loadFromFile(fileName);
                adjMatrix.print();

                
                
                adjList.loadFromFile(fileName);
                adjList.toPrint();
                
                break;
                
            case '2':
                mst.prim(adjMatrix);
                mst.prim(adjList);

                break;
                
            case '3':
                mst.kruskal(adjMatrix);
                mst.kruskal(adjList);
                break;
        }
                
        } while (option != '0');
        
    }
    
int main(int argc, char *argv[]) {
        char option;
        do {
            cout << endl;
            cout << "==== MENU GLOWNE ===" << endl;
            cout << "1.MST" << endl;
            cout << "0.Wyjscie" << endl;
            cout << "Podaj opcje:";
            cin >> option;
            cout << endl;
            
            switch (option){
                case '1':
                    menu_mst();
                    break;
            }
            
        } while (option != '0');
        
        return 0;
    }
