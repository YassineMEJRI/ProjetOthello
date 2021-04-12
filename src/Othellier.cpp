#include "../include/Othellier.h"
#include <iostream>
using namespace std;

Othellier::Othellier()
{        nbPionsTotale = 4 ;
         grille[3][3].setCouleur(0);
         grille[4][4].setCouleur(0);
         grille[3][4].setCouleur(1);
         grille[4][3].setCouleur(1);
}

int Othellier::ajouterPion(int posx ,int posy ,int couleur )
{
    grille[posx][posy].setCouleur(couleur);
}

void  Othellier :: printBoard()
{
    system("cls");
    std::cout << "  a   b   c   d   e   f   g    h    " <<std::endl;
    for ( int i =0 ; i<8; i++)
    {
                  cout  << " ----------------------------------" << endl ;
                  cout << i + 1 ;

                for ( int j =0 ; j<8; j++)
                {

                       cout << " |" ;
                       if (grille[i][j].getCouleur() == -1 )

                          cout << "  " ;
                      else if (grille[i][j].getCouleur() == 0)
                        cout << " b " ;
                     else  cout << " n" ;
               }
                   cout<< " |" <<endl ;
            }
cout  << " ----------------------------------" << endl ;
  }
Othellier::~Othellier()
{
    //dtor
}
int Othellier::incrementer(){
 return this->nbPionsTotale++;
}
int Othellier::getnbPionsTotale(){
return this->nbPionsTotale;
}


