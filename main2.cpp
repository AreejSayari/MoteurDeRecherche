#include <iostream>
#include <vector>
#include <string>
#include "MoteurDeRecherche.cpp"

#include <chrono>
using namespace std::chrono;

using namespace std;

int main()
{
    moteurDeRech m;
    auto start = high_resolution_clock::now(); // debut
    m.indexer("C:\\VScode\\C++\\C++ programs\\MiniProjet\\petit_corpus");
    auto stop = high_resolution_clock::now(); // fin
    auto duration = duration_cast<microseconds>(stop - start);
    auto start2 = high_resolution_clock::now(); // debut
    m.rechercher("london station");
    auto stop2 = high_resolution_clock::now(); // fin
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "\nDuree d'indexation:" << duration.count() << " ms\nDuree de recherche " << duration2.count() << " ms" << endl;
    return 0;
}