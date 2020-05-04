#ifndef CIORBA_H
#define CIORBA_H
#include "Produs.h"
#include <bits/stdc++.h>

using namespace std;

class Ciorba:public Produs
{
    public:
        Ciorba(int = 0,string = "",bool = 0,bool = 0);
        ~Ciorba();
        double getPret();

        friend istream& operator >> (istream&, Ciorba&);
        friend ostream& operator << (ostream&, const Ciorba&);
        Ciorba& operator = (const Ciorba&);
        Ciorba(const Ciorba&);



    protected:

    private:
        static unordered_map<string,double> ciorbe;
        static unordered_map<string,double> sides;
        bool smantana;
        bool ardei;

};

#endif // CIORBA_H
