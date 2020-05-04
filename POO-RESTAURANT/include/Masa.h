#ifndef MASA_H
#define MASA_H
#include<vector>
#include "Client.h"
using namespace std;


class Masa
{
    public:
        Masa(int);
        ~Masa();
        void adaugaClienti(Client *);
        void eliminareClienti(Client *);
        double notaColectiva();
        int getId();
        int getCapacitateTotala();
        int getCapacitateCurenta();
        void setCapacitateTotala(int);
        void setCapacitateCurenta(int);

        friend istream& operator >> (istream&, Masa&);
        friend ostream& operator << (ostream&, const Masa&);
        Masa& operator = (const Masa&);
        Masa(const Masa&);

        vector<Client*> & getClienti();
    protected:
    private:
        vector<Client*> clienti;
        int capacitateTotala;
        int capacitateCurenta;
        int this_id;
        static int id;
};

#endif // MASA_H
