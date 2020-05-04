#include <iostream>
#include <Restaurant.h>
#include <Chelner.h>
using namespace std;

int main()
{
    int n,x, y;
    Restaurant* restaurant = Restaurant::getInstance();
    Chelner chelner("Ion");

    cout <<"introduceti nr de mese al restaurantului: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout <<"introduceti numarul de locuri al mesei " << i <<" :";
        cin >> *restaurant;
        //restaurant->adaugaMasa(new Masa(x));
    }
    cout<<"\n";
    while(true)
    {
        cout<<"1 n - introduceti n clienti noi\n";
        cout<<"2 n - achitati nota pentru clientul cu id-ul \n";
        cout<<"3 n - achitati nota pentru masa cu id-ul \n";
        cout<<"4 - afisati id-urile meselor si clientii \n";
        cout<<"5 - exit\n";
        cout<<"optiunea aleasa este: ";
        cin >> x;
        if (x == 5)
            break;
        if (x== 4)
        {
            cout << *restaurant <<"\n";
            continue;
        }
        cin >> y;
        if (x == 1)
            chelner.primireClienti(y);
        if (x == 2){
            try{
            throw chelner.totalClient(y);
            }
            catch(double x)
            {
                cout << x<<"\n";
            }
            catch(...)
            {
                cout <<"invalid";
            }
        }
        if(x == 3){
            try{
            throw chelner.totalMasa(y);
            }
            catch(double x)
            {
                cout << x<<"\n";
            }
            catch(...)
            {
                cout <<"invalid";
            }
        }
    }


    return 0;
}
