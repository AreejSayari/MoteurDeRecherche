#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <map>
#include "ordonnanceur.hpp"

// ordonnancement

vector<string> ord_aleatoire::ordonnancer(index *i, vector<string> motscles)
{
    vector<string> m;
    unordered_map<string, double> stat;
    for (auto mot : motscles)
    {
        stat = i->getstat(mot);
        for (auto itr = stat.begin(); itr != stat.end(); itr++)
        {
            m.push_back(itr->first);
        }
    }
    if (m.empty())
    {
        m.push_back("Il y a aucun fichier");
    }
    return m;
}

vector<string> ord_binaire::ordonnancer(index *i, vector<string> motscles)
{
    vector<string> m;
    unordered_map<string, double> stat, s;
    multimap<double, string, greater<double>> multimap;
    for (auto mot : motscles)
    {
        stat = i->getstat(mot);
        if (stat.empty())
        {
            break;
        }
        for (auto e : stat)
        {
            auto it = s.find(e.first);
            if (it == s.end())
            {
                s.insert(make_pair(e.first, e.second));
            }
            else
            {
                it->second += e.second;
            }
        }
    }
    if (s.empty())
    {
        m.push_back("Il y a aucun fichier");
        return m;
    }
    for (auto pair : s)
    {
        multimap.insert(make_pair(pair.second, pair.first));
    }
    for (auto itr = multimap.begin(); itr != multimap.end(); itr++)
    {
        m.push_back(itr->second);
    }
    return m;
}

vector<string> ord_intersection::ordonnancer(index *i, vector<string> motscles)
{
    vector<string> m;
    unordered_map<string, double> stat, s;
    multimap<double, string, greater<double>> multimap;
    for (auto mot : motscles)
    {
        stat = i->getstat(mot);
        if (stat.empty())
        {
            break;
        }
        for (auto e : stat)
        {
            auto it = s.find(e.first);
            if (it == s.end())
            {
                s.insert(make_pair(e.first, 1));
            }
            else
            {
                it->second++;
            }
        }
    }
    if (s.empty())
    {
        m.push_back("Il y a aucun fichier");
        return m;
    }
    for (auto pair : s)
    {
        multimap.insert(make_pair(pair.second, pair.first));
    }
    for (auto itr = multimap.begin(); itr != multimap.end(); itr++)
    {
        m.push_back(itr->second);
    }
    return m;
}
