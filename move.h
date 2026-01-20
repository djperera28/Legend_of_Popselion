#pragma once
#include "typechart.h"

struct Move { // Represents a move that a Popsmon can use
    std::string name;
    int power;
    Type type;
    std::vector<Move> moves;
};