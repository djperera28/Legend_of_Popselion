#pragma once
#include "typechart.h"

struct Move { // Represents a move that a Popsmon can use
    std::string name;
    int power;
    Type type;
    std::string forceSwap; // For moves that force a swap (e.g. "Swap out")
    std::string bossHeal;
    std::vector<Move> moves;
};