#ifndef FELPRINCIPAL_H
#define FELPRINCIPAL_H
#include "Produs.h"
#include <bits/stdc++.h>

using namespace std;

class FelPrincipal:public Produs
{
    public:
        FelPrincipal(int,string t, bool = 0,int = 3,string g = "");
        virtual ~FelPrincipal();
        double getPret();

        friend istream& operator >> (istream&, FelPrincipal&);
        friend ostream& operator << (ostream&, const FelPrincipal&);
        FelPrincipal& operator = (const FelPrincipal&);
        FelPrincipal(const FelPrincipal&);

    protected:

    private:
        static unordered_map<string,double> principale;
        static unordered_map<string,double> garnituri;
        bool garnitura;
        int bineFacuta;
        string garni;
};

#endif // FELPRINCIPAL_H
