
#include "player.h"
#include <iostream>
#include <iomanip>

void Player::addPopsmon(const Popsmon& pmon) {
    popsmonCollection.push_back(pmon);

    int index = (int)pmon.type;
    if (!achievement.typeCollected[index]) {
        achievement.typeCollected[index] = true;
    }

    bool allCollected = true;
    for (int i = 0; i < (int)Type::COUNT - 1; i++) {
        if (!achievement.typeCollected[i]) {
            allCollected = false;
            break;
        }
    }

    if (allCollected && !achievement.allTypesAchievement) {
        achievement.allTypesAchievement = true;

        //std::cout << "";
        //std::cout << "";
    }
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