#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Othellier.h"
#include <string>
#include <SFML/Graphics.hpp>
#include "LeaderBoard.h"
#include "GUI.h"

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
        void playGUI(sf::RenderWindow &);
        bool jouerTourGUI(int,int,int &tour,int *,int&);
        void randomizeFirstPlayer();
        int startGameGUI();

        sf::Sprite pionB;
        sf::Sprite pionN;

    protected:

    private:
        GUI gui;
        Othellier othellier;
        Player players[2];
        LeaderBoard leaderBoard;
};

#endif // GAME_H
