#include "../include/Game.h"
#include <string>
int trouverDansTab(int* tab, int x);
Game::Game(){}
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
        {players[0].increment_nbPion(1);}
        else
        {players[1].increment_nbPion(1);}}
}}
int Game::jouerTour(int &c) // nb  ddesigne  le tour de role de chaque joueur  */
{
    int* tab; // enregistre les id des cases accessibles a chaque tour
    int x,y;
    std::string a; // pour stocker l'entree du clavier
    std::cout<<"score du joueur "<<players[0].getName()<<" est : "<<players[0].getNbPions()<<std::endl;
    std::cout<<"score du joueur "<<players[1].getName()<<" est : "<<players[1].getNbPions()<<std::endl;
    if ( (c % 2) == 0)  // tour du joueur 0
        {
        do{
            std::string nom = players[0].getName();
            std::cout<<nom<<" play now"<<std::endl;
            tab = othellier.Possiblemoves(players[0].getcolor()); // tableaux des id // possibles moves par rapport les couleurs
            std::cout<<std::endl;
            std::cout<<"ajouter la position du pion a jouer  sous la forme ' lettreChiffre '"<<std::endl; // lecture de lentree de joueur
            std::cin>>a[0]>>a[1]; // 1ere char 2 eme char
            y = (a[0]-'a'); // conversion du char vers int
            x = (a[1]-'1');
           /* std::cout << "id entree  " << othellier.getCase(x,y).getId() << std::endl;*/
        }while(othellier.getCase(x,y).getCouleur()!=-1 || !trouverDansTab(tab, othellier.getCase(x,y).getId()));
     // test  si le choix de la case est convenable  //  trouver dans tab : chercher l id de la case jouee dans tab
        othellier.ajouterPion(x,y,players[0].getcolor());
        othellier.changerPion(x,y,players[0].getcolor()) ;
        othellier.printBoard();
        }
    else // tour du jour 1
        {
        do{
            std::string nom = players[1].getName();
            std::cout<<nom<<" play now"<<std::endl;
            tab = othellier.Possiblemoves(players[1].getcolor());
            std::cout<<std::endl;
            std::cout<<"ajouter la position du point sous la forme ' lettreChiffre '"<<std::endl;
            std::cin>>a[0]>>a[1];
            y = a[0]-'a';
            x = a[1]-'1';
        }while(othellier.getCase(x,y).getCouleur()!=-1 || !trouverDansTab(tab, othellier.getCase(x,y).getId()));
        othellier.ajouterPion (x,y,players[1].getcolor());
        othellier.changerPion(x,y,players[1].getcolor()) ; //
        othellier.printBoard(); //
        }
        c++;
        this->scoreupdate(); //
}
void Game::initiate()
{

    othellier.getCase(3,3).setCouleur(0);
    othellier.getCase(4,4).setCouleur(0);
    othellier.getCase(3,4).setCouleur(1);
    othellier.getCase(4,3).setCouleur(1);
    players[0].setCouleur(1);
    players[1].setCouleur(0); //randomize

    othellier.printBoard();
}



Othellier Game::getOthellier(){
    return othellier;
}


int trouverDansTab(int* tab, int x) // cherche x dans tab (x = id choisie)
{
    for(int i =0; i < 64; i++){
        //std::cout << tab[i]<<std::endl;
        if(tab[i]== x)
            return 1;
    }
    return 0;
}
