#ifndef CLIENT_H
#define CLIENT_H
#include<vector>
#include "Produs.h"
#include <bits/stdc++.h>


using namespace std;

class Client
{
    public:
        Client(bool = 0);
        ~Client();
        void setIntrebat(bool);
        bool getIntrebat();
         double notaIndividuala();

        friend istream& operator >> (istream&, Client&);
        friend ostream& operator << (ostream&, const Client&);
        Client& operator = (Client const&);
        Client(const Client&);


         void adaugaProdus(Produs*);
         int getId();
    private:
        static int id;
        int this_id;
        bool intrebat;
        vector<Produs*> produse;

};

#endif // CLIENT_H
