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

    Game g;
    //k.initiate(adversaire);
    g.startGameGUI();
    return 0;
}
