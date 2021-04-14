#include "Othellier.h"
#include <iostream>

Othellier::Othellier(){
        nbPionsTotale = 4 ;
        grille[3][3].setCouleur(0);
        grille[4][4].setCouleur(0);
        grille[3][4].setCouleur(1);
        grille[4][3].setCouleur(1);
}

int Othellier::ajouterPion(int posx ,int posy ,int couleur ){
    grille[posx][posy].setCouleur(couleur);
}
void Othellier::accessPions(int couleur){
    // black test
    std::cout<<couleur<<std::endl;
    std::string access="";
    int couleuradd = 1;
    if (couleur == 1 ) {couleuradd = 0;}
    for( int i = 0 ; i<8 ;i++)
    {for (int j = 0; j<8;j++)
        { int k=j;
         if (grille[i][j].getCouleur() == couleur )
            {//--------------- horizontal -------------------------------
             do{k++;}while((grille[i][k].getCouleur() == couleuradd));
             if ((8>k)&&(j+1<k)&&(grille[i][k].getCouleur()==-1)){
                access = (char)(97+k);
                std::cout <<" | " << access <<","<< i+1;}
             k = j;
             do{k--;}while((grille[i][k].getCouleur() == couleuradd));
             if ((j-1>k)&&(grille[i][k].getCouleur()==-1)&&(0<=k)){
                access = (char)(97+k);
                std::cout <<" | " << access <<","<< i+1;}
            //--------------- vertical verification --------------------
                k = i;
             do{k++;}while((grille[k][j].getCouleur() == couleuradd));
             if ((8>k)&&(j+1<k)&&(grille[k][j].getCouleur() == -1)){
                access = (char)(97+j);
                std::cout <<" | " << access <<","<< k+1;}
                k = i;
             do{k--;}while((grille[k][j].getCouleur() == couleuradd));
             if ((j-1>k)&&(0<=k)&&(grille[k][j].getCouleur() == -1)){
                access = (char)(97+j);
                std::cout <<" | " << access <<","<< k+1;}

            //--------------- verification diagonal sup --------------------
             k=i;
             int k1 = j;
             do{k++; k1 ++; }while((grille[k][k1].getCouleur() == couleuradd));
             if ((j+1<k1)&&(i+1<k)&&(grille[k][k1].getCouleur() == -1)){
                access = (char)(97+k1);
                std::cout <<" | " << access <<","<< k+1;}

             k=i;
             k1 = j;
             do{k--; k1 --; }while((grille[k][k1].getCouleur() == couleuradd));
             if ((j-1>k1)&&(i-1>k)&&(grille[k][k1].getCouleur() == -1)){
                access = (char)(97+k1);
                std::cout <<" | " << access <<","<< k+1;}
             k=i;
             k1 = j;
             do{k++; k1 --; }while((grille[k][k1].getCouleur() == couleuradd));
             if ((j-1>k1)&&(i+1<k)&&(grille[k][k1].getCouleur() == -1)){
                access = (char)(97+k1);
                std::cout <<" | " << access <<","<< k+1;}
             k=i;
             k1 = j;
             do{k--; k1 ++; }while((grille[k][k1].getCouleur() == couleuradd));
             if ((j-1>k1)&&(i-1>k)&&(grille[k][k1].getCouleur() == -1)){
                access = (char)(97+k1);
                std::cout <<" | " << access <<","<< k+1;}
        }
    }
    }}
void  Othellier :: printBoard()
{system("cls");
std::cout << "    a   b   c   d   e   f   g   h   " <<std::endl;
        for ( int i =0 ; i<8; i++)
            {
              std::cout  << " -+---+---+---+---+---+---+---+---+" <<std::endl ;
              std::cout << i + 1 ;
              for ( int j =0 ; j<8; j++)
              { std::cout << " |" ;
                if (grille[i][j].getCouleur() == -1 ){std::cout << "  " ;}
                else if (grille[i][j].getCouleur() == 0){std::cout << " b" ;}
                     else {std::cout << " n" ;}}
                std::cout<< " |"<<std::endl;
              }
std::cout  << " ----------------------------------" << std::endl ;
}
Othellier::~Othellier()
{
    //dtor
}
int Othellier::incrementer(){
 return this->nbPionsTotale++;
}
int Othellier::getnbPionsTotale(){
return this->nbPionsTotale;}

Case Othellier::getCase(int x, int y){
    return grille[x][y];
}
