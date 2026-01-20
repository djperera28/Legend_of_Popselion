#include "popsmon.h"

Popsmon::Popsmon(std::string name, Type type, int health, int attack)
    : name(name), type(type), health(health), maxHealth(health), attack(attack) {}
                                                    // Constructor