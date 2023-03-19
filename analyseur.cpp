#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include "analyseur.hpp"


// classe analyseur
unordered_map<string, double> analyseurOccurence::analyser(vector<string> mots)
{
    unordered_map<string, double> dict;
    for (const string &mot : mots)
    {
        auto itr = dict.find(mot);
        if (itr == dict.end())
            dict.insert(make_pair(mot, 1));
        else
            dict[mot]++;
    }
    return dict;
}

unordered_map<string, double> analyseurFrequence::analyser(vector<string> mots)
{
    int a = mots.size();
    unordered_map<string, double> dict;
    for (const string &mot : mots)
    {
        auto itr = dict.find(mot);
        if (itr == dict.end())
            dict.insert(make_pair(mot, 1));
        else
            dict[mot]++;
    }
    for (auto itr = dict.begin(); itr != dict.end(); itr++)
    {
        itr->second = (itr->second / a);
    }
    return dict;
}

unordered_map<string, double> analyseurExistance::analyser(vector<string> listemots, vector<string> mot)
{
    unordered_map<string, double> dict;
    for (auto m : mot)
    {
        for (auto w : listemots)
        {
            if (m == w)
            {
                dict.insert(make_pair(m, 1));
                break;
            }
        }
        dict.insert(make_pair(m, 0));
    }
    return dict;
}
