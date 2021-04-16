#include <iostream>
#include "Game.h"
//#include <fstream>
#include <ctime>
#include <sstream>
#include "common.h"
#include <string>

using namespace std;
//log file
ofstream log;
time_t now = time(0);


int main()
{
    //log file
    stringstream ss;
    ss << now;
    log.open(ss.str()+".txt");

    string c;
    int a,b;
    cout<<"type \"start\" to initializate the game"<<endl;
    cin>> c;
    if (c=="start"){
        system("CLS");
        string c="";
        Game k;
        k.initiate();
        int nb = 2 ;
        int noPlay = 1; // 1 si joueur percedent a joué
        do{
            if (!(noPlay=k.jouerTour(nb) || noPlay))
                break;
            log << "nb pions tot " << k.getOthellier().getnbPionsTotale() << endl;
        }while(k.getOthellier().getnbPionsTotale()<64);

        //afficher gagnant
        if (k.getWinner().length() == 0)
            cout << "Match Nul" << endl;
        else
            cout << "Le jouer " << k.getWinner() << " a gagné!";
        cout << "Le score final:\n" << k.getPlayer(0).getName() << " : " << k.getPlayer(0).getNbPions() << endl;
        cout << k.getPlayer(1).getName() << " : " << k.getPlayer(1).getNbPions() << endl;
        }
    return 0;
}
