#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"
#include "popsopedia.h"
#include "damage.h"
#include "typechart.h"

void Game::showControls() {
    std::cout << "\n========================================\n";
    std::cout << "               HOW TO PLAY\n";
    std::cout << "========================================\n\n";

    std::cout << "▶ EXPLORATION\n";
    std::cout << "  Walk into tall grass to encounter\n";
    std::cout << "  wild Popsmon.\n\n";

    std::cout << "▶ BATTLE\n";
    std::cout << "  • Choose moves each turn\n";
    std::cout << "  • Switch Popsmon when needed\n";
    std::cout << "  • Type matchups affect damage\n\n";

    std::cout << "▶ PARTY\n";
    std::cout << "  • Carry multiple Popsmon\n";
    std::cout << "  • Swap during battle\n";
    std::cout << "  • Heal between encounters (future!)\n\n";

    std::cout << "▶ MENU\n";
    std::cout << "  • Explore  – Find wild Popsmon\n";
    std::cout << "  • Popsmon  – View your party\n";
    std::cout << "  • Exit     – Leave the adventure\n\n";

    std::cout << "========================================\n";
    std::cout << "        PRESS ENTER TO CONTINUE\n";
    std::cout << "========================================\n";

    std::cin.ignore();
    std::cin.get();
}

void Game::drawBattleUI(const Popsmon& active, const Popsmon& wildPopsmon) {
    std::cout << "\n========================================\n";
    std::cout << "   YOUR POPSMON              WILD POPSMON\n";
    std::cout << "   " << active.name << " (HP: " << active.health << ")\n";
    std::cout << "   VS\n";
    std::cout << "   " << wildPopsmon.name << " (HP: " << wildPopsmon.health << ")\n";
    std::cout << "========================================\n";
}

Popsmon Game::chooseStarter() {
    std::cout << "\nChoose your starter Popsmon:\n";
    std::cout << "1. Solarion (Fire)\n";
    std::cout << "2. Thornbreaker (Nature)\n";
    std::cout << "3. Aquastral (Water)\n";
    std::cout << "Choice: ";

    int choice;
    std::cin >> choice;

    if (choice == 1) return Popsopedia::get("Solarion");
    if (choice == 2) return Popsopedia::get("Thornbreaker");
    return Popsopedia::get("Aquastral");
}

bool Game::battle(Player& player, Popsmon& wildPopsmon) {
    int activeIndex = 0;
    Popsmon& active = player.popsmonCollection[activeIndex];

    while (true) {
        drawBattleUI(active, wildPopsmon);

        std::cout << "\nChoose your action:\n";
        for (int i = 0; i < (int)active.moves.size(); i++) {
            std::cout << "  " << i+1 << ". " << active.moves[i].name
                      << "  [" << typeToString(active.moves[i].type) << "]\n";
        }
        std::cout << "  " << active.moves.size() + 1 << ". Switch Popsmon\n";
        std::cout << "========================================\n";
        std::cout << "Action: ";

        int choice;
        std::cin >> choice;

        // Player chooses a move
        if (choice >= 1 && choice <= (int)active.moves.size()) {
            Move move = active.moves[choice - 1];
            int dmg = calculateDamage(active, wildPopsmon, move);
            wildPopsmon.health -= dmg;

            std::cout << active.name << " used " << move.name
                      << "! It dealt " << dmg << " damage.\n";

            if (wildPopsmon.health <= 0) {
                std::cout << "Wild " << wildPopsmon.name << " fainted!\n";
                return true;
            }
        }
        // Player switches Popsmon
        else if (choice == (int)active.moves.size() + 1) {
            std::cout << "\n========================================\n";
            std::cout << "            SWITCH POPSMON\n";
            std::cout << "========================================\n";

            for (int i = 0; i < (int)player.popsmonCollection.size(); i++) {
                const auto& p = player.popsmonCollection[i];
                std::cout << "  " << i+1 << ". " << p.name
                          << " (HP: " << p.health << ")\n";
            }

            std::cout << "========================================\n";
            std::cout << "Choose: ";

            int swapChoice;
            std::cin >> swapChoice;

            if (swapChoice >= 1 && swapChoice <= (int)player.popsmonCollection.size()) {
                activeIndex = swapChoice - 1;
                active = player.popsmonCollection[activeIndex];
                std::cout << "Go, " << active.name << "!\n";
                continue; // skip wild turn
            } else {
                std::cout << "Invalid choice.\n";
                continue;
            }
        }
        else {
            std::cout << "Invalid choice.\n";
            continue;
        }

        // Wild's turn
        Move wildMove = wildPopsmon.moves[std::rand() % wildPopsmon.moves.size()];
        int dmg = calculateDamage(wildPopsmon, active, wildMove);
        active.health -= dmg;

        std::cout << "Wild " << wildPopsmon.name << " used " << wildMove.name
                  << "! It dealt " << dmg << " damage.\n";

        if (active.health <= 0) {
            std::cout << active.name << " fainted!\n";

            bool hasAlive = false;
            for (auto& p : player.popsmonCollection)
                if (p.health > 0) hasAlive = true;

            if (!hasAlive) {
                std::cout << "You have no Popsmon left!\n";
                return false;
            }

            std::cout << "Choose another Popsmon!\n";
            continue;
        }
    }
}

void Game::start() {
    std::srand(std::time(0));
    Popsopedia::init();

    // Title screen loop
    while (true) {
        std::cout << "\n========================================\n";
        std::cout << "          ▒█▀▀█ ▒█▀▀█ ▒█▀▀█ ▒█▀▀█  \n";
        std::cout << "          ▒█▄▄█ ▒█  █ ▒█▄▄█ ▒█▄▄▄     \n";
        std::cout << "          ▒█    ▒█▄▄█ ▒█     ▄▄▄█      \n";
        std::cout << "========================================\n";
        std::cout << "            POPSMON ADVENTURE\n";
        std::cout << "========================================\n";
        std::cout << "  1. Start Adventure\n";
        std::cout << "  2. Controls\n";
        std::cout << "  3. Exit\n";
        std::cout << "========================================\n";
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) break;
        if (choice == 2) {
            showControls();
            continue;
        }
        if (choice == 3) {
            std::cout << "Goodbye!\n";
            return;
        }

        std::cout << "Invalid choice.\n";
    }

    Player player;
    Popsmon starter = chooseStarter();
    player.addPopsmon(starter);

    std::cout << "\nYour adventure begins!\n";

    // Main game loop
    while (true) {
        std::cout << "\n========================================\n";
        std::cout << "  1. Explore\n";
        std::cout << "  2. View Popsmon\n";
        std::cout << "  3. Exit Game\n";
        std::cout << "========================================\n";
        std::cout << "Choose: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            Popsmon wild = Popsopedia::randomWild();
            std::cout << "\nA wild " << wild.name << " appeared!\n";
            battle(player, wild);
        }
        else if (choice == 2) {
            player.showCollection();
        }
        else if (choice == 3) {
            std::cout << "Thanks for playing!\n";
            break;
        }
        else {
            std::cout << "Invalid choice.\n";
        }
    }
}