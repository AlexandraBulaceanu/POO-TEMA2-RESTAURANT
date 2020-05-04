#include "Ciorba.h"
#include <bits/stdc++.h>

using namespace std;

unordered_map<string,double> Ciorba::ciorbe={{"burta",10.50},{"legume",7.8},{"ciuperci",15.9}};
unordered_map<string,double> Ciorba::sides={{"smantana",2.4},{"ardei",1.0}};

Ciorba::Ciorba(int c,string t, bool s, bool a):Produs(c,t),smantana(s),ardei(a)
{

}

Ciorba::~Ciorba()
{

}

double Ciorba::getPret(){
    return (ciorbe[getTip()])*cantitate+smantana*sides["smantana"]+ardei*sides["ardei"];
}
