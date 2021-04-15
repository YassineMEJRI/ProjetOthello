#ifndef PLAYER_H
#define PLAYER_H
#include <string>


class Player
{
    public:
        Player();
        std::string getName();
        int getcolor();
        void setCouleur(int coul);
        int getNbPions();
        void  setNbPions(int x );
        int increment_nbPion(int);
        virtual ~Player();

    protected:

    private:
        std::string name;
        int color = 0;
        int nbPions;
};

#endif // PLAYER_H
