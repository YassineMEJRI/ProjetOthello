#include "LeaderBoard.h"
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <iostream>

LeaderBoard::LeaderBoard()
{
    //ctor
}

void LeaderBoard::addScore(std::string nom,int score){
    if(liste.count(nom)==0)
        liste[nom]=score;
    else
        liste[nom]+=score;
}

std::map<std::string,int> LeaderBoard::getListe(){
    return liste;
}

void LeaderBoard::writeListeToFile(){
    fichierScores.open("scores.txt", std::ios::out);
    std::map<std::string,int>::iterator it;
    for(it = liste.begin(); it!= liste.end(); it++){
        fichierScores<<it->first << "\t" << it->second << "\n";
    }
    fichierScores.close();
}

void LeaderBoard::readListeFromFile(){
    std::string sl;
    std::stringstream ligne;
    std::string nom;
    int score;
    fichierScores.open("scores.txt", std::ios::in);
    while(getline(fichierScores, sl)){
        ligne << sl;
        ligne >> nom >> score;
        liste[nom]=score;
    }
    fichierScores.close();
}

void LeaderBoard::affiche(){
    std::map<std::string,int>::iterator it;
    for(it = liste.begin(); it!= liste.end(); it++){
        std::cout << it->first << "\t" << it->second << "\n";
    }
}

LeaderBoard::~LeaderBoard()
{
    //dtor
}
