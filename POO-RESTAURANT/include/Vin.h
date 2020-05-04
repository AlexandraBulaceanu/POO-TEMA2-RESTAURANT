#ifndef VIN_H
#define VIN_H
#include "Produs.h"
#include <bits/stdc++.h>

using namespace std;

class Vin:public Produs
{
    public:
        Vin(int = 0,string = "",bool = 0);
        virtual ~Vin();
        double getPret();

        friend istream& operator >> (istream&, Vin&);
        friend ostream& operator << (ostream&, const Vin&);
        Vin& operator = (const Vin&);
        Vin(const Vin&);

    protected:

    private:
        bool sticluta;
        static unordered_map<string,double> varsat;
        static unordered_map<string,double> sticla;
};

#endif // VIN_H
