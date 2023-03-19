#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include "MoteurDeRecherche.hpp"

// Moteur de recherche
moteurDeRech::moteurDeRech()
{
    l = new lecteur1;
    lrep = new lecteurRep;
    a = new analyseurOccurence;
    o = new ord_binaire;
    ind = new index1;
    t.push_back(new ponctuation);
    t.push_back(new majuscule);
    //t.push_back(new orthographe);
    //t.push_back(new motsvides());
}

void moteurDeRech::rechercher(string req)
{
    vector<string> motscles, fichiers;
    string ch;
    for (long long unsigned int i = 0; i < req.size(); i++)
    {
        if (req[i] == ' ' && ch.size() != 0)
        {
            motscles.push_back(ch);
            ch = string();
        }
        else
        {
            ch += req[i];
        }
    }
    if (ch.size() != 0)
    {
        motscles.push_back(ch);
    }
    for (auto e : t)
    {
        motscles = e->traiter(motscles);
    }
    fichiers = o->ordonnancer(ind, motscles);
    cout << "\nLes Resultats de ta recherche:" << endl;
    for (auto e : fichiers)
    {
        cout << e << endl;
    }
}
void moteurDeRech::indexer(string cheminf)
{
    vector<string> fichiers;
    fichiers = lrep->lire(cheminf);
    for (auto f : fichiers)
    {
        indexerFichier(f);
    }
}
void moteurDeRech::indexerFichier(string cheminf)
{
    vector<string> listemots;
    unordered_map<string, double> stat;
    listemots = l->lire(cheminf); // lecture du fichier
    for (auto e : t)              // traitement du fichier
    {
        listemots = e->traiter(listemots);
    }
    stat = a->analyser(listemots); // analyse du fichier
    ind->savestat(cheminf, stat);  // sauvegarde des statistiques dans l'index
}
void moteurDeRech::supprimerFichier(string cheminf)
{
    ind->suppfichier(cheminf);
}
void moteurDeRech::reindexerFichier(string cheminf)
{
    supprimerFichier(cheminf);
    indexerFichier(cheminf);
}
void moteurDeRech::changerdemoteur()
{
    int i, j, s;
    string lang;
    while (i != 5)
    {
        cout << "Qu'est-ce que vous voulez modifier?" << endl;
        cout << "1.Traiteur\n2.Analyseur\n3.Index\n4.Ordonnanceur\n5.Exit" << endl;
        cin >> i;
        switch (i)
        {
        case 1:
            for (long long unsigned int k = 0; k < t.size(); k++)
            {
                delete t[k];
            }
            t.clear();
            do
            {
                cout << "\nchoisissez le traiteur:\n1.Traiteur de ponctuation\n2.Traiteur de majuscule\n3.Traiteur d'orthographe\n4.Traiteur de mots vides" << endl;
                ;
                cin >> j;
                if (j == 1)
                {
                    t.push_back(new ponctuation);
                }
                if (j == 2)
                {
                    t.push_back(new majuscule);
                }
                if (j == 3)
                {
                    t.push_back(new orthographe);
                }
                if (j == 4)
                {
                    cout << "saisir la langue: " << endl;
                    cin >> lang;
                    t.push_back(new motsvides(lang));
                }
                cout << "Vous voulez choisir un autre traiteur?\n1.Oui\n2.Non" << endl;
                ;
                cin >> s;
            } while (s == 1);
            break;
        case 2:
            cout << "choisissez l'analyseur\n1.Analyseur d'occurence\n2.Analyseur de frequence\n3.Analyseur d'existance" << endl;
            cin >> j;
            delete a;
            if (j == 1)
            {
                a = new analyseurOccurence;
            }
            if (j == 2)
            {
                a = new analyseurFrequence;
            }
            if (j == 2)
            {
                a = new analyseurExistance;
            }
            break;
        case 3:
            cout << "choisissez l'index\n1.Index1\n2.Index2" << endl;
            cin >> j;
            delete ind;
            if (j == 1)
            {
                ind = new index1;
            }
            if (j == 2)
            {
                ind = new index2;
            }
            break;
        case 4:
            cout << "choisissez l'ordonnanceur\n1.Ordonnanceur aléatoire\n2.Ordonnanceur d'intersection\n3.Ordonnanceur binaire" << endl;
            cin >> j;
            delete o;
            if (j == 1)
            {
                o = new ord_aleatoire;
            }
            if (j == 2)
            {
                o = new ord_intersection;
            }
            if (j == 2)
            {
                o = new ord_binaire;
            }
            break;
        default:
            break;
        }
    }
}