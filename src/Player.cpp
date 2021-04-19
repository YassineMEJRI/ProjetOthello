#include "../include/Player.h"
#include <iostream>
#include <string>

Player::Player(){
     nbPions = 2;
}

void Player::setCouleur(int coul){
    color = coul;
}

 std::string Player::getName(){
     return name;
}

int Player::getcolor(){
    return color;
}

 int Player::increment_nbPion(int nb){
    nbPions += nb;
    return 0;
 }

int Player::getNbPions(){
     return nbPions;
}
void Player::setNbPions(int x ){
    nbPions = x; //
}

void Player::entrerNom(){
    std::cout<< "taper le nom du joueur :"<<std::endl;
    std::cin>>name;
}

void Player::setNom(std::string n){
    name = n;
}

int Player::isBot(){
    return bot;
}

void Player::setIsBot(int x){
    bot = x;
}
 Player::~Player(){}
