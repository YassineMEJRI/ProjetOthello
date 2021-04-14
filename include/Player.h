#ifndef PLAYER_H
#define PLAYER_H
#include <string>


class Player
{
    public:
        Player();
        std::string Getname(Player a);
        int getcolor();
        void SetcolorPlayer(Player &a ,int b);
        int getnbpoint(){ return nbPions;};
        int setnbpoint(){ nbPions = 0;};
        int increment_nbPion(int);
        virtual ~Player();

    protected:

    private:
        std::string name;
        int color = 0;
        int nbPions;
};

#endif // PLAYER_H
