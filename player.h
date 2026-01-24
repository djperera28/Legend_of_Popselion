#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "popsmon.h"

class Player {
    public:
        std::vector<Popsmon> popsmonCollection; // Vector to hold the player's Popsmon collection
        bool hasAlivePopsmon() const; // Function to check if player has any alive Popsmon
        void addPopsmon(const Popsmon& pmon); // Function to add a Popsmon to the collection
        void showCollection(); // Function to display the player's Popsmon collection
};

#endif // PLAYER_H