#include <iostream>
#include "Game.h"
#include <ctime>
#include <sstream>
#include "common.h"
#include <string>
#include <SFML/Graphics.hpp>
#include "LeaderBoard.h"

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
    LeaderBoard l;
    l.readListeFromFile();
    l.affiche();
    l.addScore("yassine", 100);
    l.writeListeToFile();
    l.readListeFromFile();
    l.affiche();

/*
    cout << "Jouer contre:\n1.un ami\n2.Contre l'ordinateur" << endl;
    int adversaire;
    do{
        cin >> adversaire;
    }while(adversaire != 1 && adversaire !=2);

    system("CLS");
    string c="";
    Game k;
    k.initiate(adversaire);
    k.GUI();*/

    return 0;
}
