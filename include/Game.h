#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Othellier.h"
#include <string>
#include <SFML/Graphics.hpp>

class Game
{
    public:
        Game();
        void initiate(int);
        int jouerTour(int &c);
        std::string getWinner();
        Player getPlayerWinner();
        int compterPieces(int couleur);
        int scoreupdate();
        Othellier getOthellier();
        virtual ~Game();
        int gameOver();
        Player getPlayer(int);
        int startGame();
        void GUI();
        bool jouerTourGUI(int,int,int &tour,int *,int&);
        sf::Sprite pionB;
        sf::Sprite pionN;

    protected:

    private:
        Othellier othellier;
        Player players[2];
};

#endif // GAME_H
