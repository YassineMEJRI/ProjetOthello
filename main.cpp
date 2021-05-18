#include <iostream>
#include "Game.h"
#include <ctime>
#include <sstream>
#include "common.h"
#include <string>
#include <SFML/Graphics.hpp>
#include "LeaderBoard.h"
#include <SFML/Main.hpp>

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

    /*cout << "Jouer contre:\n0.un ami\n1.CPU1\n2.CPU2" << endl;
    int adversaire;
    do{
        cin >> adversaire;
    }while(adversaire<0&&adversaire>2);

    system("CLS");
    string c="";*/

    Game g;
    //k.initiate(adversaire);
    g.startGameGUI();
    /*LeaderBoard l;
    l.readListeFromFile();
    cout << l.getStringSortedByScore();*/
    /*
    string h("heeee");
    cout << h;
    printf("%s", h.c_str());

    char s[200];
    sprintf(s,"%-20s%d",h,20);
    string sds(s);
    cout << s;
    */
    return 0;
}
