#include "AlteBauturi.h"
#include <bits/stdc++.h>

using namespace std;

unordered_map<string,double> AlteBauturi::alteBauturi({{"bereCuAlcool",8.9},{"bereFaraAlcool",9.2},{"apaPlata",3.6}});



AlteBauturi::AlteBauturi(int c,string s):Produs(c,s)
{

}



AlteBauturi::~AlteBauturi()
{

}
double AlteBauturi::getPret(){
    return cantitate*alteBauturi[getTip()];
}
