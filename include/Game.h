#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Othellier.h"

class Game
{
    public:
        Game();
        void initiate();
        int jouerTour(int &c);
        Player getWinner();
        int compterPieces(int couleur);
        int scoreupdate();
        Othellier getOthellier();
        virtual ~Game();
        /*int gameOver();*/

    protected:

    private:
        Othellier othellier;
        Player players[2];
};

#endif // GAME_H
