#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include "traiteur.hpp"

// classe traiter
vector<string> ponctuation::traiter(vector<string> listemots)
{
    vector<string> mots;
    string ch;
    for (auto text : listemots)
    {
        for (long long unsigned int i = 0; i < text.size(); i++)
        {
            if (isalpha(text[i]))
                ch = ch + text[i];
            if (not(isalpha(text[i + 1])) && (ch.size() != 0))
            {
                mots.push_back(ch);
                ch = string();
            }
        }
    }
    return mots;
}

vector<string> majuscule::traiter(vector<string> listemots)
{
    for (auto &e : listemots)
    {
        for (long long unsigned int j = 0; j < e.size(); j++)
        {
            e[j] = tolower(e[j]);
        }
    }
    return listemots;
}

vector<string> motsvides::traiter(vector<string> listemots)
{
    string f = "C:\\VScode\\C++\\C++ programs\\MiniProjet\\moteur\\lang\\" + lang + ".txt";
    string mot;
    ifstream fichier(f);
    while(fichier >> mot)
    {
        for (long long unsigned int i=0; i<listemots.size(); i++)
        {
            if (listemots[i] == mot)
            {
                listemots.erase(listemots.begin()+i);
            }
        }
    }
    fichier.close();
    return listemots;
}

vector<string> orthographe::traiter(vector<string> listemots)
{
    int j;
    for(auto &e:listemots)
    {
        j=e.size();
        if (e[j-1]=='s')
        {
            e.pop_back();
        }
    }
    return listemots;
}