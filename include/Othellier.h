#ifndef OTHELLIER_H_INCLUDED
#define OTHELLIER_H_INCLUDED
#include "Case.h"
#include<iostream>
class Othellier
{
    public:
        void printBoard() ;
        int ajouterPion (int posx ,int posy ,int couleur ) ;
        Othellier();
       ~Othellier();
        int incrementer();
        int getnbPionsTotale();
        int* Possiblemoves(int);/* 8 direction possibles  haut bas gauche droit les 4 diagonales */
        Othellier getOthellier();
        Case& getCase(int, int);
        int changerPion(int posx,int posy,int couleur) ;
    private:
        Case grille [8][8] ;
        int nbPionsTotale = 0 ;
};

#endif // OTHELLIER_H_INCLUDED
