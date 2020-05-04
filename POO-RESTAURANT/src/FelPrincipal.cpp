#include "FelPrincipal.h"
#include <bits/stdc++.h>

using namespace std;

unordered_map<string,double> FelPrincipal::principale = {{"puiFrigarui",18.95},{"tocanaDePui",25.6},{"vitaChateaubriand",35.78},{"vitaStroganoff",46},{"fileDeVita",48.9}};
unordered_map<string,double> FelPrincipal::garnituri = {{"cartofiPrajiti",9.7},{"cartofiPiure",10.3},{"orezSarbesc",13.4}};

FelPrincipal::FelPrincipal(int c,string s,bool b, int f,string g):Produs(c,s),garnitura(b), bineFacuta(f), garni(g)
{
    //ctor
}

FelPrincipal::~FelPrincipal()
{

}

double FelPrincipal::getPret(){
    return cantitate*principale[getTip()]+garnitura*garnituri[garni];
}
