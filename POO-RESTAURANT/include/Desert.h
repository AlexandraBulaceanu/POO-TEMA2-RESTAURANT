#ifndef DESERT_H
#define DESERT_H
#include "Produs.h"
#include <bits/stdc++.h>

using namespace std;

class Desert:public Produs
{
    public:
        Desert(int = 0,string = "");
        virtual ~Desert();
        double getPret();

        friend istream& operator >> (istream&, Desert&);
        friend ostream& operator << (ostream&, const Desert&);
        Desert& operator = (const Desert&);
        Desert(const Desert&);

    protected:

    private:
        static unordered_map<string,double> deserturi;
};

#endif // DESERT_H
