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
        int getnbPionsTotale();
        void setnbPionsTotale(int);
        int possibleMoves(int);/* 8 direction possibles  haut bas gauche droit les 4 diagonales */
        Case& getCase(int, int);
        int changerPion(int posx,int posy,int couleur);
        int getXById(int);
        int getYById(int);
        void init();
        int* getPossibleMoves();
    private:
        Case grille [8][8] ;
        int nbPionsTotale = 0 ;
        int tabPossibleMoves[64];//tableau qui contient les jeux possibles a chaque tour
};

#endif // OTHELLIER_H_INCLUDED
