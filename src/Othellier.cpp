#include "Othellier.h"
#include <iostream>
void init(int*);
int tab[64];
Othellier::Othellier(){
        nbPionsTotale = 4 ;
}

int Othellier::ajouterPion(int posx ,int posy ,int couleur ){
    grille[posx][posy].setCouleur(couleur);
}
int* Othellier::accessPions(int couleur){
    //tableau qui contient les jeux possibles
    init(tab);
    int tailleTab = 0;
    // black test
    std::cout<<couleur<<std::endl;
    std::string access="";
    int couleuradd = 1;
    if (couleur == 1 ) {couleuradd = 0;}
    for( int i = 0 ; i<8 ;i++)
    {for (int j = 0; j<8;j++)
        { int k=j;
         if (grille[i][j].getCouleur() == couleur )
            {
            //--------------- horizontal -------------------------------
             do{k++;}while((grille[i][k].getCouleur() == couleuradd));
             if ((8>k)&&(j+1<k)&&(grille[i][k].getCouleur()==-1)){
                access = (char)(97+k);
                std::cout <<" | " << access <<","<< i+1;
                //ajout du jeu au tableau
                    tab[tailleTab] = grille[i][access[0]-'a'].getId();
                    std::cout << tab[tailleTab] <<std::endl;
                    std::cout << i+1 << " " << access[0]-'a'<<std::endl;;
                    tailleTab++;
                }
             k = j;
             do{k--;}while((grille[i][k].getCouleur() == couleuradd));
             if ((j-1>k)&&(grille[i][k].getCouleur()==-1)&&(0<=k)){
                access = (char)(97+k);
                std::cout <<" | " << access <<","<< i+1;
                tab[tailleTab] = grille[i][access[0]-'a'].getId();
                std::cout << tab[tailleTab] <<std::endl;
                tailleTab++;
                }

            //--------------- vertical verification --------------------
                k = i;
             do{k++;}while((grille[k][j].getCouleur() == couleuradd));
             if ((8>k)&&(j+1<k)&&(grille[k][j].getCouleur() == -1)){
                access = (char)(97+j);
                std::cout <<" | " << access <<","<< k+1;
                tab[tailleTab] = grille[k][access[0]-'a'].getId();
                std::cout << tab[tailleTab] <<std::endl;
                tailleTab++;
                }

                k = i;
             do{k--;}while((grille[k][j].getCouleur() == couleuradd));
             if ((j-1>k)&&(0<=k)&&(grille[k][j].getCouleur() == -1)){
                access = (char)(97+j);
                std::cout <<" | " << access <<","<< k+1;
                tab[tailleTab] = grille[k][access[0]-'a'].getId();
                std::cout << tab[tailleTab] <<std::endl;
                tailleTab++;
                }


            //--------------- verification diagonal sup --------------------
             k=i;
             int k1 = j;
             do{k++; k1 ++; }while((grille[k][k1].getCouleur() == couleuradd));
             if ((j+1<k1)&&(i+1<k)&&(grille[k][k1].getCouleur() == -1)){
                access = (char)(97+k1);
                std::cout <<" | " << access <<","<< k+1;
                tab[tailleTab] = grille[k][access[0]-'a'].getId();
                std::cout << tab[tailleTab] <<std::endl;
                tailleTab++;
                }


             k=i;
             k1 = j;
             do{k--; k1 --; }while((grille[k][k1].getCouleur() == couleuradd));
             if ((j-1>k1)&&(i-1>k)&&(grille[k][k1].getCouleur() == -1)){
                access = (char)(97+k1);
                std::cout <<" | " << access <<","<< k+1;
                tab[tailleTab] = grille[k][access[0]-'a'].getId();
                std::cout << tab[tailleTab] <<std::endl;
                tailleTab++;
                }

             k=i;
             k1 = j;
             do{k++; k1 --; }while((grille[k][k1].getCouleur() == couleuradd));
             if ((j-1>k1)&&(i+1<k)&&(grille[k][k1].getCouleur() == -1)){
                access = (char)(97+k1);
                std::cout <<" | " << access <<","<< k+1;
                tab[tailleTab] = grille[k][access[0]-'a'].getId();
                std::cout << tab[tailleTab] <<std::endl;
                tailleTab++;
                }

             k=i;
             k1 = j;
             do{k--; k1 ++; }while((grille[k][k1].getCouleur() == couleuradd));
             if ((j-1>k1)&&(i-1>k)&&(grille[k][k1].getCouleur() == -1)){
                access = (char)(97+k1);
                std::cout <<" | " << access <<","<< k+1;
                tab[tailleTab] = grille[k][access[0]-'a'].getId();
                std::cout << tab[tailleTab] <<std::endl;
                tailleTab++;
                }

        }
    }
    }
    std::cout << tailleTab << std::endl;
    tailleTab = 0;
    return tab;
    }
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

Case & Othellier::getCase(int x, int y){
    return grille[x][y];
}

void init(int* tab){
    for(int i = 0; i < 64 ; i++)
        tab[i] = -1;
}
