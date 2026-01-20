#pragma once
#include "typechart.h"

struct Move {
    std::string name;
    int power;
    Type type;
    std::vector<Move> moves;
};