#include "Game.h"
#include <string>
Game::Game(){}
Game::~Game(){}
int Game::scoreupdate()
{
    this->players[0].setnbpoint();
    this->players[1].setnbpoint();
for ( int i =0 ; i<8; i++)
{
for ( int j =0 ; j<8; j++)
{
    if (this->othellier.getCase(i,j).getCouleur() == -1 ){}
    else if (this->othellier.getCase(i,j).getCouleur() == 0)
        {this->players[0].increment_nbPion(1);}
        else
        {this->players[1].increment_nbPion(1);}}
}}
int Game::jouerTour(Game &k,int &c){
    std::string a;
    std::cout<<"score du joueur "<<players[0].Getname(players[0])<<" est : "<<players[0].getnbpoint()<<std::endl;
    std::cout<<"score du joueur "<<players[1].Getname(players[1])<<" est : "<<players[1].getnbpoint()<<std::endl;
    if ( (c % 2) == 0) {
        std::string nom = players[0].Getname(players[0]);
        std::cout<<nom<<" play now"<<std::endl;
        k.othellier.accessPions(k.players[0].getcolor());
        std::cout<<std::endl;
        std::cout<<"ajouter la position du point sous la forme ' lettre , chiffre '"<<std::endl;
        std::cin>>a[0]>>a[1];
        std::cout<< (int)a[0]-'a'<<std::endl;
        std::cout<<(int)a[1]-'1';
        k.othellier.ajouterPion ((int)(a[1]-'1'),(int)(a[0]-'a'),k.players[0].getcolor());
        k.othellier.printBoard();
        }
    else
        {
        std::string nom = players[1].Getname(players[1]);
        std::cout<<nom<<" play now"<<std::endl;
        k.othellier.accessPions(k.players[1].getcolor());
        std::cout<<std::endl;
        std::cout<<"ajouter la position du point sous la forme ' lettre , chiffre '"<<std::endl;
        std::cin>>a[0]>>a[1];
        std::cout<< (int)a[0]-'a'<<std::endl;
        std::cout<<(int)a[1];
        k.othellier.ajouterPion ((int)(a[1]-'1'),(int)(a[0]-'a'),k.players[1].getcolor());
        k.othellier.printBoard();
        }c++;
        k.scoreupdate();
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

Othellier Game::getOthellier(){
    return othellier;
}

