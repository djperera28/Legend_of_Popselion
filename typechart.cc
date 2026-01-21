#include "typechart.h"
#include <string>

//Effectiveness Multiplier
float getEffectiveness(Type attacker, Type defender) {
    static float chart[9][9] = {
//9x9 type effectiveness matrix
//Rows = attacker, columns = defender
    //                F     N     W     E     Wd    Er    Sh    L     P
    /* Fire     */  {1.0f, 2.0f, 0.5f, 1.0f, 1.0f, 0.5f, 2.0f, 1.0f, 1.0f},
    /* Nature   */  {0.5f, 1.0f, 2.0f, 0.5f, 0.5f, 2.0f, 1.0f, 1.0f, 1.0f},
    /* Water    */  {2.0f, 0.5f, 1.0f, 0.5f, 1.0f, 2.0f, 1.0f, 1.0f, 1.0f},

    /* Electric */  {1.0f, 1.0f, 2.0f, 1.0f, 2.0f, 0.5f, 1.0f, 1.0f, 1.0f},
    /* Wind     */  {1.0f, 2.0f, 1.0f, 0.5f, 1.0f, 2.0f, 1.0f, 1.0f, 1.0f},
    /* Earth    */  {2.0f, 0.5f, 0.5f, 2.0f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f},

    /* Shadow   */  {1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 2.0f},
    /* Light    */  {1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f, 1.0f, 0.5f},
    /* Psychic  */  {1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 2.0f, 1.0f}

    };
    
    return chart[(int)attacker][(int)defender];
}

// convert Type to string for debugging/UI
std::string typeToString(Type type) {
    switch (type) {
        case Type::Fire:    return "Fire";
        case Type::Nature:  return "Nature";
        case Type::Water:   return "Water";
        case Type::Electric:return "Electric";
        case Type::Wind:    return "Wind";
        case Type::Earth:   return "Earth";
        case Type::Shadow:  return "Shadow";
        case Type::Light:   return "Light";
        case Type::Psychic: return "Psychic";
        case Type::Infinity:return "Infinity";
        default:            return "Unknown";
    }
}