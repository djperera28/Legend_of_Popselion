#ifndef GAME_H
#define GAME_H

#include "player.h" 

class Game {
    public:
        void start(); // Function to start the game
        void showControls(); // Function to show game controls
        Popsmon chooseStarter(); // Function to choose starter Popsmon
        bool battle(Player& player, Popsmon& wildPopsmon); // Battle function
        void drawBattleUI(const Popsmon& active, const Popsmon& wildPopsmon); // Function to draw battle UI

        bool attemptCapture(const Popsmon& wildPopsmon); // Function to attempt capturing a wild Popsmon
        
};

#endif // GAME_H