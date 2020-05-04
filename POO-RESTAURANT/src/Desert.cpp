#include "Desert.h"
#include <bits/stdc++.h>

using namespace std;

unordered_map<string,double> Desert::deserturi= {{"3CupeDeInghetata,",8},{"5CupeDeInghetata",12.8},{"tortKrantz",12.7}};

Desert::Desert(int c,string t):Produs(c,t)
{
    //ctor
}

Desert::~Desert()
{
    //dtor
}

double Desert::getPret(){
    return deserturi[getTip()]*cantitate;
}
