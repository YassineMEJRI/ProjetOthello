#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Othellier.h"

class Game
{
    public:
        Game();
        int update();
        void initiate();
        int jouerTour(Game &k,int &c);
        int gameOver();
        Player getWinner();
        int compterPieces(int couleur);
        Case* getPossibleMoves(int couleur);
        int scoreupdate();
        Othellier getOthellier();
        virtual ~Game();

    protected:

    private:
        Othellier othellier;
        Player players[2];
};

#endif // GAME_H
