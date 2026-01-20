#ifndef TYPECHART_H
#define TYPECHART_H

#include <string>

enum class Type {
    Fire,
    Nature,
    Water,
    Electric,
    Wind,
    Earth,
    Shadow,
    Light,
    Psychic,
    COUNT // always last = number of types
};

float getEffectiveness(Type attacker, Type defender);
std::string typeToString(Type type);

#endif