#include "Player.h"
#include <iostream>
#include <string>


Player::Player(){
    this->nbPions = 2;
     std::cout<< "taper le nom du joueur :"<<std::endl;
     std::cin>>this->name;}
void Player::SetcolorPlayer(Player &a,int colore){
 a.color = colore;}
std:: string Player::Getname(Player a){
     return a.name;
 }
 int Player::getcolor(){
 return this->color;}

Player::~Player()
{
    //dtor
}
