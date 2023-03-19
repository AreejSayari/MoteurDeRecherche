#include <iostream>
#include <vector>
#include <string>
#include "index.cpp"

using namespace std;

// ordonnancement
class ordonnanceur
{
public:
    virtual ~ordonnanceur(){}
    virtual vector<string> ordonnancer(index* i, vector<string> motscles) = 0;
};

class ord_intersection : public ordonnanceur
{
public:
    ~ord_intersection(){}
    vector<string> ordonnancer(index* i, vector<string> motscles);
};

class ord_aleatoire : public ordonnanceur
{
public:
    ~ord_aleatoire(){}
    vector<string> ordonnancer(index* i, vector<string> motscles); 
};

class ord_binaire : public ordonnanceur
{
public:
    ~ord_binaire(){}
    vector<string> ordonnancer(index* i, vector<string> motscles); 
};