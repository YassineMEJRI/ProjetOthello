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
    log.open("logs/"+ss.str()+".txt");
    /*
    LeaderBoard l;
    l.addScore("yassine",100);
    l.addScore("mariem",120);
    l.addScore("mourad", 50);
    l.addScore("yassine", 100);
    l.writeListeToFile();
    //l.writeListeToFile();

    l.readListeFromFile();
    l.addScore("mourad", 300);
    l.affiche();
    l.getSortedByScore();

    //randomize who plays first
*/

    cout << "Jouer contre:\n0.un ami\n1.CPU1\n2.CPU2" << endl;
    int adversaire;
    do{
        cin >> adversaire;
    }while(adversaire<0&&adversaire>2);

    system("CLS");
    string c="";
    Game k;
    k.initiate(adversaire);
    k.GUI();

    return 0;
}
