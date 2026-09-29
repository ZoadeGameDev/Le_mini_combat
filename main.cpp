#include <iostream>
#include <random>
#include <print>
#include "character.h"

int main() {
    int random_seed = std::time(nullptr);
    std::srand(random_seed);
    std::println("RANDOM SEED: {}", random_seed);

    int max_turn = 100;
    int turn = 0;

    Character Orc("L'Orc", 60, 14, 4);
    Character Troll("Le Troll", 80, 11, 6);

    while (((Orc.Pv() != 0) && (Troll.Pv() != 0)) && (turn < max_turn)) {
        std::println("");

        std::println("=== Turn {} ===", turn, max_turn);
        // The Orc attack the Troll
        if (Orc.IsDead()) {
            break;
        }
        Troll.ReceiveAttack(Orc.Attaque(), Orc.Nom());
        // The Troll attack the Orc
        if (Troll.IsDead()) {
            break;
        }
        Orc.ReceiveAttack(Troll.Attaque(), Troll.Nom());

        // add 1 more turn
        turn += 1;
    }
    std::println("");
    if (turn >= max_turn) {
        std::println("Match Nul");
    } else if (Orc.Pv() < Troll.Pv()) {
        std::println("{} s'effondre", Orc.Nom());
        std::println("{} gagne en {} tours.", Troll.Nom(), turn);
    } else {
        std::println("{} s'effondre", Troll.Nom());
        std::println("{} gagne en {} tours.", Orc.Nom(), turn);
    }

    return 0;
}
