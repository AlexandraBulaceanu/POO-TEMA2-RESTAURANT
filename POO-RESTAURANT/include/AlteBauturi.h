#ifndef ALTEBAUTURI_H
#define ALTEBAUTURI_H
#include "Produs.h"
#include <bits/stdc++.h>

using namespace std;

class AlteBauturi:public Produs
{
    public:
        AlteBauturi(int = 0,string = "");
        virtual ~AlteBauturi();
        double getPret();

        friend istream& operator >> (istream&, AlteBauturi&);
        friend ostream& operator << (ostream&, const AlteBauturi&);
        AlteBauturi& operator = (const AlteBauturi&);
        AlteBauturi(const AlteBauturi&);

    protected:

    private:
        static unordered_map<string,double> alteBauturi;
};

#endif // ALTEBAUTURI_H
