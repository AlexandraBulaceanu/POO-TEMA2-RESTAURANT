#include "Restaurant.h"
#include "Masa.h"
#include<vector>

using namespace std;

Restaurant* Restaurant::instance=nullptr;

Restaurant::Restaurant(vector<Masa*> vec) : mese(vec)
{

}

Restaurant::~Restaurant()
{
    for(auto &i:mese){
        i->~Masa();
        delete(i);
    }
    mese.clear();
}

Restaurant* Restaurant::getInstance(){
    if(instance==nullptr){
        instance = new Restaurant();
    }
    return instance;
}

istream & operator >> (istream& in, Restaurant &obj)
{
    int x;
    in >> x;
    obj.adaugaMasa(new Masa(x));
    return in;
}

ostream& operator << (ostream& out, const Restaurant& obj)
{
    for (auto &it: obj.mese)
        out << *it;
    return out;
}

void Restaurant::adaugaMasa(Masa *m){
    mese.push_back(m);
}
vector<Masa*> & Restaurant::getMese(){
    return mese;
}
