#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <dirent.h>
#include "lecteur.hpp"

using namespace std;

// classe lecteur
vector<string> lecteur1::lire(string cheminf)
{
    vector<string> mots;
    string mot;
    ifstream fichier(cheminf);
    while (fichier >> mot)
    {
        mots.push_back(mot);
    }
    fichier.close();
    return mots;
}

vector<string> lecteurRep::lire(string path)
{
    const char *rep = path.c_str();
    vector<string> liste;
    DIR *pDIR;
    struct dirent *entry;
    pDIR = opendir(rep);
    if (pDIR)
    {
        do
        {
            entry = readdir(pDIR);
            if (entry)
            {
                if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
                    liste.push_back(path + "\\" + entry->d_name);
            }
        } while (entry);
    }
    int k=path.length();
    string fin;
    fin += path[k-4];
    fin +=path[k-3];
    fin +=path[k-2];
    fin +=path[k-1];
    if (fin==".txt")
    {
        liste.push_back(path);
    }
    return (liste);
}