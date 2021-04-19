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
        cout << "Jouer contre:\n 1.un ami\n2.Contre l'ordinateur" << endl;
        int adversaire;
        do{
            cin >> adversaire;
        }while(adversaire != 1 && adversaire !=2);

        system("CLS");
        string c="";
        Game k;
        k.initiate(adversaire);
        k.startGame();
    }
    return 0;
}
