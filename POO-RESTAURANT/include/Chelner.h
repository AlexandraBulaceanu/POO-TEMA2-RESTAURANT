#ifndef CHELNER_H
#define CHELNER_H
#include "Produs.h"
#include "Client.h"
#include <bits/stdc++.h>

using namespace std;

class Chelner
{
    public:
        Chelner(string = "");
        ~Chelner();
        void primireClienti(int);
        friend istream& operator >> (istream&, Chelner&);
        friend ostream& operator << (ostream&, const Chelner&);
        Chelner& operator = (const Chelner&);
        Chelner(const Chelner&);
        void setName(string );
        string getName() const;
        double totalClient(int);
        double totalMasa(int);
    protected:

    private:
        string nume;
         queue<Client*> comanda;

};

#endif // CHELNER_H
