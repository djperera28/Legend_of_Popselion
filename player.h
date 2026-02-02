#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "popsmon.h"
#include "typechart.h"


struct PlayerAchievement {
    bool typeCollected[(int)Type::COUNT] = { false };
    bool allTypesAchievement = false;
};

class Player {
    public:
        std::vector<Popsmon> popsmonCollection; // Vector to hold the player's Popsmon collection
        bool hasAlivePopsmon() const; // Function to check if player has any alive Popsmon
        void addPopsmon(const Popsmon& pmon); // Function to add a Popsmon to the collection
        void showCollection(); // Function to display the player's Popsmon collection

        PlayerAchievement achievement; // achievement progress
};      
#endif // PLAYER_H