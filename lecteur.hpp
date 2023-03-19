#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Lecture
class lecteur
{
public:
    virtual ~lecteur(){}
    virtual vector<string> lire(string cheminf) = 0; // lire un fichier et retourner un vecteur de ses mots
};

class lecteur1 : public lecteur
{
public:
    ~lecteur1(){}   
    vector<string> lire(string cheminf);
};

class lecteurRep : public lecteur
{
public:
    ~lecteurRep(){}
    vector<string> lire(string cheminf);
};