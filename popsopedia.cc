#include "popsopedia.h"
#include <cstdlib>
#include <ctime>

// Static registry definition
std::unordered_map<std::string, Popsmon> Popsopedia::registry;

void Popsopedia::init() {
    registry.clear(); // Clear existing registry

    //
    // STARTERS
    //

    // Solarion (Fire)
    {
        Popsmon p;                          // Define Popsmon
        p.name = "Solarion";                // Name
        p.type = Type::Fire;                // Type
        p.maxHealth = 120;                  // Max Health
        p.health = p.maxHealth;             // Current Health
        p.attack = 8;                       // Attack stat
        p.moves = {                         // Moves
            {"Heat Burst", 4, Type::Fire},
            {"Solar Smash", 6, Type::Fire}
        };
        registry[p.name] = p;               // Add to registry
    }

    // Thornbreaker (Nature)
    {
        Popsmon p;
        p.name = "Thornbreaker";
        p.type = Type::Nature;
        p.maxHealth = 150;
        p.health = p.maxHealth;
        p.attack = 6;
        p.moves = {
            {"Root Slam", 4, Type::Nature},
            {"BRING ME..?", 7, Type::Nature}
        };
        registry[p.name] = p;
    }

    // Aquastral (Water)
    {
        Popsmon p;
        p.name = "Aquastral";
        p.type = Type::Water;
        p.maxHealth = 130;
        p.health = p.maxHealth;
        p.attack = 7;
        p.moves = {
            {"Rising Tide", 4, Type::Water},
            {"Poseidon's Wish", 6, Type::Water}
        };
        registry[p.name] = p;
    }

    //
    // WILD POPSMON
    //

    // Voltaris (Electric)
    {
        Popsmon p;
        p.name = "Voltaris";
        p.type = Type::Electric;
        p.maxHealth = 110;
        p.health = p.maxHealth;
        p.attack = 7;
        p.moves = {
            {"Speed Force", 4, Type::Electric},
            {"We Are The Flash", 6, Type::Electric}
        };
        registry[p.name] = p;
    }

    // Gravemantle (Earth)
    {
        Popsmon p;
        p.name = "Gravemantle";
        p.type = Type::Earth;
        p.maxHealth = 140;
        p.health = p.maxHealth;
        p.attack = 6;
        p.moves = {
            {"Ready to Rubble", 4, Type::Earth},
            {"Grand Slam", 6, Type::Earth}
        };
        registry[p.name] = p;
    }

    // Zephyra (Wind)
    {
        Popsmon p;
        p.name = "Zephyra";
        p.type = Type::Wind;
        p.maxHealth = 100;
        p.health = p.maxHealth;
        p.attack = 8;
        p.moves = {
            {"Tornado", 4, Type::Wind},
            {"Winds of Wrath", 6, Type::Wind}
        };
        registry[p.name] = p;
    }

    // Noctalon (Shadow)
    {
        Popsmon p;
        p.name = "Noctalon";
        p.type = Type::Shadow;
        p.maxHealth = 120;
        p.health = p.maxHealth;
        p.attack = 7;
        p.moves = {
            {"Dark Night", 4, Type::Shadow},
            {"The Void", 6, Type::Shadow}
        };
        registry[p.name] = p;
    }

    // Luminaryn (Light)
    {
        Popsmon p;
        p.name = "Luminaryn";
        p.type = Type::Light;
        p.maxHealth = 115;
        p.health = p.maxHealth;
        p.attack = 7;
        p.moves = {
            {"Spectral Beam", 4, Type::Light},
            {"Let There Be Light", 6, Type::Light}
        };
        registry[p.name] = p;
    }

    // Psyperian (Psychic)
    {
        Popsmon p;
        p.name = "Psyperian";
        p.type = Type::Psychic;
        p.maxHealth = 105;
        p.health = p.maxHealth;
        p.attack = 8;
        p.moves = {
            {"The Force", 4, Type::Psychic},
            {"Psionic Judgement", 6, Type::Psychic}
        };
        registry[p.name] = p;
    }

    // Legendary Popsmon (BOSS)
    { 
        Popsmon boss;
        boss.name = "Popselion";
        boss.type = Type::Infinity;
        boss.maxHealth = 999;
        boss.health = boss.maxHealth;
        boss.attack = 99;
        boss.moves = {
            {"Pops, Bops, and the Popular Way", 10, Type::Infinity},
            {"Pop Out", 0, Type::Infinity}, // swap move
            {"POPSELION FOREVER", 0, Type::Infinity} // boss heal
        };
        registry[boss.name] = boss;
    }

}

Popsmon Popsopedia::get(const std::string& name) { // Retrieve Popsmon by name
    return registry.at(name);
}

Popsmon Popsopedia::randomWild() {                 // Get a random wild Popsmon
    std::vector<std::string> wildList = {
        "Aquastral",
        "Gravemantle",
        "Luminaryn",
        "Noctalon",
        "Psyperian",
        "Solarion",
        "Thornbreaker",
        "Voltaris",
        "Zephyra"
    };

    int index = std::rand() % wildList.size();     // Random index
    return registry[wildList[index]];              // Return random wild Popsmon
}

Popsmon Popsopedia::bossEncounter() {
    std::vector<std::string> bossList = {
        "Popselion"
    };

    return registry["Popselion"];
}