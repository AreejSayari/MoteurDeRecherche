#include <iostream>
#include <vector>
#include <string>
#include "MoteurDeRecherche.cpp"

using namespace std;

int main()
{
    moteurDeRech m;
    int x;
    string cheminf;
    string req;
    while (x != 6)
    {
        cout << "\n";
        cout << " |||||||||||||||||||||||||||-----MOTEUR DE RECHERCHE ---||||||||||||||||||||||||||||" << endl;
        cout << " //----------------------------------- Menu --------------------------------------//" << endl;
        cout << " //-------------------------------------------------------------------------------//" << endl;
        cout << " //-----------------        Choisir une option entre 1 et 6     ------------------//" << endl;
        cout << " //-------------------------------------------------------------------------------//" << endl;
        cout << "1:  Faire votre recherche\n2:  Indexer un fichier\n3:  Reindexer un fichier\n4:  Supprimer un fichier\n5:  Modifier le moteur de recherche\n6:  Exit" << endl;
        cin >> x;
        while (x < 1 || x > 6)
        {
            cout << "Resaisir un numero entre 1 et 6" << endl;
            cin >> x;
        }
        switch (x)
        {
        case 1:
            cout << " |||||||||||||||||||||||||||-----    RECHERCHE     -----||||||||||||||||||||||||||||" << endl;
            cout << "saisir la requete de recherche:";
            cin.ignore();
            getline(cin, req);
            m.rechercher(req);
            break;
        case 2:
            cout << " |||||||||||||||||||||||||||-----     INDEXER      -----||||||||||||||||||||||||||||" << endl;
            cout << "saisir le chemin:";
            cin.ignore();
            getline(cin, cheminf);
            m.indexer(cheminf);
            break;
        case 3:
            cout << " |||||||||||||||||||||||||||-----    REINDEXER     -----||||||||||||||||||||||||||||" << endl;
            cout << "saisir le chemin:";
            cin.ignore();
            getline(cin, cheminf);
            m.reindexerFichier(cheminf);
            break;
        case 4:
            cout << " |||||||||||||||||||||||||||-----    SUPPRIMER     -----||||||||||||||||||||||||||||" << endl;
            cout << "saisir le chemin:";
            cin.ignore();
            getline(cin, cheminf);
            m.supprimerFichier(cheminf);
            break;
        case 5:
            cout << " |||||||||||||||||||||||||||-----    MODIFIER      -----||||||||||||||||||||||||||||" << endl;
            m.changerdemoteur();
            break;
        }
        cout << " //-------------------------------------------------------------------------------//" << endl;
        cout << " //-------------------------------------------------------------------------------//" << endl;
    }
    return 0;
}