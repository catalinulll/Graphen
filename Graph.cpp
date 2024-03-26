#include "Graph.h"
#include <queue>
#include <iostream>
#include <sstream>

Graph::Graph(const string& filename) {
    ifstream f(filename);
    if (f.is_open()) {
        f >> nr_noduri;  // citesc nr de varfuri
        lista_adiacenta.resize(nr_noduri);  // redimensionez lista de adiacenta
        string l; // iau o variabila l pentru linii
        getline(f, l);  // consumăm linia goală după numărul de vârfuri
        while (getline(f, l)) { // parcurg fiecare linie si construiesc lista de adiacenta
            istringstream iss(l);
            int varf;
            iss >> varf;  // citesc varful curent
            int varf_adiacent;
            while (iss >> varf_adiacent) { //citesc varfurile adiacente
                lista_adiacenta[varf].push_back(varf_adiacent);  // adaug la lista de adiacenta varful adiacent
            }
        }
        f.close();
    } else {
        cout << "Fisierul nu se poate deschide" << endl;
    }
}

void Graph::colorare() {
    vector<int> culori(nr_noduri, -1);  // vectorul de culori are -1 deoarece culorile nu sunt setate
    vector<bool> vizitat(nr_noduri, false); // vectorul de varfuri vizitate este initializat cu false
    queue<int> coada; // coada pentru BFS
    for (int start = 0; start < nr_noduri; start++) {
        if (!vizitat[start]) { // daca  varful nu a fost vizitat
            coada.push(start); // se adauga varful in coada
            vizitat[start] = true; // se marcheaza ca vizitat
            culori[start] = 0; // se atribuie culoarea 0
            while (!coada.empty()) { // se face BFS
                int varf = coada.front(); // se extrag varfurile din coada
                coada.pop();
                for (int i = 0; i < lista_adiacenta[varf].size(); i++) { // pentru fiecare varf adiacent
                    int varf_adiacent = lista_adiacenta[varf][i];
                    if (!vizitat[varf_adiacent]) { // daca nu a fost inca vizitat
                        coada.push(varf_adiacent); // se adauga in coada
                        vizitat[varf_adiacent] = true; // se marcheaza ca vizitat
                        culori[varf_adiacent] = 1 - culori[varf]; // i se da culoarea complementara(se obtine din scaderea culorii varfului din 1
                    }
                }
            }
        }
    }
    for (int varf = 0; varf < nr_noduri; varf++) {
        cout << "VARF: " << varf << " | CULOARE: " << culori[varf] << endl;
    }
}
