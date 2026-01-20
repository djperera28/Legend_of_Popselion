#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "popsmon.h"

class Player {
    public:
        std::vector<Popsmon> popsmonCollection; // Vector to hold the player's Popsmon collection

        void addPopsmon(const Popsmon& pmon);
        void showCollection();
};

#endif // PLAYER_H