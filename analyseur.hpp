#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Analyseur
class analyseur
{
public:
    virtual~analyseur(){}
    virtual unordered_map<string, double> analyser(vector<string> listemots) = 0;
};

class analyseurOccurence : public analyseur
{
public:
    ~analyseurOccurence(){}
    unordered_map<string, double> analyser(vector<string> listemots);
};

class analyseurFrequence : public analyseur
{
public:
    ~analyseurFrequence(){}
    unordered_map<string, double> analyser(vector<string> listemots);
};

class analyseurExistance : public analyseur
{
public:
    ~analyseurExistance(){}
    unordered_map<string, double> analyser(vector<string> listemots)
    {
        unordered_map<string, double> dict;
        return dict;
    }
    unordered_map<string, double> analyser(vector<string> listemots, vector<string> mot);
};