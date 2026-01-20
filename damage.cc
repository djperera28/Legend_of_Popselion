#include "damage.h"

#include <random>
#include <algorithm>

static float getRandomMultiplier() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<float> dist(0.85f, 1.00f);
    return dist(gen);
}

float calculateDamage(
    const Popsmon& attacker,
    const Popsmon& defender,
    const Move& move
) {
    float typeMult = getEffectiveness(move.type, defender.type);
    float randomMult = getRandomMultiplier();

    float base = attacker.attack * move.power;
    float dmg = base * typeMult * randomMult;

    return std::max(1.0f, dmg);
}
