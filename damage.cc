#include "damage.h"

#include <random>
#include <algorithm>

static float getRandomMultiplier() {
    static std::random_device rd; // Seed for RNG
    static std::mt19937 gen(rd()); // Mersenne Twister RNG, pseudo-random but good enough
    static std::uniform_real_distribution<float> dist(0.85f, 1.00f);
    return dist(gen); 
}

float calculateDamage(                                           // Calculates damage from attacker to defender using a specific move
    const Popsmon& attacker,
    const Popsmon& defender,
    const Move& move
) {
    float typeMult = getEffectiveness(move.type, defender.type); // Type effectiveness
    float randomMult = getRandomMultiplier();                    // Random factor between 0.85 and 1.0

    float base = attacker.attack * move.power;                   // Base damage calculation
    float dmg = base * typeMult * randomMult;                    // Final damage with multipliers

    return std::max(1.0f, dmg);                                  // Ensure at least 1 damage is dealt
}
