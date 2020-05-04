#include "Produs.h"
#include <bits/stdc++.h>

using namespace std;


Produs::Produs(int p,string tip) : cantitate(p), tip(tip)
{
}

Produs& Produs::operator = (const Produs& obj)
{
    pret = obj.pret;
    cantitate = obj.cantitate;
    tip = obj.tip;
    return (*this);
}

Produs::Produs(const Produs& obj)
{
    pret = obj.pret;
    cantitate = obj.cantitate;
    tip = obj.tip;
}



Produs::~Produs()
{

}

int Produs::getCantitate(){
    return cantitate;
}

void Produs::setCantitate(int c){
    cantitate=c;
}
string Produs::getTip(){
    return tip;
}
void Produs::setTip(string s){
    tip = s;
}
