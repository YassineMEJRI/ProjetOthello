#include "LeaderBoard.h"

#include <fstream>

#include <map>

#include <string>

#include <sstream>

#include <iostream>

#include <iomanip>

LeaderBoard::LeaderBoard() {
  //ctor
}

void LeaderBoard::addScore(std::string nom, int score) {
  if (liste.count(nom) == 0)
    liste[nom] = score;
  else
    liste[nom] += score;
}

std::map < std::string, int > LeaderBoard::getListe() {
  return liste;
}

void LeaderBoard::writeListeToFile() {
  fichierScores.open("scores.txt", std::ios::out);
  std::map < std::string, int > ::iterator it;
  for (it = liste.begin(); it != liste.end(); it++) {
    fichierScores << it -> first << "\t" << it -> second << "\n";
  }
  fichierScores.close();
}

void LeaderBoard::readListeFromFile() {
  std::string sl;
  //std::stringstream ligne;
  std::string nom;
  int score;
  fichierScores.open("scores.txt", std::ios:: in );
  while (getline(fichierScores, sl)) {
    std::stringstream ligne;
    ligne << sl;
    ligne >> nom >> score;
    liste[nom] = score;
  }
  fichierScores.close();
}

std::multimap < int, std::string, std::greater < int >> LeaderBoard::getSortedByScore() {
  std::map < std::string, int > ::iterator it;
  std::multimap < int, std::string, std::greater < int >> sorted;
  for (it = liste.begin(); it != liste.end(); it++) {
    sorted.insert(std::pair < int, std::string > (it -> second, it -> first));
  }
  std::multimap < int, std::string, std::greater < int >> ::iterator it2;
  for (it2 = sorted.begin(); it2 != sorted.end(); it2++) {
    //std::cout << it2 -> first << "\t" << it2 -> second << "\n";
  }
  return sorted;
}

std::string LeaderBoard::getStringSortedByScore(){
  std::map < std::string, int > ::iterator it;
  std::multimap < int, std::string, std::greater < int >> sorted;
  std::stringstream sortedstring;

  for (it = liste.begin(); it != liste.end(); it++) {
    sorted.insert(std::pair < int, std::string > (it -> second, it -> first));
  }

  std::multimap < int, std::string, std::greater < int >> ::iterator it2;
    int nb = 0;
  for (it2 = sorted.begin(); it2 != sorted.end()&&nb<8; it2++) {
    //std::cout << it2 -> first << "\t" << it2 -> second << "\n";
    sortedstring   <<std::left << std::setw(8) << std::setfill(' ') <<it2 -> second;
    sortedstring <<std::right<<std::setw(15) << std::setfill(' ')<<it2 -> first<<std::endl;
    //sprintf(sortedstring,"%-20s%4d\n",(it2 -> second).c_str(),it2 -> first);
    nb++;
  }
  return sortedstring.str();
}

void LeaderBoard::affiche() {
  std::map < std::string, int > ::iterator it;
  for (it = liste.begin(); it != liste.end(); it++) {
//    std::cout << it -> first << "\t" << it -> second << "\n";
  }
}

LeaderBoard::~LeaderBoard() {
  //dtor
}
