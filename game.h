#ifndef GAME_H
#define GAME_H

#include "player.h" 

class Game {
    public:
        void start();
        void showControls();
        Popsmon chooseStarter();
        bool battle(Player& player, Popsmon& wildPopsmon);
        void drawBattleUI(const Popsmon& active, const Popsmon& wildPopsmon);
        
};

#endif // GAME_H