#include "Game.h"
#include <iostream>
#include "common.h"
Othellier::Othellier(){
        nbPionsTotale = 4 ;
}

int Othellier::ajouterPion (int posx ,int posy ,int couleur ) /* couleur noir ou blanc */
{
    if(grille[posx][posy].setCouleur(couleur)){
        log << "pion " << posy << posx << " " << couleur << " ajouté" << std::endl;
        nbPionsTotale++;
        return 1;
    }
    return 0;
}
int* Othellier::possibleMoves(int couleur) /* tester les cases possibles (lignes hor verti diagonale*/
{
    log << "in possible moves" << std::endl;
    init();
    // black test
    std::cout<<couleur<<std::endl;
    std::string access="";
    int couleuradd = 1;
    if (couleur == 1 ) {couleuradd = 0;}
    for( int i = 0 ; i<8 ;i++){
        for (int j = 0; j<8;j++){
            int k=j;
            if (grille[i][j].getCouleur() == couleur ){
            //---------------------- horizontal -------------------------------
             do{k++;}while((8>k)&&(grille[i][k].getCouleur() == couleuradd));
             if ((8>k)&&(j+1<k)&&(grille[i][k].getCouleur()==-1)){
                access = (char)(97+k);
                std::cout <<" | " << access <<","<< i+1;
                //ajout du jeu au tabPossibleMovesleau
                    tabPossibleMoves[grille[i][k].getId()] += k-j-1;
                  /*  std::cout << tabPossibleMoves[tailleTab] <<std::endl;*/
                  //  std::cout << i+1 << " " << access[0]-'a'<<std::endl;;
                }
             k = j;
             do{k--;}while((0<=k)&&(grille[i][k].getCouleur() == couleuradd));
             if ((j-1>k)&&(grille[i][k].getCouleur()==-1)&&(0<=k)){
                access = (char)(97+k);
                std::cout <<" | " << access <<","<< i+1;
                tabPossibleMoves[grille[i][k].getId()] += j-k-1;
              //  std::cout << tabPossibleMoves[tailleTab] <<std::endl;
                }

            //--------------- vertical verification --------------------
                k=i;
             do{k++;}while((8>k)&&(grille[k][j].getCouleur() == couleuradd));
             if ((8>k)&&(i+1<k)&&(grille[k][j].getCouleur()==-1)){
                access = (char)(97+j);
             std :: cout <<" | " << access <<","<< k+1;
             tabPossibleMoves[grille[k][j].getId()] += k-i-1;
             }
            k=i;
             do{k--;}while((0<=k)&&(grille[k][j].getCouleur() == couleuradd));
             if ((0<=k)&&(i-1>k)&&(grille[k][j].getCouleur()==-1)){
                access = (char)(97+j);
             std ::cout <<" | " << access <<","<< k+1;
             tabPossibleMoves[grille[k][j].getId()] += i-k-1;
             }


            //--------------- verification diagonal sup --------------------
             k=i;
             int k1 = j;
             do{k++; k1 ++; }while((8>k1)&&(8>k)&&(grille[k][k1].getCouleur() == couleuradd));
             if ((8>k1)&&(8>k)&&(j+1<k1)&&(i+1<k)&&(grille[k][k1].getCouleur() == -1)){
                access = (char)(97+k1);
                std::cout <<" | " << access <<","<< k+1;
                tabPossibleMoves[grille[k][k1].getId()] += k-i-1;
               // std::cout << tab[tailleTab] <<std::endl;
                }


             k=i;
             k1 = j;
             do{k--; k1 --; }while((0<=k1)&&(0<=k)&&(grille[k][k1].getCouleur() == couleuradd));
             if ((0<=k1)&&(0<=k)&&(j-1>k1)&&(i-1>k)&&(grille[k][k1].getCouleur() == -1)){
                access = (char)(97+k1);
                std::cout <<" | " << access <<","<< k+1;
                tabPossibleMoves[grille[k][k1].getId()] += i-k-1;
                // std::cout << tabPossibleMoves[tailleTab] <<std::endl;
                }

             k=i;
             k1 = j;
             do{k++; k1 --; }while((0<=k1)&&(8>k)&&(grille[k][k1].getCouleur() == couleuradd));
             if ((0<=k1)&&(8>k)&&(j-1>k1)&&(i+1<k)&&(grille[k][k1].getCouleur() == -1)){
                access = (char)(97+k1);
                std::cout <<" | " << access <<","<< k+1;
                tabPossibleMoves[grille[k][k1].getId()] += k-i-1;
                //std::cout << tabPossibleMoves[tailleTab] <<std::endl;
                }

             k=i;
             k1 = j;
             do{k--; k1 ++; }while((0<=k)&&(8>k1)&&(grille[k][k1].getCouleur() == couleuradd));
             if ((0<=k)&&(8>k1)&&(j-1>k1)&&(i-1>k)&&(grille[k][k1].getCouleur() == -1)){
                access = (char)(97+k1);
                std::cout <<" | " << access <<","<< k+1;
                tabPossibleMoves[grille[k][k1].getId()] += i-k-1;
               // std::cout << tabPossibleMoves[tailleTab] <<std::endl;
                }

        }
    }
    }
  //  std::cout << tailleTab << std::endl;
    log << "exiting possible moves" << std::endl;
    return tabPossibleMoves;
}
void  Othellier :: printBoard()
{
    system("cls");
    std::cout << "    a   b   c   d   e   f   g   h   " <<std::endl;
    log << "    a   b   c   d   e   f   g   h   " <<std::endl;
        for ( int i =0 ; i<8; i++)
            {
              std::cout  << " -+---+---+---+---+---+---+---+---+" <<std::endl ;
              std::cout << i + 1 ;
              log  << " -+---+---+---+---+---+---+---+---+" <<std::endl ;
              log << i + 1 ;
              for ( int j =0 ; j<8; j++)
              {
                std::cout << " |" ;
                log << " |" ;
                if (grille[i][j].getCouleur() == -1 ){
                        std::cout << "  " ;
                       log << grille[i][j].getId() ;
                }
                else if (grille[i][j].getCouleur() == 0){
                        std::cout << " b" ;
                        log << " b" ;
                }
                     else {
                            std::cout << " n" ;
                            log << " n" ;
                     }
                }
                std::cout<< " |"<<std::endl;
                log<< " |"<<std::endl;
              }
std::cout  << " ----------------------------------" << std::endl ;
log  << " ----------------------------------" << std::endl ;
}
Othellier::~Othellier()
{
    //dtor
}

int Othellier::getnbPionsTotale(){
return this->nbPionsTotale;}

Case & Othellier::getCase(int x, int y){
    return grille[x][y];
}


int Othellier::changerPion(int posx,int posy,int couleur){
    log << "flipping coins\n";
    int couleuradd = 1;
    if (couleur == 1 ) {couleuradd = 0;}
    // ------------------- Vertical droite -------------------------------
    int i = posx;
     do{
            i++;
     }while((grille[i][posy].getCouleur()==couleuradd )&&(i<8));
        if (grille[i][posy].getCouleur() == couleur)
        {
            for (int j=posx+1;j<i;j++){
                    grille[j][posy].setCouleur(couleur);
                    log << "in VD flipped " << posy << j << std::endl;
            }
        }
     // ------------------- Vertical gauche -------------------------------
     i = posx;
     do{
            i--;
     }while((grille[i][posy].getCouleur()==couleuradd) && (i >= 0 ));
        if (grille[i][posy].getCouleur() == couleur)
        {
            for (int j=posx-1;j>i;j--){
                    grille[j][posy].setCouleur(couleur);
                    log << "in VG flipped " << posy << j << std::endl;
            }
        }
    // ------------------- horizontal gauche -------------------------------
     i = posy;
     do{
            i++;
     }while((grille[posx][i].getCouleur()==couleuradd) && (i < 8 ));
        if (grille[posx][i].getCouleur() == couleur)
        {
            for (int j=posy+1;j<i;j++){
                    grille[posx][j].setCouleur(couleur);
                    log << "in HG flipped " << j << posx << std::endl;
            }
        }
    // ------------------- horizontal gauche -------------------------------
     i = posy;
     do{
            i--;
     }while((grille[posx][i].getCouleur()==couleuradd) && (i >= 0 ));
        if (grille[posx][i].getCouleur() == couleur)
        {
            for (int j=posy-1;j>i;j--){
                    grille[posx][j].setCouleur(couleur);
                    log << "in HG flipped " << j << posx << std::endl;
            }
        }
    // ------------------- diagonal-------------------------------
    i = posx;
    int j = posy;
     do{
            i--;
            j--;
        }while((grille[i][j].getCouleur()==couleuradd) && (i >= 0 )&& (j >= 0 ));
        if (grille[i][j].getCouleur() == couleur)
        {
            while ( (i<=posx)&&(j<=posy)){
            grille[i][j].setCouleur(couleur);
            log << "in diag flipped " << j << i << std::endl;
            i++;
            j++;
            }
        }
    // ------------- diag 2 -----------------------
    i = posx;
    j = posy;
     do{
            i--;
            j++;
        }while((grille[i][j].getCouleur()==couleuradd) && (i >= 0 )&& (j < 8 ));
        if (grille[i][j].getCouleur() == couleur)
        {
            while ( (i<=posx)&&(j>=posy)){
            grille[i][j].setCouleur(couleur);
            log << "in diag2 flipped " << j << i << std::endl;
            i++;
            j--;
            }
        }
    // ------------- diag 3 -----------------------
     i = posx;
     j = posy;
     do{
            i++;
            j--;
        }while((grille[i][j].getCouleur()==couleuradd) && (j >= 0 )&& (i < 8 ));
        if (grille[i][j].getCouleur() == couleur)
        {
            while ( (i>=posx)&&(j<=posy)){
                grille[i][j].setCouleur(couleur);
                log << "in diag3 flipped " << j << i << std::endl;
                i--;
                j++;
            }
        }
    //------------diag 4 --------------------------
     i = posx;
     j = posy;
     do{
            i++;
            j++;
        }while((grille[i][j].getCouleur()==couleuradd) && (i < 8 )&& (j < 8 ));
        if (grille[i][j].getCouleur() == couleur)
        {
            while ( (i>=posx)&&(j>=posy)){
            grille[i][j].setCouleur(couleur);
            log << "in diag4 flipped " << j << i << std::endl;
            i--;
            j--;
            }
        }
}

int Othellier::getXById(int id){
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            if(grille[i][j].getId() == id)
                return i;
        }
    }
    return -1;
}
int Othellier::getYById(int id){
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            if(grille[i][j].getId() == id)
                return j;
        }
    }
    return -1;
}




void Othellier::init()
{
    for(int i = 0; i < 64 ; i++)
        tabPossibleMoves[i] = 0;
}
