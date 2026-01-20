#ifndef POPSMON_H
#define POPSMON_H

#include <iostream>
#include <string>
#include <vector>
#include "move.h"

class Popsmon {
    public:
        std::string name; 
        int health; 
        int attack;
        Type type;
        std::vector<Move> moves; 

        Popsmon()
            : name(""), type(Type::Fire), health(0), attack(0) {}

        Popsmon(std::string name, Type type, int health, int attack);

};

#endif // POPSMON_H