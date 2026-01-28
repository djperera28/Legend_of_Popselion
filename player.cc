
#include "player.h"
#include <iostream>
#include <iomanip>

void Player::addPopsmon(const Popsmon& pmon) {
    popsmonCollection.push_back(pmon);
}

void Player::showCollection() {
    std::cout << "\n\033[1;96mYour Popsmon Collection:\033[0m\n";
    for (const auto& pmon : popsmonCollection) {
        std::cout << "Name: " << pmon.name 
                  << ", Type: " << typeToString(pmon.type)
                  << ", Health: " << pmon.health 
                  << ", Attack: " << pmon.attack << "\n";
    }
}

bool Player::hasAlivePopsmon() const {
    for (const auto& p : popsmonCollection) {
        if (p.health > 0) {
            return true;
        }
    }
    return false;
}