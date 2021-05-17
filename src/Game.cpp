#include "Game.h"

#include <stdlib.h>

#include <string>

#include <time.h>

#include "common.h"

#include <windows.h>

#include <SFML/Graphics.hpp>

#include <SFML/Window.hpp>

#include "LeaderBoard.h"

int trouverDansTab(int * tab, int x);
int tabEmpty(int * tab);
int random(int * tab);
int calculated_move(int * tab);

Game::Game() {}
int Game::startGameGUI(){
    std::string nom1,nom2;
    int adversaire;
    sf::RenderWindow &window = gui.GraphicDebutJeu(nom1,nom2,adversaire);
    //sf::RenderWindow &window = gui.DebutJeu(nom1,nom2,adversaire);
    players[0].setNom(nom1);
    players[1].setNom(nom2);
    initiate(adversaire);//adversaire 0 Friend 1 CPU1 2 CPU2
    playGUI(window);
}

int Game::startGame() {
  int nb = 2;
  int noPlay = 1; // 1 si joueur percedent a joué
  do {
    log << "noplay = " << noPlay << std::endl;
    if (!noPlay) {
      if (!(noPlay = jouerTour(nb)))
        break;
    }
    noPlay = jouerTour(nb);
    log << "nb pions tot " << othellier.getnbPionsTotale() << std::endl;
  } while (othellier.getnbPionsTotale() < 64);

  //afficher gagnant
  if (getWinner().length() == 0)
    std::cout << "Match Nul" << std::endl;
  else
    std::cout << "Le jouer " << getWinner() << " a gagné!";
  std::cout << "Le score final:\n" << players[0].getName() << " : " << players[0].getNbPions() << std::endl;
  std::cout << players[1].getName() << " : " << players[1].getNbPions() << std::endl;

  return 0;
}

Game::~Game() {}

int Game::scoreupdate() {
  players[0].setNbPions(0); // set 0 et compter le nbr de pions de chaque joueur dans la grille .
  players[1].setNbPions(0);
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (othellier.getCase(i, j).getCouleur() == -1) {
        /*rien a faire */ } else if (othellier.getCase(i, j).getCouleur() == players[0].getcolor()) {
        players[0].increment_nbPion(1);
      } else {
        players[1].increment_nbPion(1);
      }
    }
  }
}
int Game::jouerTour(int & c) // nb  ddesigne  le tour de role de chaque joueur  */
{
  int * tab; // enregistre les id des cases accessibles a chaque tour
  int x, y;
  std::string a; // pour stocker l'entree du clavier
  std::cout << "score du joueur " << players[0].getName() << " est : " << players[0].getNbPions() << std::endl;
  std::cout << "score du joueur " << players[1].getName() << " est : " << players[1].getNbPions() << std::endl;

  do {
    std::string nom = players[c % 2].getName();
    std::cout << nom << " play now" << std::endl;
    log << nom << " play now" << std::endl;
    tab = othellier.possibleMoves(players[c % 2].getcolor()); // tableaux des id // possibles moves par rapport les couleurs
    for (int i = 0; i < 64; i++) {
      log << i << ":" << tab[i] << " ";
    }
    log << std::endl;
    if (tabEmpty(tab)) {
      std::cout << players[c % 2].getName() << " ne peut rien jouer" << std::endl;
      log << players[c % 2].getName() << " ne peut rien jouer" << std::endl;
      c++;
      return 0;
    } else {
      if (players[c % 2].isBot()) {
        int bot_move;
        Sleep(500);
        if (players[c % 2].isBot() == 1) {
          bot_move = random(tab);
          log << "playing a random move\n";
        } else {
          bot_move = calculated_move(tab);
          log << "playing a calculated move\n";
        }
        x = othellier.getXById(bot_move);
        y = othellier.getYById(bot_move);
        log << players[c % 2].getName() << " a joué" << (char)(y + 'a') << x + 1 << std::endl;
        break;
      } else {
        std::cout << std::endl;
        std::cout << "ajouter la position du pion a jouer  sous la forme ' lettreChiffre '" << std::endl; // lecture de lentree de joueur
        std::cin >> a[0] >> a[1]; // 1ere char 2 eme char
        y = (a[0] - 'a'); // conversion du char vers int
        x = (a[1] - '1');
        log << a[0] << a[1] << std::endl;
      }
    }
    /* std::cout << "id entree  " << othellier.getCase(x,y).getId() << std::endl;*/
  } while (othellier.getCase(x, y).getCouleur() != -1 || !tab[othellier.getCase(x, y).getId()]);
  // test  si le choix de la case est convenable  //  trouver dans tab : chercher l id de la case jouee dans tab
  othellier.ajouterPion(x, y, players[c % 2].getcolor());
  othellier.changerPion(x, y, players[c % 2].getcolor());
  othellier.printBoard();

  c++;
  scoreupdate();
  return 1;
}
void Game::initiate(int adversaire) {
  players[0].setIsBot(0);
  //players[0].entrerNom();
  if (adversaire == 1) {
    players[1].setIsBot(1);
    players[1].setNom("CPU1");
  } else if (adversaire == 2) {
    players[1].setIsBot(2);
    players[1].setNom("CPU2");
  } else if (adversaire == 3) {
    players[1].setIsBot(0);
    //players[1].entrerNom();
  }
  randomizeFirstPlayer();

  othellier.getCase(3, 3).setCouleur(1);
  othellier.getCase(4, 4).setCouleur(1);
  othellier.getCase(3, 4).setCouleur(0);
  othellier.getCase(4, 3).setCouleur(0);
  players[0].setCouleur(1);
  players[1].setCouleur(0); //randomize

  othellier.printBoard();
}

std::string Game::getWinner() {
  if (players[0].getNbPions() > players[1].getNbPions())
    return players[0].getName();
  else if (players[0].getNbPions() < players[1].getNbPions())
    return players[1].getName();
  else
    return "";
}

Player Game::getPlayerWinner() {
  if (players[0].getNbPions() > players[1].getNbPions())
    return players[0];
  else if (players[0].getNbPions() < players[1].getNbPions())
    return players[1];
  else {
    Player draw;
    draw.setNom("Match Nul!");
    draw.setNbPions(players[0].getNbPions());
  }

}

Player Game::getPlayer(int x) {
  return players[x];
}

Othellier Game::getOthellier() {
  return othellier;
}

int tabEmpty(int * tab) {
  for (int i = 0; i < 64; i++) {
    if (tab[i] != 0)
      return 0;
  }
  return 1;
}

int random(int * tab) {
  int r = 0;
  srand(time(NULL));
  do {
    r = rand() % 64;
  } while (tab[r] == 0);
  return r;
}

int calculated_move(int * tab) {
  int best = 0;
  if (tab[0])
    return 0;
  if (tab[7])
    return 7;
  if (tab[63])
    return 63;
  if (tab[56])
    return 56;
  for (int i = 1; i < 7; i++) {
    if (tab[i])
      return i;
  }
  for (int i = 57; i < 63; i++) {
    if (tab[i])
      return i;
  }
  for (int i = 8; i < 49; i += 8) {
    if (tab[i])
      return i;
  }
  for (int i = 15; i < 63; i += 8) {
    if (tab[i])
      return i;
  }
  for (int i = 0; i < 63; i++) {
    if (tab[i] > tab[best])
      best = i;
  }
  return best;
}

sf::Vector2i posInitiale(127, 119);
void Game::playGUI(sf::RenderWindow &window) {

  //sf::RenderWindow window(sf::VideoMode(1000, 700), "Othello", sf::Style::Close | sf::Style::Titlebar);
  //window.setFramerateLimit(30);
  //window.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - 500, 0));

  //cursor joueur blanc
  sf::Image cursor1;
  cursor1.loadFromFile("cursorblanc.png");
  const uint8_t * pixels1 = cursor1.getPixelsPtr();
  sf::Cursor c1;
  c1.loadFromPixels(pixels1, sf::Vector2u(55, 56), sf::Vector2u(27.5, 28));

  //cursor joueur blanc
  sf::Image cursor2;
  cursor2.loadFromFile("cursornoir.png");
  const uint8_t * pixels2 = cursor2.getPixelsPtr();
  sf::Cursor c2;
  c2.loadFromPixels(pixels2, sf::Vector2u(55, 56), sf::Vector2u(27.5, 28));

  sf::Cursor syscursor;
  syscursor.loadFromSystem(sf::Cursor::Arrow);

  sf::Texture imgOth;
  imgOth.loadFromFile("othellier2.png");
  imgOth.setSmooth(true);
  sf::Sprite bgOth(imgOth);

  sf::Texture imgPionB;
  imgPionB.loadFromFile("pionblanc.png");
  imgPionB.setSmooth(true);
  pionB.setTexture(imgPionB);

  sf::Texture imgPionN;
  imgPionN.loadFromFile("pionnoir.png");
  imgPionN.setSmooth(true);
  pionN.setTexture(imgPionN);

  sf::Font font;
  font.loadFromFile("AvenirLTStd-Black.otf");

  sf::Text score0(std::to_string(players[0].getNbPions()), font);
  score0.setCharacterSize(30);
  score0.setFillColor(sf::Color::White);
  score0.setOrigin(15, 15);
  score0.setPosition(770 + 15, 338 + 15);

  sf::Text score1(std::to_string(players[1].getNbPions()), font);
  score1.setCharacterSize(30);
  score1.setFillColor(sf::Color::White);
  score1.setOrigin(15, 15);
  score1.setPosition(770 + 15, 230 + 15);

  sf::Text nomJ0(players[0].getName(), font);
  nomJ0.setCharacterSize(30);
  nomJ0.setFillColor(sf::Color::White);
  nomJ0.setPosition(875, 353 - 15);

  sf::Text nomJ1(players[1].getName(), font);
  nomJ1.setCharacterSize(30);
  nomJ1.setFillColor(sf::Color::White);
  nomJ1.setPosition(875, 245 - 15);

  sf::Sprite pions[8][8];
  int tour = 2;
  window.setMouseCursor(c1);

  int * tab;
  tab = othellier.possibleMoves(players[tour % 2].getcolor());
  bool gameOn = true;
  int gameContinues = 2;
  while (window.isOpen()) {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (othellier.getCase(i, j).getCouleur() == 0)
          pions[j][i] = pionB;
        else if (othellier.getCase(i, j).getCouleur() == 1)
          pions[j][i] = pionN;
        else if (tab[i * 8 + j] != 0) {
          pions[j][i] = pionN;
          pions[j][i].setColor(sf::Color(255, 255, 255, 50));
        } else
          pions[j][i].setColor(sf::Color(0, 0, 0, 0));
        pions[j][i].setPosition(posInitiale.x + 69 * j, posInitiale.y + 69 * i);
      }
    }
    if (players[tour % 2].isBot() && gameOn) {
      //Sleep(500);
      int bot_move;
      //Sleep(500);
      if (players[tour % 2].isBot() == 1)
        bot_move = random(tab);
      else
        bot_move = calculated_move(tab);
      int x = othellier.getXById(bot_move);
      int y = othellier.getYById(bot_move);
      log << "gamecontinues= " << gameContinues << "\n";
      jouerTourGUI(y, x, tour, tab, gameContinues);

    }
    sf::Event event;
    while (window.pollEvent(event)) {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed)
        window.close();
      if (event.type == sf::Event::MouseButtonPressed)
        if (event.key.code == sf::Mouse::Left && gameOn) {
          if (gameOn == true) {
            sf::Vector2i pos = sf::Mouse::getPosition(window);
            int i = pos.x;
            int j = pos.y;
            if (i > 127 && i < 127 + 69 * 8 && j > 118 && j < 118 + 69 * 8) {
              i = (pos.x - 127) / 69;
              j = (pos.y - 118) / 69;
              gameOn = jouerTourGUI(i, j, tour, tab, gameContinues);
            }
          }
        }
    }

    // clear the window with black color
    window.clear();
    sf::Vector2i pos = sf::Mouse::getPosition(window);
    int mousex = pos.x;
    int mousey = pos.y;

    if (othellier.getnbPionsTotale() >= 64)
      gameOn = false;

    if (gameOn) {
      if (mousex > 127 && mousex < 127 + 69 * 8 && mousey > 118 && mousey < 118 + 69 * 8) {
        if (tour % 2)
          window.setMouseCursor(c1);
        else
          window.setMouseCursor(c2);
      } else
        window.setMouseCursor(syscursor);

      window.draw(bgOth);

      for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
          window.draw(pions[i][j]);

      score0.setString(std::to_string(players[0].getNbPions()));
      window.draw(score0);
      score1.setString(std::to_string(players[1].getNbPions()));
      window.draw(score1);

      window.draw(nomJ0);
      window.draw(nomJ1);
    } else {
      sf::Text gameover("Game Over " + getPlayerWinner().getName() + " " + std::to_string(getPlayerWinner().getNbPions()), font);
      gameover.setCharacterSize(30);
      gameover.setStyle(sf::Text::Bold);
      gameover.setFillColor(sf::Color::White);
      gameover.setPosition(500, 350);

      window.draw(gameover);
    }

    window.display();
  }
  if (!gameOn) {
    leaderBoard.readListeFromFile();
    leaderBoard.addScore(getPlayerWinner().getName(), getPlayerWinner().getNbPions() * 10);
    leaderBoard.writeListeToFile();
    leaderBoard.getSortedByScore();

  }

}

bool Game::jouerTourGUI(int i, int j, int & tour, int * tab, int & gameContinues) {
  othellier.printBoard();
  if (tabEmpty(tab)) {
    tour++;
    gameContinues--;
    tab = othellier.possibleMoves(players[tour % 2].getcolor());
    if (gameContinues < 1)
      return false;
    return true;
  } else if (tab[j * 8 + i] != 0) {
    /*if(tour%2)
        pions[i][j]=pionB;
    else
        pions[i][j]=pionN;*/
    //pions[i][j].setPosition(posInitiale.x+69*i,posInitiale.y+69*j);
    othellier.ajouterPion(j, i, players[tour % 2].getcolor());
    othellier.changerPion(j, i, players[tour % 2].getcolor());
    tour++;
    gameContinues = 2;
    tab = othellier.possibleMoves(players[tour % 2].getcolor());
    scoreupdate();
  }
  return true;
}

void Game::randomizeFirstPlayer() {
  srand(time(NULL));
  int r = rand() % 2;
  if (r == 0) {
    Player tmp = players[0];
    players[0] = players[1];
    players[1] = tmp;
  }
}
