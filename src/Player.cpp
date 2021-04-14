#include "Player.h"
#include <iostream>
#include <string>

Player::Player(){
     nbPions = 2;
     std::cout<< "taper le nom du joueur :"<<std::endl;
     std::cin>>name;
}

void Player::SetcolorPlayer(Player &a,int colore){
    a.color = colore;
}

 std::string Player::Getname(Player a){
     return a.name;
 }
 int Player::getcolor(){
 return color;}

 int Player::increment_nbPion(int nb){
    nbPions += nb;
    return 0;
 }
 Player::~Player(){}
