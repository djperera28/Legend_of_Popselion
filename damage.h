#pragma once
#include "typechart.h"
#include "popsmon.h"

float calculateDamage(
    const Popsmon& attacker,
    const Popsmon& defender,
    const Move& move
);