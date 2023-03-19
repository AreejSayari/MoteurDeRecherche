#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// index
class index
{
public:
    virtual ~index(){}
    virtual void savestat(string cheminf, unordered_map<string, double> statics) = 0;
    virtual unordered_map<string, double> getstat(string mot) = 0;
    virtual void suppfichier(string cheminf) = 0;
    //virtual void sauvegarder()=0;
};

class index1 : public index
{
    unordered_map<string, unordered_map<string, double>> dict; 
public:
    ~index1(){}
    void savestat(string cheminf, unordered_map<string, double> statics);
    unordered_map<string, double> getstat(string mot);
    void suppfichier(string cheminf);
    //void sauvegarder();
};

class statistique
{
public:
    string mot;
    string fichier;
    double stat;
    statistique(string m, string f, double s) : mot(m), fichier(f), stat(s) {}
};
class index2 : public index
{
    vector<statistique> ind;
public:
    ~index2(){}
    void savestat(string cheminf, unordered_map<string, double> statics);
    unordered_map<string, double> getstat(string mot);
    void suppfichier(string cheminf);
    //void sauvegarder();
};