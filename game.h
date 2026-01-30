#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "popsopedia.h" 

class Game {
    public:
        void start();                                                         // Function to start the game
        void showControls();                                                  // Function to show game controls
        Popsmon chooseStarter();                                              // Function to choose starter Popsmon
        bool battle(Player& player, Popsmon& wildPopsmon);                    // Function to start battle logic              
        void drawBattleUI(const Popsmon& active, const Popsmon& wildPopsmon); // Function to draw battle UI
        void drawBossBattleUI(const Popsmon& active, const Popsmon& p);
        void drawPartyUI(const Player& player, int activeIndex);              // Function to draw party UI
        bool attemptCapture(const Popsmon& wildPopsmon);                      // Function to attempt capturing a wild Popsmon
        bool bossBattle(Player& player, Popsmon& p, PlayerAchievement);                   // Function to start Boss fight
        

};

#endif // GAME_H