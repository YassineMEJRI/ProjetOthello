#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#include <map>
#include <string>
#include <fstream>
#include <map>

class LeaderBoard
{
    public:
        LeaderBoard();
        void addScore(std::string,int);
        std::map<std::string,int> getListe();
        void writeListeToFile();
        void readListeFromFile();
        void affiche();
        std::multimap<int,std::string,std::greater<int>> getSortedByScore();
        virtual ~LeaderBoard();

    protected:

    private:
        std::map<std::string,int> liste;
        std::fstream fichierScores;
};

#endif // LEADERBOARD_H
