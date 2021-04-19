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
        int isBot();
        void setIsBot(int);
        void entrerNom();
        void setNom(std::string);
        virtual ~Player();

    protected:

    private:
        std::string name;
        int color = 0;
        int nbPions;
        int bot = 0; //0 si personne 1 si robot
};

#endif // PLAYER_H
