#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED
#include<SFML/Graphics.hpp>


class GUI {
  public:
   GUI();
  ~GUI();
  sf::RenderWindow & GraphicDebutJeu(std::string & nom1, std::string & nom2, int & adversaire);
  int choicegame();
  int InitialiseJeu(int adversaire);
  int settingswindow();
  int scorewindow();
  sf::RenderWindow & DebutJeu(std::string & nom1, std::string & nom2, int & adversaire);

  private:
  sf::RenderWindow window;
  sf::Texture Background;
  sf::Texture ButtonNC;
  sf::Texture ButtonC;
  sf::Sprite ButtonPlay;
  sf::Sprite ButtonSettings;
  sf::Sprite ButtonScore;
  sf::Text playText;
  sf::Text settingsText;
  sf::Text ScoreText;
  sf::Font font;
  sf::Font font2;
  sf::Sprite BackgroundSupport;

  sf::Texture backto;
  sf::Sprite BackButton;
  sf::Texture imgOth;
  sf::Sprite bgOth;
  sf::Texture PlayervspcNC;
  sf::Sprite BtPlayervspcNC;
  sf::Texture twoPlayerNC;
  sf::Sprite BttwoPlayer;
  sf::Event event;

  sf::Texture AddName;
  sf::Texture AddNameTwoPlayer;
  sf::Sprite AddNametext;
  sf::Sprite AddNametext2;

  sf::Texture playBTN_NC;

  sf::Texture difficulty1;
  sf::Texture difficulty2;
  sf::Sprite difficultyButton;
  sf::Texture background;
  sf::Sprite backgroundAdd;
  sf::Texture music_on;
  sf::Texture music_off;
  sf::Sprite SoundAdd;
  sf::Sprite MusicAdd;


  sf::Text scoreList;

  //sf::Texture scoreBackground;
  //sf::Music //musique;
  //sf::Music sound;
  sf::Sprite MusicIconButton;
  sf::Sprite SoundIconButton;
  int initial = 0, initialSetMusic = 0, initialSetSound = 0;
  sf::Texture SoundIconOn;
  sf::Texture SoundIconOff;
  sf::Texture MusicIconOn;
  sf::Texture MusicIconOff;
  int difficulty = 1;
  int adv = 0; //=1 si VS FRIEND 0 sinon
  int initialement = 0;
  std::string nameJ1, nameJ2;
  bool startgame = false;
};

#endif // GUI_H_INCLUDED
