#include "Game.h"
#include <iostream>
#include "common.h"
void init(int*);
int tab[64]; //tableau qui contient les jeux possibles a chaque tour
Othellier::Othellier(){
        nbPionsTotale = 4 ;
}

int Othellier::ajouterPion (int posx ,int posy ,int couleur ) /* couleur noir ou blanc */
{
    grille[posx][posy].setCouleur(couleur);
}
int* Othellier::Possiblemoves(int couleur) /* tester les cases possibles (lignes hor verti diagonale*/
{
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
                  /*  std::cout << tab[tailleTab] <<std::endl;*/
                  //  std::cout << i+1 << " " << access[0]-'a'<<std::endl;;
                    tailleTab++;
                }
             k = j;
             do{k--;}while((grille[i][k].getCouleur() == couleuradd));
             if ((j-1>k)&&(grille[i][k].getCouleur()==-1)&&(0<=k)){
                access = (char)(97+k);
                std::cout <<" | " << access <<","<< i+1;
                tab[tailleTab] = grille[i][access[0]-'a'].getId();
              //  std::cout << tab[tailleTab] <<std::endl;
                tailleTab++;
                }

            //--------------- vertical verification --------------------
                k=i;
             do{k++;}while((grille[k][j].getCouleur() == couleuradd));
             if ((8>k)&&(i+1<k)&&(grille[k][j].getCouleur()==-1)){
                access = (char)(97+j);
             std :: cout <<" | " << access <<","<< k+1;
             tab[tailleTab] = grille[k][access[0]-'a'].getId();
             tailleTab++;
             }
            k=i;
             do{k--;}while((grille[k][j].getCouleur() == couleuradd));
             if ((0<=k)&&(i-1>k)&&(grille[k][j].getCouleur()==-1)){
                access = (char)(97+j);
             std ::cout <<" | " << access <<","<< k+1;
             tab[tailleTab] = grille[k][access[0]-'a'].getId();
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
               // std::cout << tab[tailleTab] <<std::endl;
                tailleTab++;
                }


             k=i;
             k1 = j;
             do{k--; k1 --; }while((grille[k][k1].getCouleur() == couleuradd));
             if ((j-1>k1)&&(i-1>k)&&(grille[k][k1].getCouleur() == -1)){
                access = (char)(97+k1);
                std::cout <<" | " << access <<","<< k+1;
                tab[tailleTab] = grille[k][access[0]-'a'].getId();
                // std::cout << tab[tailleTab] <<std::endl;
                tailleTab++;
                }

             k=i;
             k1 = j;
             do{k++; k1 --; }while((grille[k][k1].getCouleur() == couleuradd));
             if ((j-1>k1)&&(i+1<k)&&(grille[k][k1].getCouleur() == -1)){
                access = (char)(97+k1);
                std::cout <<" | " << access <<","<< k+1;
                tab[tailleTab] = grille[k][access[0]-'a'].getId();
                //std::cout << tab[tailleTab] <<std::endl;
                tailleTab++;
                }

             k=i;
             k1 = j;
             do{k--; k1 ++; }while((grille[k][k1].getCouleur() == couleuradd));
             if ((j-1>k1)&&(i-1>k)&&(grille[k][k1].getCouleur() == -1)){
                access = (char)(97+k1);
                std::cout <<" | " << access <<","<< k+1;
                tab[tailleTab] = grille[k][access[0]-'a'].getId();
               // std::cout << tab[tailleTab] <<std::endl;
                tailleTab++;
                }

        }
    }
    }
  //  std::cout << tailleTab << std::endl;
    tailleTab = 0;
    return tab;
    }
void  Othellier :: printBoard()
{
    system("cls");
    std::cout << "    a   b   c   d   e   f   g   h   " <<std::endl;
//    log << "    a   b   c   d   e   f   g   h   " <<std::endl;
        for ( int i =0 ; i<8; i++)
            {
              std::cout  << " -+---+---+---+---+---+---+---+---+" <<std::endl ;
              std::cout << i + 1 ;
//              log  << " -+---+---+---+---+---+---+---+---+" <<std::endl ;
//              log << i + 1 ;
              for ( int j =0 ; j<8; j++)
              {
                std::cout << " |" ;
//                log << " |" ;
                if (grille[i][j].getCouleur() == -1 ){
                        std::cout << "  " ;
//                        log << "  " ;
                }
                else if (grille[i][j].getCouleur() == 0){
                        std::cout << " b" ;
//                        log << " b" ;
                }
                     else {
                            std::cout << " n" ;
//                            log << " n" ;
                     }
                }
                std::cout<< " |"<<std::endl;
//                log<< " |"<<std::endl;
              }
std::cout  << " ----------------------------------" << std::endl ;
//log  << " ----------------------------------" << std::endl ;
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


int Othellier::changerPion(int posx,int posy,int couleur){
    int couleuradd = 1;
    if (couleur == 1 ) {couleuradd = 0;}
    // ------------------- Vertical droite -------------------------------
    int i = posx;
     do{i++;}while((grille[i][posy].getCouleur()==couleuradd )&&(i<8));
        if (grille[i][posy].getCouleur() == couleur)
        {
            for (int j=posx+1;j<i;j++){grille[j][posy].setCouleur(couleur);}}
     // ------------------- Vertical gauche -------------------------------
     i = posx;
     do{i--;}while((grille[i][posy].getCouleur()==couleuradd) && (i >= 0 ));
        if (grille[i][posy].getCouleur() == couleur)
        {
            for (int j=posx-1;j>i;j--){grille[j][posy].setCouleur(couleur);}
        }
    // ------------------- horizontal gauche -------------------------------
     i = posy;
     do{i++;}while((grille[posx][i].getCouleur()==couleuradd) && (i < 8 ));
        if (grille[posx][i].getCouleur() == couleur)
        {
            for (int j=posy+1;j<i;j++){grille[posx][j].setCouleur(couleur);}
        }
    // ------------------- horizontal gauche -------------------------------
     i = posy;
     do{i--;}while((grille[posx][i].getCouleur()==couleuradd) && (i >= 0 ));
        if (grille[posx][i].getCouleur() == couleur)
        {
            for (int j=posy-1;j>i;j--){grille[posx][j].setCouleur(couleur);}
        }
    // ------------------- diagonal-------------------------------
    i = posx;
    int j = posy;
     do{i--;j--;}while((grille[i][j].getCouleur()==couleuradd) && (i >= 0 )&& (j >= 0 ));
        if (grille[i][j].getCouleur() == couleur)
        { while ( (i<=posx)&&(j<=posy)){
          grille[i][j].setCouleur(couleur);
          i++;j++;}
        }
    // ------------- diag 2 -----------------------
    i = posx;
    j = posy;
     do{i--;j++;}while((grille[i][j].getCouleur()==couleuradd) && (i >= 0 )&& (j < 8 ));
        if (grille[i][j].getCouleur() == couleur)
        { while ( (i<=posx)&&(j>=posy)){
          grille[i][j].setCouleur(couleur);
          i++;j--;}
        }
    // ------------- diag 3 -----------------------
     i = posx;
     j = posy;
     do{i++;j--;}while((grille[i][j].getCouleur()==couleuradd) && (j >= 0 )&& (i < 8 ));
        if (grille[i][j].getCouleur() == couleur)
        { while ( (i>=posx)&&(j<=posy)){
          grille[i][j].setCouleur(couleur);
          i++;j--;}
        }
    //------------diag 4 --------------------------
     i = posx;
     j = posy;
     do{i++;j++;}while((grille[i][j].getCouleur()==couleuradd) && (i < 8 )&& (j < 8 ));
        if (grille[i][j].getCouleur() == couleur)
        { while ( (i>=posx)&&(j>=posy)){
          grille[i][j].setCouleur(couleur);
          i--;j--;}
        }
}




void init(int* tab)
{
    for(int i = 0; i < 64 ; i++)
        tab[i] = -1;
}
