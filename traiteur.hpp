#include <iostream>
#include <vector>
#include <string>

using namespace std;

// traiteur
class traiteur
{
public:
    virtual ~traiteur(){}
    virtual vector<string> traiter(vector<string> listemots) = 0;
};

class ponctuation : public traiteur
{
public:
    ~ponctuation(){}
    vector<string> traiter(vector<string> listemots); // supprimer toute la ponctuation des mots du vecteur
};

class majuscule : public traiteur
{
public:
    ~majuscule(){}
    vector<string> traiter(vector<string> listemots); // transformer les mots du vecteur en minuscule
};

class motsvides : public traiteur
{
    string lang;
public:
    ~motsvides(){}
    motsvides(string l="anglais") : lang(l) {}
    vector<string> traiter(vector<string> listemots);
};

class orthographe : public traiteur
{
public:
    ~orthographe(){}
    vector<string> traiter(vector<string> listemots);
};
