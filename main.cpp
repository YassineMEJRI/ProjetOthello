#include <iostream>
#include "../include/Game.h"

using namespace std;

int main()
{
    string c;
    int a,b;
    cout<<"tapez Start to initializate the game"<<endl;
    cin>> c;
    if (c=="start"){
        system("CLS");
        string c="";
        Game k;
        k.initiate();
        int nb = 2 ;
        do {
            k.jouerTour(k,nb);
        }while(k.othellier.getnbPionsTotale()<64);
        }
    return 0;
}
