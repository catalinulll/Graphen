#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class Graph {
private:
    int nr_noduri;
    vector<vector<int>> lista_adiacenta;
public:
    Graph(const string& filename);
    void colorare();
};
#endif // GRAPH_H
