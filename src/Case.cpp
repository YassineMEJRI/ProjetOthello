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

int Case :: setCouleur (int couleur )
{
    this->couleur=couleur ;
    return 1;
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
