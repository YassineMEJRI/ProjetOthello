#include "Game.h"
#include <string>

Game::Game(){}
Game::~Game(){}
int Game::jouerTour(Game &k,int &c){

int a,b;
    if ( (c % 2) == 0){
        std::string nom = players[0].Getname(players[0]);
        std::cout<<nom<<" play now"<<std::endl;
        std::cout<<"ajouter la position du point x et y"<< std::endl;
        std::cin>>a>>b;
        k.othellier.ajouterPion (a,b,k.players[0].getcolor());
        k.othellier.printBoard();}
    else
        {
        std::string nom = players[1].Getname(players[1]);
        std::cout<<nom<<" play now"<< std::endl;
        std::cout<<"ajouter la position du point x et y"<<std::endl;
        std::cin>>a>>b;
        k.othellier.ajouterPion (a,b,k.players[1].getcolor());
        k.othellier.printBoard();
        }c++;
}
void Game::initiate()
{   Othellier nes;
    nes.printBoard();
    players[0].SetcolorPlayer(players[0],0);
    players[1].SetcolorPlayer(players[1],1);
}
int Game::update()
{   this->othellier.incrementer();
    this->othellier.printBoard();
}
