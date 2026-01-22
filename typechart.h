#ifndef TYPECHART_H
#define TYPECHART_H

#include <string>

enum class Type { // order must match effectiveness chart
    Fire,
    Nature,
    Water,
    Electric,
    Wind,
    Earth,
    Shadow,
    Light,
    Psychic,
    Infinity,
    COUNT // always last = number of types
};

float getEffectiveness(Type attacker, Type defender); // returns effectiveness multiplier
std::string typeToString(Type type); // convert Type to string for debugging/UI

#endif