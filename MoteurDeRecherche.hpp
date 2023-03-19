#include <iostream>
#include <vector>
#include <string>
#include "analyseur.cpp"
#include "ordonnanceur.cpp"
#include "traiteur.cpp"
#include "lecteur.cpp"

using namespace std;

// Moteur de recherche
class moteurDeRech
{
    lecteur* l,*lrep;
    analyseur* a;
    vector<traiteur*> t;
    ordonnanceur* o;
    index* ind;
    void indexerFichier(string cheminf);
public:
    moteurDeRech();
    void rechercher(string requette);      // recherche des fichiers 
    void indexer(string cheminf); // indexer d'une repertoire
    void supprimerFichier(string cheminf); // supprimer un fichier de l’index
    void reindexerFichier(string cheminf); // reindexer un fichier
    void changerdemoteur();
};