#include "Masa.h"
#include "Client.h"
#include<vector>

using namespace std;

int Masa::id=0;

Masa::Masa(int cap) : capacitateTotala(cap)
{
    id++;
    this_id = id;
}

Masa::~Masa()
{

    for(auto &i:clienti){
        i->~Client();
        delete(i);
    }
    clienti.clear();
}

ostream& operator << (ostream& out, const Masa& obj)
{
    out << obj.this_id<<"\n";
    out <<"id-urile clientilor de la masa sunt: ";
    for (auto &it: obj.clienti)
        out << (*it) <<" ";
    out<<"\n";
    return out;

}

void Masa::adaugaClienti(Client *c){
    clienti.push_back(c);
    setCapacitateCurenta(clienti.size());
}
void Masa::eliminareClienti(Client *c){
    for(auto &i:clienti){
        if(i==c){
            swap(i,clienti[clienti.size()-1]);
            clienti.pop_back();

            i->~Client();

            setCapacitateCurenta(clienti.size());
        }
    }
}
double Masa::notaColectiva(){
    double suma=0;
    for(auto &c:clienti){
        suma+=c->notaIndividuala();
    }
    return suma;
}
int Masa::getId(){
    return this_id;
}
int Masa::getCapacitateCurenta(){
    return capacitateCurenta;
}
int Masa::getCapacitateTotala(){
    return capacitateTotala;
}
void Masa::setCapacitateTotala(int cap){
    capacitateTotala = cap;
}
void Masa::setCapacitateCurenta(int cap){
     capacitateCurenta=cap;
}
vector<Client*> & Masa::getClienti(){
    return clienti;
}
