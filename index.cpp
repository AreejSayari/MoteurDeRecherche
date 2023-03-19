#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "index.hpp"

using namespace std;

// index 1
unordered_map<string, double> index1::getstat(string mot)
{
    return(dict[mot]);
}
void index1::savestat(string cheminf, unordered_map<string, double> statics)
{
    for (auto itr = statics.begin(); itr != statics.end(); itr++)
    {
        dict[itr->first][cheminf] = itr->second;
        /*auto mot = dict.find(itr->first);
        if (mot == dict.end())
        {
            dict[itr->first][cheminf] = itr->second;
        }
        else
        {
            mot->second.insert(make_pair(cheminf, itr->second));
        }*/
    }
}
void index1::suppfichier(string cheminf)
{
    for (auto itr = dict.begin(); itr != dict.end(); itr++)
    {
        for (auto k = itr->second.begin(); k != itr->second.end(); k++)
        {
            auto it = itr->second.find(cheminf);
            while (it != itr->second.end())
            {
                itr->second.erase(it);
                it = itr->second.find(cheminf);
            }
        }
        if (itr->second.size() == 0)
        {
            dict.erase(itr);
        }
    }
}
/*void index1::sauvegarder()
{
    unordered_map<string,double>::iterator  a ;
    //fstream file("Save.txt", ios::out | ios::trunc);
    fstream file("C:\\VScode\\C++\\C++ programs\\MiniProjet\\moteur\\save.txt", ios::app | ios::trunc);
    if (file.is_open())
    {
        for (auto itr = dict.begin(); itr != dict.end(); itr++)
        {
            file <<" { " << itr->first << " : " ;
            for ( a = (itr->second).begin(); a != (itr->second).end();a++)
            {
                file<<" { " << a->first << " : "<< a->second << " } , " ;
            }
            file<<  " } " <<endl;
        }
        file.close();
        cout<< "\nSauvegard avec succes "<<endl;
    }
    else
    {
        cout<< "Erreur  !!";
    }
}*/

// index 2
void index2::savestat(string cheminf, unordered_map<string, double> statics)
{
    for (auto itr = statics.begin(); itr != statics.end(); itr++)
    {
        statistique s(itr->first, cheminf, itr->second);
        ind.push_back(s);
    }
}
unordered_map<string, double> index2::getstat(string mot)
{
    unordered_map<string, double> d;
    for (auto s : ind)
    {
        if (s.mot == mot)
        {
            d.insert(make_pair(s.fichier, s.stat));
        }
    }
    return d;
}
void index2::suppfichier(string cheminf)
{
    for (long long unsigned int i = 0; i < ind.size(); i++)
    {
        if (ind[i].fichier == cheminf)
        {
            ind.erase(ind.begin() + i);
            i--;
        }
    }
}

/*void index2::sauvegarder()
{
    //fstream file("Save.txt", ios::out | ios::trunc);
    fstream file("Save.txt", ios::app | ios::trunc);

    if (file.is_open())
    {
        for (auto itr = ind.begin(); itr != ind.end(); itr++)
        {
            file<< itr->mot << " : " <<itr->fichier << " : " <<itr->stat << endl;

        }
        file.close();
        cout<< "\nSauvegard avec succes "<<endl;
    }
    else
    {
        cout<< "Erreur  !!";
    }
}*/