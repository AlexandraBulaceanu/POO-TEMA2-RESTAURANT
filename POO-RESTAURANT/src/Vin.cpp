#include "Vin.h"
#include <bits/stdc++.h>

using namespace std;
unordered_map<string,double> Vin::varsat = {{"rosu",12.3},{"alb",10.2}};
unordered_map<string,double> Vin::sticla = {{"Bordeux",20.9},{"Bolovanu",17.8}};

Vin::Vin(int c, string s, bool b):Produs(c,s),sticluta(b)
{

}

Vin::~Vin()
{

}

istream& operator >> (istream& in, Vin& obj)
{
    in >> obj.cantitate;
    return in;
}
ostream& operator << (ostream& out, const Vin& obj)
{
    out << obj.cantitate;
    return out;
}
Vin& Vin::operator = (const Vin& obj)
{
    cantitate = obj.cantitate;
    pret = obj.pret;
    tip = obj.tip;
    return (*this);
}
Vin::Vin(const Vin& obj)
{
    cantitate = obj.cantitate;
    pret = obj.pret;
    tip = obj.tip;
}



double Vin::getPret(){
    if(sticluta)
        return cantitate*sticla[getTip()];
    else
        return cantitate*varsat[getTip()];
}
