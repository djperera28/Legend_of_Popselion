#include "popsopedia.h" 
#include <vector> 
#include <cstdlib>

std::unordered_map<std::string, Popsmon> Popsopedia::registry;

Popsmon Popsopedia::get(const std::string& name) {
        return registry.at(name); 
    }
Popsmon Popsopedia::randomWild() {
    std::vector<std::string> wildList = {
        "Voltaris", "Noctalon", "Luminaryn",
        "Zephyra", "Gravemantle", "Psyperian"
    };

    int idx = rand() % wildList.size();
    return registry.at(wildList[idx]);
}

void Popsopedia::init() { 
    //fire starter 
    Popsmon solarion("Solarion", Type::Fire, 120, 8); 
    solarion.moves = { 
        {"Heat Blast", 4, Type::Fire}, 
        {"Solar Smash", 6, Type::Fire} 
    }; 
    registry["Solarion"] = solarion;

    //nature starter
    Popsmon thornbreaker("Thornbreaker", Type::Nature, 150, 6);
    thornbreaker.moves = {
        {"Root Slam", 4, Type::Nature},
        {"BRING ME..", 7, Type::Nature}
    };
    registry["Thornbreaker"] = thornbreaker;

    //water starter
    Popsmon aquastral("Aquastral", Type::Water, 130, 7);
    aquastral.moves = {
        {"Rising Tide", 4, Type::Water},
        {"Poseidon's Wish", 6, Type::Water}
    };
    registry["Aquastral"] = aquastral;

    // wild popsmon

    // Voltaris
    Popsmon voltaris("Volataris", Type::Electric, 110, 7);
    voltaris.moves = {
        {"Speed Force", 4, Type::Electric},
        {"We are the Flash", 6, Type::Electric}
    };
    registry["Voltaris"] = voltaris;

    // Gravemantle
    Popsmon gravemantle("Gravemantle", Type::Earth, 140, 6);
    gravemantle.moves = {
        {"Ready to Rubble", 4, Type::Earth},
        {"Grand Slam", 6, Type::Earth}
    };
    registry["Gravemantle"] = gravemantle;

    // Zephyra
    Popsmon zephyra("Zephyra", Type::Wind, 100, 8);
    zephyra.moves = {
        {"Tornado", 4, Type::Wind},
        {"Whirlwind", 6, Type::Wind}
    };
    registry["Zephyra"] = zephyra;

    // Noctalon
    Popsmon noctalon("Noctalon", Type::Shadow, 120, 7);
    noctalon.moves = {
        {"Dark Night", 4, Type::Shadow},
        {"The Void", 6, Type::Shadow}
    };
    registry["Noctalon"] = noctalon;

    // Luminaryn
    Popsmon luminaryn("Luminaryn", Type::Light, 115, 7);
    luminaryn.moves = {
        {"Spectral Beam", 4, Type::Light},
        {"Let there be light", 6, Type::Light}
    };
    registry["Luminaryn"] = luminaryn;

    // Psyperian
    Popsmon psyperian("Psyperian", Type::Psychic, 105, 8);
    psyperian.moves = {
        {"Hyper Charge", 4, Type::Psychic},
        {"Psionic Judgement", 6, Type::Psychic}
    };
    registry["Psyperian"] = psyperian;

    }
