#ifndef POPSMON_H
#define POPSMON_H

#include <iostream>
#include <string>
#include <vector>
#include "move.h"

struct Popsmon {
    public:
        std::string name; 
        int health;
        int maxHealth;
        int attack;
        Type type;
        std::vector<Move> moves; 

        Popsmon()
            : name(""), type(Type::Fire), health(0), maxHealth(0), attack(0) {}

        Popsmon(std::string name, Type type, int health, int attack);

        void heal(int amount) {
            health += amount;
            if (health > maxHealth) health = maxHealth;
        }
};

#endif // POPSMON_H