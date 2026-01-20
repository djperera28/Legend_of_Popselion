
#include "player.h"
#include <iostream>
#include <iomanip>

void Player::addPopsmon(const Popsmon& pmon) {
    popsmonCollection.push_back(pmon);
}

void Player::showCollection() {
    std::cout << "Your Popsmon Collection:\n";
    for (const auto& pmon : popsmonCollection) {
        std::cout << "Name: " << pmon.name 
                  << ", Type: " << typeToString(pmon.type)
                  << ", Health: " << pmon.health 
                  << ", Attack: " << pmon.attack << "\n";
    }
}