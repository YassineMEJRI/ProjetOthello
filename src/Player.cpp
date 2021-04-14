#include "../include/Player.h"
#include <iostream>
#include <string>

Player::Player(){
    this->nbPions = 2;
     cout<< "taper le nom du joueur :"<<endl;
     cin>>this->name;}
void Player::SetcolorPlayer(Player &a,int colore){
 a.color = colore;}
 string Player::Getname(Player a){
     return a.name;
 }
 int Player::getcolor(){
 return this->color;}
