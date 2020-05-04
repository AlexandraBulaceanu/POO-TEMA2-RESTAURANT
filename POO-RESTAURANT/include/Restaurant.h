#ifndef RESTAURANT_H
#define RESTAURANT_H
#include<vector>
#include<Masa.h>

using namespace std;

class Restaurant
{
    public:
        ~Restaurant();
        static Restaurant* getInstance();
        void adaugaMasa(Masa*);
        vector<Masa*> & getMese();

        friend istream& operator >> (istream&, Restaurant&);
        friend ostream& operator << (ostream&, const Restaurant&);
        Restaurant& operator = (const Restaurant&);
        Restaurant(const Restaurant&);

    protected:

    private:
        Restaurant(vector<Masa*> = {});
        static Restaurant* instance;
        vector<Masa*> mese;
};

#endif // RESTAURANT_H
