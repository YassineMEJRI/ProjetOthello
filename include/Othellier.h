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
        void accessPions(int);
        Othellier getOthellier();
        Case getCase(int, int);
    private:
        Case grille [8][8] ;
        int nbPionsTotale = 0 ;
};

#endif // OTHELLIER_H_INCLUDED
