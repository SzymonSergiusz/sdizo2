//
//  main.cpp
//  sdizo2
//
//  Created by Szymon Kluska on 14/05/2023.
//

#include <stdio.h>
#include "AdjListGraph.hpp"
#include "MSTAlgorithm.hpp"
#include "ShortestPath.hpp"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;


void menu_mst() {
    AdjListGraph adjList(0);
    AdjMatrixGraph adjMatrix(0);
    char option;
    int vGen;
    float dens = 0;
    string fileName;
    MSTAlgorithm mstPrimM, mstPrimAl, mstKruskalM, mstKruskalAl;
    EdgeList primMatrixEdgeList,kruskalMatrixEdgeList, primAdjListEdgeList, kruskalAdjListEdgeList;
    do{
        cout << endl;
        cout << "---MST---" << endl;
        cout << "A. automatyczne wczytanie" << endl;
        cout << "1.Wczytaj z pliku" << endl;
        cout << "2.Prim" << endl;
        cout << "3.Kruskal" << endl;
        cout << "4.Wyswietl wyniki Prima" << endl;
        cout << "5.Wyswietl wyniki Kruskala" << endl;
        cout << "6.Wygeneruj graf macierz" << endl;
        cout << "7.Wygeneruj graf lista" << endl;
        cout << "T.Test (pomiary)" << endl;
        cout << "0.Powrot do menu" << endl;
        cout << "Podaj opcje:";
        cin >> option;
        cout << endl;
        switch (option) {
            case 'A':
                fileName = "/Users/sergiusz/Documents/studia/CzwartySemestr/SDIZO/sdizo2/sdizo2/sdizo2/pliki/dane_mst.txt";
                adjMatrix.loadFromFile(fileName);
                adjMatrix.print();

                adjList.loadFromFile(fileName);
                adjList.toPrint();

                break;
                
            case '1':
                cout << " Podaj nazwę pliku:";
                cin >> fileName;
                
                adjMatrix.loadFromFile(fileName);
                adjMatrix.print();

                adjList.loadFromFile(fileName);
                adjList.toPrint();
                
                break;
                
            case '2':
                primMatrixEdgeList = mstPrimM.prim(adjMatrix);
                primAdjListEdgeList = mstPrimAl.prim(adjList);
                break;
                
            case '3':
                kruskalMatrixEdgeList = mstKruskalM.kruskal(adjMatrix);
                kruskalAdjListEdgeList = mstKruskalAl.kruskal(adjList);
                
                break;
            case '4':
                cout << "Prim Macierz MST: " << mstPrimM.mstVal<<"\n";
                primMatrixEdgeList.print();
                cout << "Prim Lista MST: " << mstPrimAl.mstVal<<"\n";
                primAdjListEdgeList.print();
                
                break;
            case '5':
                cout << "Kruskal Macierz MST: " << mstKruskalM.mstVal<<"\n";
                kruskalMatrixEdgeList.print();
                cout << "Kruskal Lista MST: " << mstKruskalAl.mstVal<<"\n";
                kruskalAdjListEdgeList.print();
                break;
            case '6':
                cout << " Podaj ilosc wierzcholkow:";
                cin >> vGen;
                cout << " Podaj gestosc:";
                cin >> dens;
                cout << "Wygenerowany graf Macierz MST: \n";
                adjMatrix.generateGraphUndirected(vGen, dens);
                adjMatrix.print();
                break;
            case '7':
                cout << " Podaj ilosc wierzcholkow:";
                cin >> vGen;
                cout << " Podaj gestosc:";
                cin >> dens;
                cout << "Wygenerowany graf Lista MST: \n";
                adjList.generateGraphUndirected(vGen, dens);
                adjList.toPrint();
                break;
        }
                
        } while (option != '0');
        
    }

void menu_dijkstra() {
    AdjListGraph adjList(0);
    AdjMatrixGraph adjMatrix(0);
    char option;
    int vGen;
    float dens = 0;
    string fileName;
    ShortestPath spMacierz, spLista;
    do{
        cout << endl;
        cout << "---DIJKSTRA---" << endl;
        cout << "0. automatyczne wczytanie" << endl;
        cout << "1.Wczytaj z pliku" << endl;
        cout << "2.Dijkstra lista sasiadow" << endl;
        cout << "3.Dijkstra macierz" << endl;
        cout << "5.Wyswietl wyniki" << endl;
        cout << "6.Wygeneruj graf macierz" << endl;
        cout << "7.Wygeneruj graf lista" << endl;
        
        cout << "T.Test (pomiary)" << endl;
        cout << "0.Powrot do menu" << endl;
        cout << "Podaj opcje:";
        cin >> option;
        cout << endl;
        switch (option) {
            case 'A':
                fileName = "/Users/sergiusz/Documents/studia/CzwartySemestr/SDIZO/sdizo2/sdizo2/sdizo2/pliki/dane_droga_sk1.txt";
                adjMatrix.loadFromFileDijkstra(fileName);
                adjMatrix.print();

                adjList.loadFromFileDijkstra(fileName);
                adjList.toPrint();

                break;
                
            case '1':
                cout << " Podaj nazwę pliku:";
                cin >> fileName;
                
                adjMatrix.loadFromFileDijkstra(fileName);
                adjMatrix.print();

                adjList.loadFromFileDijkstra(fileName);
                adjList.toPrint();
                
                break;
                
            case '2':
                spLista.dijkstra(adjList, 0);
                spLista.print();
                break;
            case '3':
                spMacierz.dijkstra(adjMatrix, 0);
                spMacierz.print();
                break;
                
                
            case '6':
                cout << " Podaj ilosc wierzcholkow:";
                cin >> vGen;
                cout << " Podaj gestosc:";
                cin >> dens;
                cout << "Wygenerowany graf Macierz MST: \n";
                adjMatrix.generateGraphDirected(vGen, dens);
                adjMatrix.print();
                break;
            case '7':
                cout << " Podaj ilosc wierzcholkow:";
                cin >> vGen;
                cout << " Podaj gestosc:";
                cin >> dens;
                cout << "Wygenerowany graf Lista MST: \n";
                adjList.generateGraphDirected(vGen, dens);
                adjList.toPrint();
                break;
                
                
            case 'T':
                AdjMatrixGraph testM(0);
                AdjListGraph testL(0);
                testM.loadFromFileDijkstra("/Users/sergiusz/Documents/studia/CzwartySemestr/SDIZO/sdizo2/sdizo2/sdizo2/pliki/test.txt");
                testL.loadFromFileDijkstra("/Users/sergiusz/Documents/studia/CzwartySemestr/SDIZO/sdizo2/sdizo2/sdizo2/pliki/test.txt");
                ShortestPath testSpM, testSpL;
                std::cout << "Dla macierzy:\n";
                testSpM.dijkstra(testM, 0);
                testSpM.print();
                std::cout << "Dla listy:\n";
                testSpL.dijkstra(testL, 0);
                testSpL.print();
                
                break;
        }
                
        } while (option != '0');
        
    }

void menu_belford() {
    AdjListGraph adjList(0);
    AdjMatrixGraph adjMatrix(0);
    
    bool isCorrect;
    int vGen;
    float dens = 0;
    char option;
    string fileName;
    ShortestPath spMacierz, spLista;
    do{
        cout << endl;
        cout << "---BELLMAN FORD---" << endl;
        cout << "A. automatyczne wczytanie" << endl;
        cout << "1.Wczytaj z pliku" << endl;
        cout << "2.Bellman Ford lista sasiadow" << endl;
        cout << "3.Bellman Ford macierz" << endl;
        cout << "5.Wyswietl wyniki" << endl;
        cout << "6.Wygeneruj graf macierz" << endl;
        cout << "7.Wygeneruj graf lista" << endl;
        cout << "T.Test (pomiary)" << endl;
        cout << "0.Powrot do menu" << endl;
        cout << "Podaj opcje:";
        cin >> option;
        cout << endl;
        switch (option) {
            case 'A':
                fileName = "/Users/sergiusz/Documents/studia/CzwartySemestr/SDIZO/sdizo2/sdizo2/sdizo2/pliki/dane_droga_sk_BF.txt";
                adjMatrix.loadFromFileDijkstra(fileName);
                adjMatrix.print();

                adjList.loadFromFileDijkstra(fileName);
                adjList.toPrint();

                break;
                
            case '1':
                cout << " Podaj nazwę pliku:";
                cin >> fileName;
                
                adjMatrix.loadFromFileDijkstra(fileName);
                adjMatrix.print();

                adjList.loadFromFileDijkstra(fileName);
                adjList.toPrint();
                
                break;
                
            case '2':
                isCorrect = spLista.belford(adjList, 0);
                if (isCorrect) {
                    spLista.print();

                } else std::cout << "Wykryto cykl ujemny\n";
                                
                break;
            case '3':
                isCorrect = spMacierz.belford(adjMatrix, 0);
                if (isCorrect) spMacierz.print();
                else std::cout << "Wykryto cykl ujemny\n";
                break;
                
                
                
            case '6':
                cout << " Podaj ilosc wierzcholkow:";
                cin >> vGen;
                cout << " Podaj gestosc:";
                cin >> dens;
                cout << "Wygenerowany graf Macierz MST: \n";
                adjMatrix.generateGraphDirected(vGen, dens);
                adjMatrix.print();
                break;
            case '7':
                cout << " Podaj ilosc wierzcholkow:";
                cin >> vGen;
                cout << " Podaj gestosc:";
                cin >> dens;
                cout << "Wygenerowany graf Lista MST: \n";
                adjList.generateGraphDirected(vGen, dens);
                adjList.toPrint();
                break;
                
            case 'T':
                AdjMatrixGraph testM(0);
                AdjListGraph testL(0);
                testM.loadFromFileDijkstra("/Users/sergiusz/Documents/studia/CzwartySemestr/SDIZO/sdizo2/sdizo2/sdizo2/pliki/dane_droga_sk_BF.txt");
                testL.loadFromFileDijkstra("/Users/sergiusz/Documents/studia/CzwartySemestr/SDIZO/sdizo2/sdizo2/sdizo2/pliki/dane_droga_sk1.txt");
                ShortestPath testSpM, testSpL;
                std::cout << "Dla macierzy:\n";
                isCorrect = testSpM.belford(testM, 0);
                if (isCorrect) testSpM.print();
                else std::cout << "Wykryto cykl ujemny\n";
                std::cout << "Dla listy:\n";
                isCorrect = testSpL.belford(testL, 0);
                if (isCorrect) testSpL.print();
                else std::cout << "Wykryto cykl ujemny\n";
                std::cout << "Dla listy dijkstra :\n";
                testSpL.dijkstra(testL, 0);
                testSpL.print();
 
                break;
        }
                
        } while (option != '0');
        
    }

void writeCsvFile(const std::string &filename, const std::string &operation, int nV, float density, double time) {
    std::ofstream file(filename, std::ios_base::app);
    if (!file) { //
        std::cerr << "nie ma pliku" << filename << std::endl;
        return;
    }
    file << operation << "," << nV << "," << density << "," << time << std::endl;
    
    
    std::cout << "done: " << operation << " dla " << nV << "," << density << "\n";
}


int wierzcholki_tab[] = {50, 100, 200, 500, 1000, 2000};
//int wierzcholki_tab[] = {2000};
float density_tab[] = {0.2, 0.6, 0.99};
//float density_tab[] = {0.2};

int ileRazy = 50;
string prim_pomiary = "/Users/sergiusz/Documents/studia/CzwartySemestr/SDIZO/sdizo2/wyniki/primPOP.csv";
string kruskal_pomiary = "/Users/sergiusz/Documents/studia/CzwartySemestr/SDIZO/sdizo2/wyniki/kruskalPOP.csv";
string dijkstra_pomiary = "/Users/sergiusz/Documents/studia/CzwartySemestr/SDIZO/sdizo2/wyniki/dijkstra.csv";
string belford_pomiary = "/Users/sergiusz/Documents/studia/CzwartySemestr/SDIZO/sdizo2/wyniki/belfordPOPMACIERZ.csv";



void test_prim() {
    //lista
    MSTAlgorithm mst;
    AdjListGraph adj(0);
    for (float dens : density_tab) {
        
        for(auto V : wierzcholki_tab) {
            
            for(int i = 0; i < ileRazy; i++) {
                adj.generateGraphUndirected(V, dens);

                auto start = chrono::high_resolution_clock::now();

                mst.prim(adj);
                auto end = chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration<double>(end - start).count();
                writeCsvFile(prim_pomiary,"PRIM LISTA SASIADOW", V, dens, duration);
            }
            

            
            
        }
        
    }
    
    //macierz
    AdjMatrixGraph matrix(0);
    for (float dens : density_tab) {
        
        for(auto V : wierzcholki_tab) {
            for(int i = 0; i < ileRazy; i++) {
                matrix.generateGraphUndirected(V, dens);

                auto start = chrono::high_resolution_clock::now();
                
                mst.prim(matrix);
                auto end = chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration<double>(end - start).count();
                writeCsvFile(prim_pomiary,"PRIM MACIERZ", V, dens, duration);
            }
        }
        
    }
    
}


void test_kruskal() {
    //lista
    MSTAlgorithm mst;
    AdjListGraph adj(0);
    for (float dens : density_tab) {
        
        for(auto V : wierzcholki_tab) {
            
            for(int i = 0; i < ileRazy; i++) {
                adj.generateGraphUndirected(V, dens);

                auto start = chrono::high_resolution_clock::now();
                
                mst.kruskal(adj);
                auto end = chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration<double>(end - start).count();
                writeCsvFile(kruskal_pomiary,"KRUSKAL LISTA SASIADOW", V, dens, duration);
            }
        }
        
    }
    
    //macierz
    AdjMatrixGraph matrix(0);
    for (float dens : density_tab) {
        
        
        for(auto V : wierzcholki_tab) {
            for(int i = 0; i < ileRazy; i++) {
                matrix.generateGraphUndirected(V, dens);

                auto start = chrono::high_resolution_clock::now();
                
                mst.kruskal(matrix);
                auto end = chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration<double>(end - start).count();
                writeCsvFile(kruskal_pomiary,"KRUSKAL MACIERZ", V, dens, duration);
                
                
            }
        }
        
    }
    
}


void test_dijkstra() {
    //lista
    ShortestPath sp;
    AdjListGraph adj(0);
    for (float dens : density_tab) {
        
        for(auto V : wierzcholki_tab) {
            for(int i = 0; i < ileRazy; i++) {
                adj.generateGraphDirected(V, dens);

                auto start = chrono::high_resolution_clock::now();
                
                sp.dijkstra(adj, 0);
                auto end = chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration<double>(end - start).count();
                writeCsvFile(dijkstra_pomiary,"DIJKSTRA LISTA SASIADOW", V, dens, duration);
            }
        }
        
    }
    
    //macierz
    AdjMatrixGraph matrix(0);
    for (float dens : density_tab) {
        
        for(auto V : wierzcholki_tab) {
            for(int i = 0; i < ileRazy; i++) {
                matrix.generateGraphDirected(V, dens);

                auto start = chrono::high_resolution_clock::now();
                
                sp.dijkstra(matrix, 0);
                auto end = chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration<double>(end - start).count();
                writeCsvFile(dijkstra_pomiary,"DIJKSTRA MACIERZ", V, dens, duration);
            }
        }
        
    }
    
}
void test_belford() {
    //lista
    ShortestPath sp;
    AdjListGraph adj(0);
//    for (float dens : density_tab) {
//        
//        for(auto V : wierzcholki_tab) {
//            for(int i = 0; i < ileRazy; i++) {
//                adj.generateGraphDirected(V, dens);
//
//                auto start = chrono::high_resolution_clock::now();
//                
//                sp.belford(adj, 0);
//                auto end = chrono::high_resolution_clock::now();
//                auto duration = std::chrono::duration<double>(end - start).count();
//                writeCsvFile(belford_pomiary,"BELFORD LISTA SASIADOW", V, dens, duration);
//            }
//        }
//        
//    }
    
    //macierz
    AdjMatrixGraph matrix(0);
    for (float dens : density_tab) {
        
        for(auto V : wierzcholki_tab) {
            for(int i = 0; i < ileRazy; i++) {
                matrix.generateGraphDirected(V, dens);

                auto start = chrono::high_resolution_clock::now();
                
                sp.belford(matrix, 0);
                auto end = chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration<double>(end - start).count();
                writeCsvFile(belford_pomiary,"BELFORD MACIERZ", V, dens, duration);
            }
        }
        
    }
    
}
void test() {
//    test_prim();
    test_belford();
//    test_kruskal();
//    test_dijkstra();
}
int main(int argc, char *argv[]) {
        char option;
        do {
            cout << endl;
            cout << "==== MENU GLOWNE ===" << endl;
            cout << "1.MST" << endl;
            cout << "2.Dijkstra" << endl;
            cout << "3.Bellman Ford" << endl;
            cout << "0.Wyjscie" << endl;
            cout << "Podaj opcje:";
            cin >> option;
            cout << endl;
            
            switch (option){
                case '1':
                    menu_mst();
                    break;
                case '2':
                    menu_dijkstra();
                    break;
                case '3':
                    menu_belford();
                    break;
                case 'T':
                    test();
                    break;
                case 'S':
                    AdjMatrixGraph m(0);
                    m.generateGraphDirected(20, 0.99);
                    MSTAlgorithm mst;
                    EdgeList el = mst.prim(m);
                    el.print();
                    
                    break;
            }
            
        } while (option != '0');
        
        return 0;
    }
