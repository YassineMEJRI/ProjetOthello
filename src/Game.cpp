#include "../include/Game.h"
#include <stdlib.h>
#include <string>
#include <time.h>
#include "common.h"
#include <windows.h>
int trouverDansTab(int* tab, int x);
int tabEmpty(int* tab);
int random(int* tab);

Game::Game(){}

int Game::startGame(){
        int nb = 2 ;
        int noPlay = 1; // 1 si joueur percedent a joué
        do{
            log << "noplay = " << noPlay << std::endl;
            if (!(noPlay=this->jouerTour(nb) || noPlay)){
                break;
            }
            log << "nb pions tot " << othellier.getnbPionsTotale() << std::endl;
        }while(othellier.getnbPionsTotale()<64);

        //afficher gagnant
        if (this->getWinner().length() == 0)
            std::cout << "Match Nul" << std::endl;
        else
            std::cout << "Le jouer " << this->getWinner() << " a gagné!";
        std::cout << "Le score final:\n" << players[0].getName() << " : " << players[0].getNbPions() << std::endl;
        std::cout << players[1].getName() << " : " << players[1].getNbPions() << std::endl;

        return 0;
}

Game::~Game(){}
int Game::scoreupdate()
{
  players[0].setNbPions( 0); // set 0 et compter le nbr de pions de chaque joueur dans la grille .
  players[1].setNbPions(0);
    for ( int i =0 ; i<8; i++)
    {
        for ( int j =0 ; j<8; j++)
        {
            if (othellier.getCase(i,j).getCouleur() == -1 ){ /*rien a faire */}
            else if (othellier.getCase(i,j).getCouleur() == 0)
            {
                players[0].increment_nbPion(1);
            }
            else
            {
                players[1].increment_nbPion(1);
            }
        }
    }
}
int Game::jouerTour(int &c) // nb  ddesigne  le tour de role de chaque joueur  */
{
    int* tab; // enregistre les id des cases accessibles a chaque tour
    int x,y;
    std::string a; // pour stocker l'entree du clavier
    std::cout<<"score du joueur "<<players[0].getName()<<" est : "<<players[0].getNbPions()<<std::endl;
    std::cout<<"score du joueur "<<players[1].getName()<<" est : "<<players[1].getNbPions()<<std::endl;

        do{
            std::string nom = players[c%2].getName();
            std::cout<<nom<<" play now"<<std::endl;
            log<<nom<<" play now"<<std::endl;
            tab = othellier.Possiblemoves(players[c%2].getcolor()); // tableaux des id // possibles moves par rapport les couleurs
            if(tabEmpty(tab)){
                std::cout << players[c%2].getName() << " ne peut rien jouer" << std::endl;
                c++;
                return 0;
            }
            else{
                    if(players[c%2].isBot()){
                        //Sleep(500);
                        int random_move = random(tab);
                        x = othellier.getXById(random_move);
                        y = othellier.getYById(random_move);
                        log << "ordinateur a joué" << x << y << std::endl;
                        break;
                    }
                    else{
                        std::cout<<std::endl;
                        std::cout<<"ajouter la position du pion a jouer  sous la forme ' lettreChiffre '"<<std::endl; // lecture de lentree de joueur
                        std::cin>>a[0]>>a[1]; // 1ere char 2 eme char
                        y = (a[0]-'a'); // conversion du char vers int
                        x = (a[1]-'1');
                        log << a[0] << a[1] << std::endl;
                    }
            }
           /* std::cout << "id entree  " << othellier.getCase(x,y).getId() << std::endl;*/
        }while(othellier.getCase(x,y).getCouleur()!=-1 || !trouverDansTab(tab, othellier.getCase(x,y).getId()));
     // test  si le choix de la case est convenable  //  trouver dans tab : chercher l id de la case jouee dans tab
        othellier.ajouterPion(x,y,players[c%2].getcolor());
        othellier.changerPion(x,y,players[c%2].getcolor()) ;
        othellier.printBoard();


        c++;
        this->scoreupdate();
        return 1;
}
void Game::initiate(int adversaire)
{
    players[0].setIsBot(1);
    players[0].entrerNom();
    if(adversaire == 2){
        players[1].setIsBot(1);
        players[1].setNom("ordinateur");
    }
    else{
        players[1].setIsBot(0);
        players[1].entrerNom();
    }

    othellier.getCase(3,3).setCouleur(0);
    othellier.getCase(4,4).setCouleur(0);
    othellier.getCase(3,4).setCouleur(1);
    othellier.getCase(4,3).setCouleur(1);
    players[0].setCouleur(1);
    players[1].setCouleur(0); //randomize

    othellier.printBoard();
}

std::string Game::getWinner(){
    if(players[0].getNbPions() > players[1].getNbPions())
            return players[0].getName();
    else if(players[0].getNbPions() < players[1].getNbPions())
            return players[1].getName();
        else
            return "";
}

Player Game::getPlayer(int x){
    return players[x];
}



Othellier Game::getOthellier(){
    return othellier;
}

int tabEmpty(int* tab){
    if(tab[0] == -1)
        return 1;
    return 0;
}
int trouverDansTab(int* tab, int x) // cherche x dans tab (x = id choisie)
{
    for(int i =0; i < 64; i++){
        log << " " << tab[i];
        if(tab[i]== x){
            log << std::endl;
            return 1;
        }
    }
    log << std::endl;
    return 0;
}

int random(int* tab){
    int r = -1;
    srand(time(NULL));
    do{
        r = tab[rand()%64];
    }while(r == -1);
    return r;
}
