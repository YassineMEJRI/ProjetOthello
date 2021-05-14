#include <iostream>
#include "Game.h"
#include <ctime>
#include <sstream>
#include "common.h"
#include <string>
#include <SFML/Graphics.hpp>

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

    cout << "Jouer contre:\n1.un ami\n2.Contre l'ordinateur" << endl;
    int adversaire;
    do{
        cin >> adversaire;
    }while(adversaire != 1 && adversaire !=2);

    system("CLS");
    string c="";
    Game k;
    k.initiate(adversaire);
    k.GUI();

    return 0;
}
