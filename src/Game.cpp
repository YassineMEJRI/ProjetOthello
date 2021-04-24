#include "Game.h"
#include <stdlib.h>
#include <string>
#include <time.h>
#include "common.h"
#include <windows.h>
int trouverDansTab(int* tab, int x);
int tabEmpty(int* tab);
int random(int* tab);
int calculated_move(int* tab);

Game::Game(){}

int Game::startGame(){
        int nb = 2 ;
        int noPlay = 1; // 1 si joueur percedent a joué
        do{
            log << "noplay = " << noPlay << std::endl;
            if (!noPlay){
                    if(!(noPlay=jouerTour(nb)))
                        break;
            }
            noPlay=jouerTour(nb);
            log << "nb pions tot " << othellier.getnbPionsTotale() << std::endl;
        }while(othellier.getnbPionsTotale()<64);

        //afficher gagnant
        if (getWinner().length() == 0)
            std::cout << "Match Nul" << std::endl;
        else
            std::cout << "Le jouer " << getWinner() << " a gagné!";
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
            else if (othellier.getCase(i,j).getCouleur() == players[0].getcolor())
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
            tab = othellier.possibleMoves(players[c%2].getcolor()); // tableaux des id // possibles moves par rapport les couleurs
            for(int i =0;i<64;i++){log<<i<<":"<<tab[i]<<" ";}log<<std::endl;
            if(tabEmpty(tab)){
                std::cout << players[c%2].getName() << " ne peut rien jouer" << std::endl;
                log << players[c%2].getName() << " ne peut rien jouer" << std::endl;
                c++;
                return 0;
            }
            else{
                    if(players[c%2].isBot()){
                        int bot_move;
                        //Sleep(500);
                        if(players[c%2].isBot()==1){
                            bot_move = random(tab);
                            log << "playing a random move\n";
                        }
                        else{
                            bot_move = calculated_move(tab);
                            log << "playing a calculated move\n";
                        }
                        x = othellier.getXById(bot_move);
                        y = othellier.getYById(bot_move);
                        log << players[c%2].getName() << " a joué" << (char)(y+'a')<< x+1 << std::endl;
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
        }while(othellier.getCase(x,y).getCouleur()!=-1 || !tab[othellier.getCase(x,y).getId()]);
     // test  si le choix de la case est convenable  //  trouver dans tab : chercher l id de la case jouee dans tab
        othellier.ajouterPion(x,y,players[c%2].getcolor());
        othellier.changerPion(x,y,players[c%2].getcolor()) ;
        othellier.printBoard();


        c++;
        scoreupdate();
        return 1;
}
void Game::initiate(int adversaire)
{
    players[0].setIsBot(1);
    players[0].entrerNom();
    if(adversaire == 2){
        players[1].setIsBot(2);
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
    for(int i = 0; i < 64; i++){
        if(tab[i]!=0)
            return 0;
    }
    return 1;
}

int random(int* tab){
    int r = 0;
    srand(time(NULL));
    do{
        r = rand()%64;
    }while(tab[r] == 0);
    return r;
}

int calculated_move(int* tab){
    int best=0;
    if(tab[0])
        return 0;
    if(tab[7])
        return 7;
    if(tab[63])
        return 63;
    if(tab[56])
        return 56;
    for(int i = 1; i < 7; i++){
        if(tab[i])
            return i;
    }
    for(int i = 57; i < 63; i++){
        if(tab[i])
            return i;
    }
    for(int i = 8; i < 49; i+=8){
        if(tab[i])
            return i;
    }
    for(int i = 15; i < 63; i+=8){
        if(tab[i])
            return i;
    }
    for(int i = 0; i < 63; i++){
        if(tab[i]>tab[best])
            best = i;
    }
    return best;
}
