
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


bool typeRequiredForAchievement[(int)Type::COUNT] = { 
        true, // Fire
        true, // Nature
        true, // Water
        true, // Electric
        true, // Wind
        true, // Earth
        true, // Shadow
        true, // Light
        true, // Psychic
        false
     };
     
void obtainType(PlayerAchievement& progress, Type type) {
    int index = (int)type;

    if (progress.typeRequiredForAchievement[index])
        return; // already collected

    progress.typeRequiredForAchievement[index] = true;

    //check if all types are collected
    bool allCollected = true;
    for (bool hasType : progress.typeRequiredForAchievement) {
        if (!hasType) {
            allCollected = false;
            break;
            }
        }

        if (allCollected && !progress.allTypesAchievement) {
        progress.allTypesAchievement = true;

        // world reaction 
        std::cout << "\nThe world bowed without knowing why...\n";
        std::cout << "An ominous presence is felt..\n";
        
        }
}

void bossEncounter(const PlayerAchievement& progress) {
    if (!progress.allTypesAchievement) {
        return;
        }

        std::cout << "\nA voice echoes... ..  .\n";
        std::cout << "You..\n";
        std::cout << "You've done the impossible...\n";
        std::cout << " step forward, young Traveler..\n";
    }