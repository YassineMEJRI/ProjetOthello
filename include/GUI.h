#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED
#include<SFML/Graphics.hpp>


class GUI {
    public:
        GUI();
        ~GUI();
        int GraphicDebutJeu();
        int choicegame();
        int InitialiseJeu(int adversaire, std::string & nameJ1, std::string & nameJ2);
        int settingswindow();
        int scorewindow();
        sf::RenderWindow& DebutJeu(std::string &nom1, std::string &nom2, int& adversaire);

    private:
        sf::RenderWindow window;
};

#endif // GUI_H_INCLUDED
