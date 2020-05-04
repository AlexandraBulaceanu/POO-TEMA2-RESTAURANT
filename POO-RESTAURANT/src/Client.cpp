#include "Client.h"
#include "Produs.h"
#include "AlteBauturi.h"
#include "Ciorba.h"
#include "Desert.h"
#include "FelPrincipal.h"
#include "Vin.h"
#include<vector>

using namespace std;

int Client::id = 0;

ostream & operator << (ostream& out, const Client& obj)
{
    out << obj.this_id;
    return out;
}



Client::Client(bool t) : intrebat(t)
{
    id++;
    this_id = id;
}

Client::Client(const Client& obj)
{
    this_id = ++id;
    intrebat = obj.intrebat;
    for (auto & it: obj.produse)
    {
        if (dynamic_cast<Vin*>(it))
            produse.push_back(it);
    }

}

Client::~Client()
{
    for(auto &i:produse){
        i->~Produs();
    }
    produse.clear();
}
void Client::setIntrebat(bool v){
    intrebat = v;
}
bool Client::getIntrebat(){
    return intrebat;
}
double Client::notaIndividuala(){
    double suma = 0;
    for(auto &p:produse){
        suma+=p->getPret();
    }
    return suma;
}
int Client::getId(){
    return this_id;
}
void Client::adaugaProdus(Produs* p){
    produse.push_back(p);
}
istream &operator >>(istream &f,Client& c){
    bool vrea;
    string tip;
    string vrea2;
    int can;
    cout<<"Vreti bautura?(da/nu)\n";
    f>>vrea2;
    if(vrea2 == "da"){
        cout<<"Ce tip de bautura?(vin, altceva)\n";
        f>>tip;
        if(tip!="vin"){
            cout<<"bere sau apa?\n";
            string tipAltaBautura;
            f>>tipAltaBautura;
            cout<<"Ce cantitate?\n";
                f>>can;
            AlteBauturi* a = new AlteBauturi(can,tipAltaBautura);
            c.adaugaProdus(a);
        }else{
            string sticla;
            bool sti;
            string tipVin;
            cout<<"varsat sau sticla\n";
            f>>sticla;
            if(sticla=="sticla") sti=true;
            cout<<"De care vin sa va aduc?\n";
            f>>tipVin;
            cout<<"Ce cantitate?\n";
            f>>can;
            Vin* v = new Vin(can,tipVin,sti);
            c.adaugaProdus(v);
        }
    }
    cout<<"Doriti ciorba?(da,nu)\n";
    f>>vrea2;
    if(vrea2=="da"){
        cout<<"Ce tip?(legume, burta, ciuperci)\n";
        f>>tip;
        bool s,a;
        if(tip=="legume"||tip=="burta")
        {
            cout<<"Cu smantana?(1,0)\n";
            f>>s;
            cout<<"Cu ardei?(1,0)\n";
            f>>a;
        }
        cout<<"Ce cantitate doriti?\n";
            f>>can;
        Ciorba* ci = new Ciorba(can,tip,s,a);
        c.adaugaProdus(ci);
    }
    cout<<"Doriti fel principal?(da,nu)\n";
    f>>vrea2;
    if(vrea2=="da"){
        int biness=3;
        cout<<"Ce doriti sa mancati?\n";
        f>>tip;
        if(tip=="vita Chateaubriand"){
            cout<<"Cat de bine facuta?\n";
            f>>biness;
        }
        cout<<"Ce cantitate?\n";
        f>>can;
        bool g;
        string tipGarnitura="";
        cout<<"Vreti si garnitura?\n";
        f>>g;
        if(g){
            cout<<"Ce garnitura doriti?\n";
            f>>tipGarnitura;
        }
        FelPrincipal* fp = new FelPrincipal(can,tip,g,biness,tipGarnitura);
        c.adaugaProdus(fp);
    }
    cout<<"Desert doriti(da,nu)?\n";
    f>>vrea2;
    if(vrea2=="da"){
        cout<<"Ce tip de desert ati dori?\n";
        f>>tip;
        cout<<"Ce cantitate?\n";
        f>>can;
        Desert* d = new Desert(can,tip);
        c.adaugaProdus(d);
    }
    c.intrebat=true;
    return f;
}
