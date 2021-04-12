#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Othellier.h"

class Game
{
    public:
        Game();
        Player players[2];
    Othellier othellier;
    int update();
    void initiate();
    int jouerTour(Game &k,int &c);
    int gameOver();
    Player getWinner();
    int compterPieces(int couleur);
    Case* getPossibleMoves(int couleur);
        virtual ~Game();

    protected:

    private:
};

#endif // GAME_H
