#include "GUI.h"

#include "iostream"

#include "LeaderBoard.h"

//#include <SFML/Audio.hpp>

//sf::Music musique;
//sf::Music sound;
sf::Sprite MusicIconButton;
sf::Sprite SoundIconButton;
int initial = 0, initialSetMusic = 0, initialSetSound = 0;
sf::Texture SoundIconOn;
sf::Texture SoundIconOff;
sf::Texture MusicIconOn;
sf::Texture MusicIconOff;
int difficulty = 1;
int adv = 0;//=1 si VS FRIEND 0 sinon
int initialement = 0;
std::string nameJ1, nameJ2;
bool startgame=false;
 GUI::GUI(){
    window.create(sf::VideoMode(1000, 700), "Othello", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(30);
    window.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - 500, 0));

    sf::Image icon;
    icon.loadFromFile("img/icon.png");
    const uint8_t * iconBlock = icon.getPixelsPtr();
    window.setIcon(50, 49, iconBlock);
 }
/*sf::RenderWindow & GUI::DebutJeu(std::string & nom1, std::string & nom2, int &adversaire) {


  int statue = GraphicDebutJeu();
  std::cout << statue << std::endl;
  if (statue == 1) {
    window.clear();
    //std::string name[2];
    do {
      statue = choicegame(); // = CPU si 2 // = FRIEND si 1
      if(statue == 1){
        adversaire = 0;
      }
        else if(statue == 2){
        if(difficulty == 1)
            adversaire = 1;
        else
            adversaire = 2;
      }
      if (statue == 5) //retour
        DebutJeu(nom1,nom2, adversaire);
      InitialiseJeu(statue, nom1, nom2);
    } while (statue == 5);
    //players[0].setNom(name[0]);
    //players[1].setNom(name[1]);
    //initiate(statue,name[0],name[1]);
    std::cout << "baaed l'initialise";
    //GUI(window);
    return window;
  } else if (statue == 10) {
    settingswindow();
    DebutJeu(nom1, nom2, adversaire);
  } else if (statue == 20) {
    window.clear();
    scorewindow();
    DebutJeu(nom1, nom2, adversaire);
  }
}*/
sf::RenderWindow& GUI::GraphicDebutJeu(std::string &nom1, std::string &nom2, int& adversaire) {
  if (initial == 0) {
    //musique.openFromFile("music.ogg");
    //sound.setVolume(30);
    //musique.setVolume(50);
    //musique.play();
    initial++;
  }
  std::cout << initial;
  sf::Texture Background;
  Background.loadFromFile("img/play/BackGround.png");

  sf::Texture ButtonNC;
  ButtonNC.loadFromFile("img/play/button.png");

  sf::Texture ButtonC;
  ButtonC.loadFromFile("img/play/Button_Clicked.png");

  sf::Font font;
  sf::Font font2;
  font2.loadFromFile("square_721_bt.ttf");
  font.loadFromFile("AvenirLTStd-Black.otf");

  sf::Sprite ButtonPlay;
  sf::Sprite ButtonSettings;
  sf::Sprite ButtonScore;

  sf::Text playText;
  sf::Text settingsText;
  sf::Text ScoreText;
  //------------------------------------
  ButtonPlay.setPosition(374, 174);
  ButtonPlay.setTexture(ButtonNC);
  playText.setPosition(440, 181);
  playText.setString("play");
  //------------------------------------
  ButtonSettings.setPosition(374, 316);
  ButtonSettings.setTexture(ButtonNC);
  settingsText.setPosition(400, 332);
  settingsText.setString("settings");
  //-----------------------------------
  ButtonScore.setPosition(374, 458);
  ButtonScore.setTexture(ButtonNC);
  ScoreText.setPosition(408, 462);
  ScoreText.setString("score");
  //-----------------------------------
  playText.setFont(font2);
  playText.setCharacterSize(65);
  playText.setFillColor(sf::Color::White);
  //-----------------------------------
  settingsText.setFont(font2);
  settingsText.setCharacterSize(48);
  settingsText.setFillColor(sf::Color::White);
  //-----------------------------------
  ScoreText.setFont(font2);
  ScoreText.setCharacterSize(65);
  ScoreText.setFillColor(sf::Color::White);
  //-----------------------------------
  sf::Sprite BackgroundSupport(Background);
  bool mouseIn = false;
  while (window.isOpen()) {

        if(startgame){
                if(adv==1)
                    adversaire = 3;
                else
                    adversaire = difficulty;
                nom1=nameJ1;nom2=nameJ2;

        return window;}
    //musique.getLoop();
    window.draw(BackgroundSupport);
    sf::Event event;
    sf::Vector2i pos = sf::Mouse::getPosition(window);
    int MouseX = pos.x;
    int MouseY = pos.y;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
      //---------------------- Mouse Moved ----------------------------
      if (event.type == sf::Event::MouseMoved) {
        if (MouseX > 374 && MouseX < 634 && MouseY > 163 && MouseY < 266) {
          ButtonPlay.setPosition(374, 170);
          ButtonPlay.setTexture(ButtonC);
          playText.setPosition(440, 177);
        } else {
          ButtonPlay.setPosition(374, 174);
          ButtonPlay.setTexture(ButtonNC);
          playText.setPosition(440, 181);

        }
        //-------------------Settings Bouton ------------------------------
        if (MouseX > 374 && MouseX < 634 && MouseY > 316 && MouseY < 419) {
          // if(initialSetSound==0&&!mouseIn){sound.play();mouseIn=true;}
          ButtonSettings.setPosition(374, 312);
          ButtonSettings.setTexture(ButtonC);
          settingsText.setPosition(400, 328);
        } else { //mouseIn=false;
          ButtonSettings.setPosition(374, 316);
          ButtonSettings.setTexture(ButtonNC);
          settingsText.setPosition(400, 332);
        }
        //---------------------score bouton ----------------------------------
        if (MouseX > 374 && MouseX < 634 && MouseY > 454 && MouseY < 557) {
          //  if(initialSetSound==0&&!mouseIn){sound.play();mouseIn=true;}
          ButtonScore.setPosition(374, 454);
          ButtonScore.setTexture(ButtonC);
          ScoreText.setPosition(408, 458);
        } else {
          ButtonScore.setPosition(374, 458);
          ButtonScore.setTexture(ButtonNC);
          ScoreText.setPosition(408, 462);
        }
      }
      //---------------------------------------------------------------------
      if (event.type == sf::Event::MouseButtonPressed) {
        if (event.key.code == sf::Mouse::Left) {
          if (MouseX > 374 && MouseX < 634 && MouseY > 163 && MouseY < 266) {
                choicegame();
            //return 1; //PLAY
          } else if (MouseX > 374 && MouseX < 634 && MouseY > 316 && MouseY < 419) {
              settingswindow();
            //return 10; //SETTINGS
          } else if (MouseX > 374 && MouseX < 634 && MouseY > 454 && MouseY < 557) {
              scorewindow();
            //return 20; //SCORE
          }
        }

      }
    }

    if (!mouseIn) {
      if (MouseX > 374 && MouseX < 634 && MouseY > 163 && MouseY < 266)
        if (initialSetSound == 0) {
          //sound.openFromFile("ding.flac");
          //sound.play();
          mouseIn = true;
        }
      if (MouseX > 374 && MouseX < 634 && MouseY > 316 && MouseY < 419)
        if (initialSetSound == 0) {
          //sound.openFromFile("ding.flac");
          //sound.play();
          mouseIn = true;
        }
      if (MouseX > 374 && MouseX < 634 && MouseY > 454 && MouseY < 557)
        if (initialSetSound == 0) {
          //sound.openFromFile("ding.flac");
          //sound.play();
          mouseIn = true;
        }
    }
    if (!(MouseX > 374 && MouseX < 634 && MouseY > 163 && MouseY < 266) && !(MouseX > 374 && MouseX < 634 && MouseY > 316 && MouseY < 419) && !(MouseX > 374 && MouseX < 634 && MouseY > 454 && MouseY < 557)) mouseIn = false;
    std::cout << mouseIn << std::endl;
    if(!startgame){
    window.draw(ButtonPlay);
    window.draw(playText);
    window.draw(ButtonSettings);
    window.draw(settingsText);
    window.draw(ButtonScore);
    window.draw(ScoreText);
    window.display();
    }
  }
}
int GUI::choicegame() {
  sf::Texture backto;
  backto.loadFromFile("img/commun/back.png");
  sf::Sprite BackButton(backto);
  BackButton.setPosition(50, 60);
  sf::Texture imgOth;
  imgOth.loadFromFile("img/gameBegin/BackgroundImg2.png");
  imgOth.setSmooth(true);
  sf::Sprite bgOth(imgOth);
  sf::Texture PlayervspcNC;
  PlayervspcNC.loadFromFile("img/gameBegin/PlayervspcNC.png");
  PlayervspcNC.setSmooth(true);
  sf::Sprite BtPlayervspcNC(PlayervspcNC);
  BtPlayervspcNC.setPosition(291, 217);
  sf::Texture twoPlayerNC;
  twoPlayerNC.loadFromFile("img/gameBegin/twoPlayerNC.png");
  twoPlayerNC.setSmooth(true);
  sf::Sprite BttwoPlayer(twoPlayerNC);
  BttwoPlayer.setPosition(291, 427);
  MusicIconOn.loadFromFile("img/commun/music_on.png");
  MusicIconOff.loadFromFile("img/commun/music_off.png");
  if (initialSetMusic == 0) MusicIconButton.setTexture(MusicIconOn);
  else MusicIconButton.setTexture(MusicIconOff);
  MusicIconButton.setPosition(25, 570);
  SoundIconOn.loadFromFile("img/commun/sound_on.png");
  SoundIconOff.loadFromFile("img/commun/sound_off.png");
  if (initialSetSound == 0) SoundIconButton.setTexture(SoundIconOn);
  else SoundIconButton.setTexture(SoundIconOff);
  SoundIconButton.setPosition(25, 630);
  bool mouseIn = false;
  while (window.isOpen()) {
        if(startgame)
            return 0;
    //sound.getLoop();
    //musique.getLoop();
    window.draw(bgOth);
    window.draw(BtPlayervspcNC);
    window.draw(BttwoPlayer);
    sf::Event event;
    sf::Vector2i pos = sf::Mouse::getPosition(window);
    int i = pos.x;
    int j = pos.y;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
      if (event.type == sf::Event::MouseMoved) {
        if (i > 291 && i < 291 + 430 && j > 217 && j < 217 + 175) {
          BtPlayervspcNC.setPosition(291, 213);
          PlayervspcNC.loadFromFile("img/gameBegin/PlayervspcC.png");
        } else {
          BtPlayervspcNC.setPosition(291, 217);
          PlayervspcNC.loadFromFile("img/gameBegin/PlayervspcNC.png");
        }
        if (i > 291 && i < 291 + 430 && j > 427 && j < 427 + 175) {
          BttwoPlayer.setPosition(291, 424);
          twoPlayerNC.loadFromFile("img/gameBegin/twoPlayerC.png");
        } else {
          BttwoPlayer.setPosition(291, 427);
          twoPlayerNC.loadFromFile("img/gameBegin/twoPlayerNC.png");
        }
        if (i > 50 && i < 50 + 36 && j > 60 && j < 60 + 51) {
          BackButton.setPosition(50, 57);
        } else {
          BackButton.setPosition(50, 60);
        }
      }
      if (event.type == sf::Event::MouseButtonPressed)
        if (event.key.code == sf::Mouse::Left) {
          if (i > 291 && i < 291 + 430 && j > 217 && j < 217 + 175) {
                adv = 0;
                InitialiseJeu(2);
            //return 2; //VS CPU
          }
          if (i > 291 && i < 291 + 430 && j > 427 && j < 427 + 175) {
                adv=1;
              InitialiseJeu(1);
            //return 1; //VS FRIEND
          }
          if (i > 50 && i < 50 + 36 && j > 60 && j < 60 + 51) {
              return 0;
            //return 5; //retour
          }
          if (i > 25 && i < 75 && j > 570 && j < 620)
            if (initialSetMusic == 0) {
              MusicIconButton.setTexture(MusicIconOff);
              initialSetMusic = 1;
              //musique.pause();
            }
          else {
            MusicIconButton.setTexture(MusicIconOn);
            initialSetMusic = 0;
            //musique.play();
          }
          if (i > 25 && i < 75 && j > 630 && j < 680)
            if (initialSetSound == 0) {
              SoundIconButton.setTexture(SoundIconOff);
              initialSetSound = 1;
              //sound.pause();
            }
          else {
            SoundIconButton.setTexture(SoundIconOn);
            initialSetSound = 0;
            //sound.play();
          }
        }

      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed)
        window.close();
    }
    if (!mouseIn) {
      if (i > 291 && i < 291 + 430 && j > 217 && j < 217 + 175)
        if (initialSetSound == 0) {
          //sound.openFromFile("ding.flac");
          //sound.play();
          mouseIn = true;
        }
      if (i > 291 && i < 291 + 430 && j > 427 && j < 427 + 175)
        if (initialSetSound == 0) {
          //sound.openFromFile("ding.flac");
          //sound.play();
          mouseIn = true;
        }
      if (i > 50 && i < 50 + 36 && j > 60 && j < 60 + 51)
        if (initialSetSound == 0) {
          //sound.openFromFile("ding.flac");
          //sound.play();
          mouseIn = true;
        }
    }
    if (!(i > 291 && i < 291 + 430 && j > 217 && j < 217 + 175) && !(i > 291 && i < 291 + 430 && j > 427 && j < 427 + 175) && !(i > 50 && i < 50 + 36 && j > 60 && j < 60 + 51)) mouseIn = false;
    if(!startgame){
    window.draw(BackButton);
    window.draw(MusicIconButton);
    window.draw(SoundIconButton);
    window.display();
    }
  }
}
int GUI::InitialiseJeu(int adversaire) {
  sf::Texture AddName;
  AddName.loadFromFile("img/gameBegin/AddNamePlayer.png");
  AddName.setSmooth(true);
  sf::Texture backto;
  backto.loadFromFile("img/commun/back.png");
  sf::Sprite BackButton(backto);
  BackButton.setPosition(50, 60);
  sf::Texture AddNameTwoPlayer;
  AddNameTwoPlayer.loadFromFile("img/gameBegin/AddNameTwoPlayer.png");
  AddNameTwoPlayer.setSmooth(true);
  sf::Sprite AddNametext(AddName);
  sf::Sprite AddNametext2;
  AddNametext.setPosition(210, 350);
  sf::Texture imgOth;
  imgOth.loadFromFile("img/gameBegin/BackgroundImg2.png");
  imgOth.setSmooth(true);
  sf::Sprite bgOth(imgOth);
  sf::Texture PlayervspcNC;
  PlayervspcNC.loadFromFile("img/gameBegin/PlayervspcNC.png");
  PlayervspcNC.setSmooth(true);
  sf::Sprite BtPlayervspcNC(PlayervspcNC);
  BtPlayervspcNC.setPosition(291, 217);
  sf::Texture twoPlayerNC;
  twoPlayerNC.loadFromFile("img/gameBegin/twoPlayerNC.png");
  twoPlayerNC.setSmooth(true);
  sf::Sprite BttwoPlayer(twoPlayerNC);
  BttwoPlayer.setPosition(291, 427);
  sf::Texture playBTN_NC;
  playBTN_NC.loadFromFile("img/gameBegin/playBTN_NC.png");
  playBTN_NC.setSmooth(true);
  sf::Sprite BtplayBTN_NC(playBTN_NC);
  sf::String playerInput;
  sf::Text playerText;
  sf::String playerInput1;
  sf::Text playerText1;
  sf::Font font;
  sf::Font font2;
  font2.loadFromFile("square_721_bt.ttf");
  font.loadFromFile("AvenirLTStd-Black.otf");
  sf::Text error;
  playBTN_NC.loadFromFile("img/gameBegin/playBTN_C.png");
  BtplayBTN_NC.setPosition(393, 591);
  MusicIconOn.loadFromFile("img/commun/music_on.png");
  MusicIconOff.loadFromFile("img/commun/music_off.png");
  if (initialSetMusic == 0) MusicIconButton.setTexture(MusicIconOn);
  else MusicIconButton.setTexture(MusicIconOff);
  MusicIconButton.setPosition(25, 570);
  SoundIconOn.loadFromFile("img/commun/sound_on.png");
  SoundIconOff.loadFromFile("img/commun/sound_off.png");
  if (initialSetSound == 0) SoundIconButton.setTexture(SoundIconOn);
  else SoundIconButton.setTexture(SoundIconOff);
  SoundIconButton.setPosition(25, 630);
  window.clear();
  int inc = 427;
  int k = 207;
  int inj = 29;
  bool boolean = false;
  bool boolean1 = false;
  int bol = 0, bol1 = 0;
  bool mouseIn = false;
  while (window.isOpen()) {
    sf::Vector2i pos = sf::Mouse::getPosition(window);
    int i = pos.x;
    int j = pos.y;
    //sound.getLoop();
    //musique.getLoop();
    if (adversaire == 2) {

      window.draw(bgOth);
      window.draw(AddNametext);
      window.draw(BtPlayervspcNC);

      sf::Event event;
      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
          window.close();
        if (event.type == sf::Event::MouseMoved) {
          if (i > 50 && i < 50 + 36 && j > 60 && j < 60 + 51) {
            BackButton.setPosition(50, 57);
          } else {
            BackButton.setPosition(50, 60);
          }
          if (j > 594 && j < 594 + 85 && i > 393 && i < 393 + 207) {
            playBTN_NC.loadFromFile("img/gameBegin/playBTN_C.png");
            BtplayBTN_NC.setPosition(393, 591);
          } else {
            playBTN_NC.loadFromFile("img/gameBegin/playBTN_NC.png");
            BtplayBTN_NC.setPosition(393, 594);
          }
        }

        if (event.type == sf::Event::MouseButtonPressed) {
          if (!boolean) {
            if (event.key.code == sf::Mouse::Left) {
              if (j > 469 && j < 469 + 67 && i > 326 && i < 326 + 377) {
                boolean = true;
                playerInput += "_";
              } else boolean = false;
            }
          }
        }
        if (boolean) {
          playerText.setString(playerInput);
          if (event.type == sf::Event::TextEntered) {
            if ((event.text.unicode > 64) && (event.text.unicode < 91) || (event.text.unicode > 96) && (event.text.unicode < 123)) {
              if (playerInput.getSize() < 9) {
                if (playerInput.getSize() != 0) {
                  playerInput.erase(playerInput.getSize() - 1);
                }
                playerInput += event.text.unicode;
                playerInput += "_";
                playerText.setString(playerInput);
              }
            }
            if (event.text.unicode == 8) {
              if (playerInput.getSize() != 0)
                playerInput.erase(playerInput.getSize() - 1);
              playerText.setString(playerInput);
            }
            if ((event.text.unicode == 13)) {
              if (playerInput.getSize() != 0) {
                playerInput.erase(playerInput.getSize() - 1);
                nameJ1 = playerInput;
                nameJ2 = "ordinateur";
                startgame = true;
                return difficulty;
              } else {
                error.setPosition(430, 540);
                error.setString("name invalid");
                error.setCharacterSize(23);
                error.setFillColor(sf::Color::Red);
                error.setFont(font2);
              }
            }
          }
        }
        if (event.type == sf::Event::MouseButtonPressed)
          if (event.key.code == sf::Mouse::Left) {
            if (j > 594 && j < 594 + 85 && i > 393 && i < 393 + 207) { //PLAY
              if (playerInput.getSize() != 0) {

                playerInput.erase(playerInput.getSize() - 1);
                nameJ1 = playerInput;
                nameJ2 = "ordinateur";
                startgame = true;
                return difficulty;
              } else {
                error.setPosition(430, 540);
                error.setString("name invalid");
                error.setCharacterSize(23);
                error.setFillColor(sf::Color::Red);
                error.setFont(font2);
              }
            }
            if (i > 50 && i < 50 + 36 && j > 60 && j < 60 + 51) { //RETOUR
              return 5;
            }
            if (i > 25 && i < 75 && j > 570 && j < 620) { //MUSIC
              if (initialSetMusic == 0) {
                MusicIconButton.setTexture(MusicIconOff);
                initialSetMusic = 1;
                //musique.pause();
              } else {
                MusicIconButton.setTexture(MusicIconOn);
                initialSetMusic = 0;
                //musique.play();
              }
            }
            if (i > 25 && i < 75 && j > 630 && j < 680) { //SOUND
              if (initialSetSound == 0) {
                SoundIconButton.setTexture(SoundIconOff);
                initialSetSound = 1;
                //sound.pause();
              } else {
                SoundIconButton.setTexture(SoundIconOn);
                initialSetSound = 0;
                //sound.play();
              }
            }
      }
    }
    if (!mouseIn) {
      if (i > 50 && i < 50 + 36 && j > 60 && j < 60 + 51)
        if (initialSetSound == 0) {
          //sound.openFromFile("ding.flac");
          //sound.play();
          mouseIn = true;
        }
      if (j > 594 && j < 594 + 85 && i > 393 && i < 393 + 207)
        if (initialSetSound == 0) {
          //sound.openFromFile("ding.flac");
          //sound.play();
          mouseIn = true;
        }
    }
    if (!(i > 50 && i < 50 + 36 && j > 60 && j < 60 + 51) && !(j > 594 && j < 594 + 85 && i > 393 && i < 393 + 207))
        mouseIn = false;

    playerText.setPosition(380, 480);
    playerText.setFont(font);
    playerText.setFillColor(sf::Color::White);
    playerText.setCharacterSize(30);
    window.draw(playerText);
    window.draw(BtplayBTN_NC);
    window.draw(error);
    window.draw(BackButton);
  } else {
    window.draw(bgOth);
    if (inc > 207) {
      window.draw(BttwoPlayer);
      BttwoPlayer.setPosition(291, inc);
      inc -= inj;
      inj -= 2;
    } else if (k < 225) {
      window.draw(BttwoPlayer);
      BttwoPlayer.setPosition(291, k);
      k += inj;
      inj += 2;
    } else {
      AddNametext2.setPosition(87, 350);
      AddNametext2.setTexture(AddNameTwoPlayer);
      window.draw(AddNametext2);
      window.draw(BttwoPlayer);
      sf::Event event;
      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
          window.close();
        if (event.type == sf::Event::MouseButtonPressed) {
          if (!boolean)
            if (j > 461 && j < 461 + 67 && i > 144 && i < 144 + 323) {
              boolean = true;
              if (bol == 0) playerInput += "_";
              bol = 1;
            } else {
              boolean = false;
              if (bol == 1) {
                playerInput.erase(playerInput.getSize() - 1);
                playerText.setString(playerInput);
                bol = 0;
              }
            }
          if (!boolean1)
            if (j > 461 && j < 461 + 67 && i > 590 && i < 590 + 323) {
              boolean1 = true;
              if (bol1 == 0) playerInput1 += "_";
              bol1 = 1;
            } else {
              boolean1 = false;
              if (bol1 == 1) {
                playerInput1.erase(playerInput1.getSize() - 1);
                playerText1.setString(playerInput1);
                bol1 = 0;
              }
            }
        }
        if (boolean == true) {
          playerText.setString(playerInput);
          if (event.type == sf::Event::TextEntered) {
            if ((event.text.unicode > 64) && (event.text.unicode < 91) || (event.text.unicode > 96) && (event.text.unicode < 123)) {
              if (playerInput.getSize() < 9) {
                if (playerInput.getSize() != 0) {
                  playerInput.erase(playerInput.getSize() - 1);
                }
                playerInput += event.text.unicode;
                playerInput += "_";
                playerText.setString(playerInput);
              }
            }
            if (event.text.unicode == 8) {
              if (playerInput.getSize() != 0)
                playerInput.erase(playerInput.getSize() - 1);
              playerText.setString(playerInput);
            }
          }
        }
        if (boolean1 == true) {
          playerText1.setString(playerInput1);
          if (event.type == sf::Event::TextEntered) {
            if ((event.text.unicode > 64) && (event.text.unicode < 91) || (event.text.unicode > 96) && (event.text.unicode < 123)) {
              if (playerInput1.getSize() < 9) {
                if (playerInput1.getSize() != 0) {
                  playerInput1.erase(playerInput1.getSize() - 1);
                }
                playerInput1 += event.text.unicode;
                playerInput1 += "_";
                playerText1.setString(playerInput1);
              }
            }
            if (event.text.unicode == 8) {
              if (playerInput1.getSize() != 0)
                playerInput1.erase(playerInput1.getSize() - 1);
              playerText1.setString(playerInput1);
            }
          }
        }
        if (event.type == sf::Event::TextEntered) {
          if ((event.text.unicode == 13)) {
            if ((playerInput1.getSize() != 0) && (playerInput.getSize() != 0)) {
              nameJ1 = playerInput1;
              nameJ2 = playerInput;
              return 1;
            } else {
              error.setPosition(430, 540);
              error.setString("name invalid");
              error.setCharacterSize(23);
              error.setFillColor(sf::Color::Red);
              error.setFont(font2);
            }
          }
        }

        if (event.type == sf::Event::MouseButtonPressed) {
          if (event.key.code == sf::Mouse::Left) {
            if (i > 50 && i < 50 + 36 && j > 60 && j < 60 + 51) {
              return 5;
            }
            if (j > 594 && j < 594 + 85 && i > 393 && i < 393 + 207) {
              if (playerInput == playerInput1) {
                error.setPosition(360, 540);
                error.setString("two name is the same");
                error.setCharacterSize(23);
                error.setFillColor(sf::Color::Red);
                error.setFont(font2);
              } else
              if ((playerInput1.getSize() != 0) && (playerInput.getSize() != 0)) {
                nameJ1 = playerInput1;
                nameJ2 = playerInput;
                return 1;
              } else {
                error.setPosition(430, 540);
                error.setString("name invalid");
                error.setCharacterSize(23);
                error.setFillColor(sf::Color::Red);
                error.setFont(font2);
              }
            }

            if (j > 469 && j < 469 + 67 && i > 326 && i < 326 + 377) {
              boolean = true;
              playerInput += "_";
            } else boolean = false;
            if (i > 25 && i < 75 && j > 570 && j < 620)
              if (initialSetMusic == 0) {
                MusicIconButton.setTexture(MusicIconOff);
                initialSetMusic = 1;
                //musique.pause();
              }
            else {
              MusicIconButton.setTexture(MusicIconOn);
              initialSetMusic = 0;
              //musique.play();
            }
            if (i > 25 && i < 75 && j > 630 && j < 680)
              if (initialSetSound == 0) {
                SoundIconButton.setTexture(SoundIconOff);
                initialSetSound = 1;
                //sound.pause();
              }
            else {
              SoundIconButton.setTexture(SoundIconOn);
              initialSetSound = 0;
              //sound.play();
            }
          }
        }
        if (event.type == sf::Event::MouseMoved) {
          if (i > 50 && i < 50 + 36 && j > 60 && j < 60 + 51) {
            if (initialSetSound == 0) //sound.play();
              BackButton.setPosition(50, 57);
          } else {
            BackButton.setPosition(50, 60);
          }
          if (j > 594 && j < 594 + 85 && i > 393 && i < 393 + 207) {
            if (initialSetSound == 0) //sound.play();
              playBTN_NC.loadFromFile("img/gameBegin/playBTN_C.png");
            BtplayBTN_NC.setPosition(393, 591);
          } else {
            playBTN_NC.loadFromFile("img/gameBegin/playBTN_NC.png");
            BtplayBTN_NC.setPosition(393, 594);
          }
        }
      }
      playerText.setPosition(170, 480);
      playerText.setFont(font);
      playerText.setFillColor(sf::Color::White);
      playerText.setCharacterSize(30);
      window.draw(playerText);
      playerText1.setPosition(600, 480);
      playerText1.setFont(font);
      playerText1.setFillColor(sf::Color::White);
      playerText1.setCharacterSize(30);
      window.draw(playerText1);
      window.draw(BtplayBTN_NC);
      window.draw(BackButton);
      window.draw(error);
    }
  }
  window.draw(SoundIconButton);
  window.draw(MusicIconButton);
  window.display();
}
}

int GUI::settingswindow() {
  sf::Texture difficulty1;
  difficulty1.loadFromFile("img/settings/level1.png");
  sf::Texture difficulty2;
  difficulty2.loadFromFile("img/settings/level2.png");
  sf::Sprite difficultyButton;
  difficultyButton.setPosition(449, 508);
  sf::Texture background;
  background.loadFromFile("img/settings/background.png");
  sf::Sprite backgroundAdd(background);
  sf::Texture music_on;
  music_on.loadFromFile("img/settings/music_on.png");
  sf::Texture music_off;
  music_off.loadFromFile("img/settings/music_off.png");
  sf::Sprite SoundAdd;
  if (initialSetSound == 0) SoundAdd.setTexture(music_on);
  else SoundAdd.setTexture(music_off);
  SoundAdd.setPosition(449, 266);
  sf::Sprite MusicAdd;
  if (difficulty == 1)
    difficultyButton.setTexture(difficulty1);
  else
  difficultyButton.setTexture(difficulty2);
  if (initialSetMusic == 0) MusicAdd.setTexture(music_on);
  else MusicAdd.setTexture(music_off);
  MusicAdd.setPosition(449, 387);
  sf::Texture backto;
  backto.loadFromFile("img/commun/back.png");
  sf::Sprite BackButton(backto);
  BackButton.setPosition(50, 60);
  while (window.isOpen()) {
    sf::Event event;
    sf::Vector2i pos = sf::Mouse::getPosition(window);
    int i = pos.x;
    int j = pos.y;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
      if (event.type == sf::Event::MouseMoved) {
        if (i > 50 && i < 50 + 36 && j > 60 && j < 60 + 51) {
          if (initialSetSound == 0) //sound.play();
            BackButton.setPosition(50, 57);
        } else {
          BackButton.setPosition(50, 60);
        }
      }
      if (event.type == sf::Event::MouseButtonPressed) {
        if (event.key.code == sf::Mouse::Left) {
          if (i > 50 && i < 50 + 36 && j > 60 && j < 60 + 51) {
              std::cout << "clicked retour\t"<<difficulty<<std::endl;
              return 0;
                //return 1;
                }
          if (i > 449 && i < 449 + 236 && j > 508 && j < 508 + 71)
            if (difficulty == 1) {
              difficulty = 2;
              difficultyButton.setTexture(difficulty2);
            } else {
              difficulty = 1;
              difficultyButton.setTexture(difficulty1);
            }
          if (i > 449 && i < 449 + 236 && j > 387 && j < 387 + 71)
            if (initialSetMusic == 0) {
              //musique.pause();
              MusicAdd.setTexture(music_off);
              initialSetMusic = 1;
            }
          else
          if (initialSetMusic == 1) {
            //musique.play();
            MusicAdd.setTexture(music_on);
            initialSetMusic = 0;
          }
          if (i > 449 && i < 449 + 236 && j > 266 && j < 266 + 71)
            if (initialSetSound == 0) {
              SoundAdd.setTexture(music_off);
              initialSetSound = 1;
            }
          else {
            SoundAdd.setTexture(music_on);
            initialSetSound = 0;
          }
        }
      }
    }
    window.draw(backgroundAdd);
    window.draw(BackButton);
    window.draw(MusicAdd);
    window.draw(SoundAdd);
    window.draw(difficultyButton);
    window.display();
  }

}

int GUI::scorewindow() {
  sf::Texture backto;
  sf::Font font2;
  font2.loadFromFile("consolaz.ttf");
  sf::Text scoreList;
  scoreList.setFont(font2);
  scoreList.setCharacterSize(30);

  LeaderBoard l;
  l.readListeFromFile();


  scoreList.setString(l.getStringSortedByScore());
  scoreList.setPosition(300, 270);
  sf::Texture Background;
  Background.loadFromFile("img/score/background.png");
  backto.loadFromFile("img/commun/back.png");
  MusicIconOn.loadFromFile("img/commun/music_on.png");
  MusicIconOff.loadFromFile("img/commun/music_off.png");
  SoundIconOn.loadFromFile("img/commun/sound_on.png");
  SoundIconOff.loadFromFile("img/commun/sound_off.png");
  sf::Sprite BackgroundAdd(Background);
  sf::Sprite BackButton(backto);
  BackButton.setPosition(50, 60);
  MusicIconButton.setPosition(25, 570);
  SoundIconButton.setPosition(25, 630);
  if (initialSetMusic == 0) MusicIconButton.setTexture(MusicIconOn);
  else MusicIconButton.setTexture(MusicIconOff);

  if (initialSetSound == 0) SoundIconButton.setTexture(SoundIconOn);
  else SoundIconButton.setTexture(SoundIconOff);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      sf::Vector2i pos = sf::Mouse::getPosition(window);
      int i = pos.x;
      int j = pos.y;
      if (event.type == sf::Event::Closed)
        window.close();
      //---------------------------- moved event --------------------------------------
      if (event.type == sf::Event::MouseMoved) { //------------------------ Bouton Back --------------------------------------
        if (i > 50 && i < 50 + 36 && j > 60 && j < 60 + 51) {
          if (initialSetSound == 0) //sound.play();
            BackButton.setPosition(50, 57);
        } else {
          BackButton.setPosition(50, 60);
        }
      }
      //--------------------------- Pressed Event -------------------------------------
      if (event.type == sf::Event::MouseButtonPressed)
        if (event.key.code == sf::Mouse::Left) {
          if (i > 50 && i < 50 + 36 && j > 60 && j < 60 + 51)
          return 0;
            //return 1;
          if (i > 25 && i < 75 && j > 570 && j < 620)
            if (initialSetMusic == 0) {
              MusicIconButton.setTexture(MusicIconOff);
              initialSetMusic = 1;
              //musique.pause();
            }
          else {
            MusicIconButton.setTexture(MusicIconOn);
            initialSetMusic = 0;
            //musique.play();
          }
          if (i > 25 && i < 75 && j > 630 && j < 680)
            if (initialSetSound == 0) {
              SoundIconButton.setTexture(SoundIconOff);
              initialSetSound = 1;
              //sound.pause();
            }
          else {
            SoundIconButton.setTexture(SoundIconOn);
            initialSetSound = 0;
            //sound.play();
          }
        }
    }
    window.draw(BackgroundAdd);
    window.draw(BackButton);
    window.draw(MusicIconButton);
    window.draw(SoundIconButton);
    window.draw(scoreList);
    window.display();
  }
}
GUI::~GUI(){};
