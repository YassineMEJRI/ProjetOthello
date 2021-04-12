#include "Case.h"

int Case :: compteurId = 0;
Case::Case()
{
    id = compteurId++ ;
    couleur = -1 ;
}

Case::Case(const int i  , int c)
{
    id = i ;
    couleur = c ;

}

int Case :: getCouleur ()
{
    return couleur ;
}

void Case :: setCouleur (int couleur )
{
    this->couleur=couleur ;
}

int  Case ::getId () const
{
    return id ;
}

int Case :: getCompteurId()
{
    return compteurId ;
}

Case::~Case()
{
    compteurId -- ;
}
