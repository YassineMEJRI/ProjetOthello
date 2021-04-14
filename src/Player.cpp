#include "Player.h"
#include <iostream>
#include <string>

Player::Player(){
     nbPions = 2;
     std::cout<< "taper le nom du joueur :"<<std::endl;
     std::cin>>name;
}

void Player::setCouleur(int coul){
    color = coul;
}

 std::string Player::getName(){
     return name;
 }
 int Player::getcolor(){
 return color;}

 int Player::increment_nbPion(int nb){
    nbPions += nb;
    return 0;
 }

int Player::getNbPions(){
     return nbPions;
}
int Player::setNbPions(){
    nbPions = 0;
}
 Player::~Player(){}
