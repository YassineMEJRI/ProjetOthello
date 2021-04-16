#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Othellier.h"
#include <string>

class Game
{
    public:
        Game();
        void initiate();
        int jouerTour(int &c);
        std::string getWinner();
        int compterPieces(int couleur);
        int scoreupdate();
        Othellier getOthellier();
        virtual ~Game();
        int gameOver();
        Player getPlayer(int);

    protected:

    private:
        Othellier othellier;
        Player players[2];
};

#endif // GAME_H
