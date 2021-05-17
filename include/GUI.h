#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED
#include<SFML/Graphics.hpp>


class GUI {
    public:
        GUI();
        ~GUI();
        sf::RenderWindow & GraphicDebutJeu(std::string &nom1, std::string &nom2, int& adversaire);
        int choicegame();
        int InitialiseJeu(int adversaire);
        int settingswindow();
        int scorewindow();
        sf::RenderWindow& DebutJeu(std::string &nom1, std::string &nom2, int& adversaire);

    private:
        sf::RenderWindow window;
};

#endif // GUI_H_INCLUDED
