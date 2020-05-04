#ifndef PRODUS_H
#define PRODUS_H
#include <bits/stdc++.h>

using namespace std;

class Produs
{
    public:
        Produs(int = 0,string tip = "");
        virtual~Produs();

        virtual double getPret()=0;
        //void setPret(double)=0;
        int getCantitate();
        void setCantitate(int);
        void setTip(string);
        string getTip();

        friend istream& operator >> (istream&, Produs&);
        friend ostream& operator << (ostream&, const Produs&);
        Produs& operator = (const Produs&);
        Produs(const Produs&);

    protected:
         double pret;
         int cantitate;
         string tip;
    private:

};

#endif // PRODUS_H
