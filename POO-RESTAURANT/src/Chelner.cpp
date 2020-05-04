#include "Chelner.h"
#include "Restaurant.h"
#include "Produs.h"
#include "Masa.h"
#include <bits/stdc++.h>

using namespace std;


void Chelner::setName(string s)
{
    nume = s;
}

string Chelner::getName() const
{
    return nume;
}

istream& operator >> (istream& in, Chelner& obj)
{
    string s;
    in >> s;
    obj.setName(s);
    return in;
}
ostream& operator << (ostream& out, const Chelner& obj)
{
    out << obj.getName();
    return out;
}
Chelner& Chelner::operator = (const Chelner& obj)
{
    nume = obj.nume;
    while(!comanda.empty())
        comanda.front()->~Client(), comanda.pop();
    queue<Client*> aux = obj.comanda;
    while(!aux.empty())
    {
        comanda.push(new Client(*(aux.front())));
        aux.pop();
    }
    return(*this);
}

Chelner::Chelner(const Chelner& obj)
{

}


Chelner::Chelner(string str):nume(str)
{

}

Chelner::~Chelner()
{
    while(!comanda.empty())
        comanda.front()->~Client(), comanda.pop();
}
void Chelner::primireClienti(int nr){
    try{
        vector<Masa*> masa;
        Restaurant* instanta = Restaurant::getInstance();
        masa = instanta->getMese();
        for(auto &m:masa){
            if(nr<=m->getCapacitateTotala()-m->getCapacitateCurenta())
                   throw m;
        }
        throw "nu exista loc";
    }catch(Masa* m){
        while(nr--)
        {
           Client* c =  new Client();
           m->adaugaClienti(c);
           comanda.push(c);
        }
    }catch(...){
        cout<<"Ne pare rau! Nu mai avem locuri!";
        return;
    }
    while (!comanda.empty())
    {
        cin >> *(comanda.front());
        comanda.pop();
    }
}
double Chelner::totalClient(int id){
    double nota=0;
    try{
        vector<Masa*> masa = Restaurant::getInstance()->getMese();
        for(auto &m:masa){
            for(auto &c:m->getClienti()){
                if(c->getId()==id){
                        //
                    nota = c->notaIndividuala();
                    //cout<<"da";
                    m->eliminareClienti(c);

                    return nota;
                }
            }
        throw "nu exista clientul";
        }
    }catch(const string){
        cout<<"Nu exista clientul respectiv";
    }
}

double Chelner::totalMasa(int id){
    double nota=0;
    try{
        vector<Masa*> masa = Restaurant::getInstance()->getMese();
        for(auto &m:masa){
                if(m->getId()==id){
                    nota = m->notaColectiva();
                    return nota;
                }
            }
        throw "nu exista masa";
        }
    catch(const string){
        cout<<"Nu exista masa respectiva";
    }
}
