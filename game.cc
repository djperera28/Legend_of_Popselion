#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "game.h"
#include "popsopedia.h"
#include "damage.h"
#include "typechart.h"

void Game::start() {
    std::srand(std::time(0));
    Popsopedia::init();

    // Title screen loop
    while (true) {
        std::cout << "\n============================================\n";
        std::cout << " ▒█▀▀█ ▒█▀▀█ ▒█▀▀█ ▒█▀▀█ ▒█▀█▀█ ▒█▀▀█ ▒██  █\n";
        std::cout << " ▒█▄▄█ ▒█  █ ▒█▄▄█ ▒█▄▄▄ ▒█ █ █ ▒█  █ ▒█ █ █\n";
        std::cout << " ▒█    ▒█▄▄█ ▒█    ▒▄▄▄█ ▒█   █ ▒█▄▄█ ▒█  ██\n";
        std::cout << "============================================\n";
        std::cout << "             \033[93mLEGEND OF POPSELION\033[0m\n";
        std::cout << "============================================\n";
        std::cout << "  1. \033[32mStart Adventure\033[0m\n";
        std::cout << "  2. Controls\n";
        std::cout << "  3. \033[31mExit\033[0m\n";
        std::cout << "============================================\n";
        std::cout << "Choose an Action: \n";

        int choice;
        std::cin >> choice;

        if (!choice) {
            std::cout << "Please enter a number!\n";
            std::cin.clear(); // clear error flag
            std::cin.ignore(); // discard invalid input
            continue;
        }
        if (choice == 1) break;
        if (choice == 2) {
            showControls();
            continue;
        }
        if (choice == 3) {
            std::cout << "\033[90mTill we meet again Traveler...\033[0m\n";
            return;
        } else if (choice != int()) {
            std::cout << "Invalid choice.\n";
            continue;
        }
    }

    Player player;
    Popsmon starter = chooseStarter();
    player.addPopsmon(starter);

    std::cout << "\n========================================\n";
    std::cout << "\n\033[1;32mYour Adventure begins!\033[0m\n";

    // Main game loop
    while (true) {
        std::cout << "\n========================================\n";
        std::cout << "  1. \033[1;32mExplore\033[0m\n";
        std::cout << "  2. \033[1;96mPopsopedia\033[0m\n";
        std::cout << "  3. \033[1;33mPops Center\033[0m\n";
        std::cout << "  4. Exit Game\n";
        std::cout << "========================================\n";
        std::cout << "Choose:  ";

        int choice;
        std::cin >> choice;

        if (!choice) {
            std::cout << "Please enter a number!\n";
            std::cin.clear(); // clear error flag
            std::cin.ignore(); // discard invalid input
            continue;
        }
        if (choice == 1) {
            if (!player.hasAlivePopsmon()) {
                std::cout << "You have no healthy Popsmon to explore!\n";
                std::cout << "Visit the \033[1;33mPops Center\033[0m to heal your Popsmon.\n";
                continue;
            }
            Popsmon wild = Popsopedia::randomWild();
            std::cout << "\nA wild " << wild.name << " appeared!\n";
            battle(player, wild);
        }
        else if (choice == 2) {
            player.showCollection();
        }
        else if (choice == 3) {
            std::cout << "\n========================================\n";
            std::cout << "             \033[1;33mPOPS CENTER\033[0m\n";
            std::cout << "========================================\n";
            for (auto& p : player.popsmonCollection) {
                p.heal(p.maxHealth); // Heal to max health
            }
            std::cout << "\n\033[1;32mYour Popsmon have been fully healed.\033[0m\n";
        }
        else if (choice == 4) {
            std::cout << "See you again Traveler!\n";
            break;
        }
        else {
            std::cout << "Invalid choice.\n";
        }
    }
}

void Game::showControls() {
    std::cout << "\n========================================\n";
    std::cout << "               HOW TO PLAY\n";
    std::cout << "========================================\n\n";

    std::cout << "▶ \033[92mEXPLORATION\033[0m\n";
    std::cout << "  Travel across Loisinia to\n";
    std::cout << "  encounter wild Popsmon.\n\n";

    std::cout << "▶ \033[91mBATTLE\033[0m\n";
    std::cout << "  • Choose moves each turn\n";
    std::cout << "  • Switch Popsmon when needed\n";
    std::cout << "  • Type matchups affect damage\n\n";

    std::cout << "▶ \033[96mPARTY\033[0m\n";
    std::cout << "  • Carry multiple Popsmon\n";
    std::cout << "  • Swap during battle\n\n";
    //std::cout << "  • Heal between encounters (future!)\n\n";

    std::cout << "▶ MENU\n";
    std::cout << "  • Explore     – Find wild Popsmon\n";
    std::cout << "  • Popsopedia  – View your Popsmon in your party\n";
    std::cout << "  • Pops Center – Heal your damaged Popsmon\n";
    std::cout << "  • Exit        – Leave the adventure\n\n";

    std::cout << "========================================\n";
    std::cout << "        PRESS ENTER TO CONTINUE\n";
    std::cout << "========================================\n";

    std::cin.ignore();
    std::cin.get();
}

void Game::drawBattleUI(const Popsmon& active, const Popsmon& wildPopsmon) {
    std::cout << "\n========================================\n";
    std::cout << "   YOUR POPSMON              WILD POPSMON\n";
    std::cout << "   " << active.name << " (HP: " << active.health << "/" << active.maxHealth << ")\n";
    std::cout << "   \033[91mVS\033[0m\n";
    std::cout << "   " << wildPopsmon.name << " (HP: " << wildPopsmon.health << "/" << wildPopsmon.maxHealth << ")\n";
    std::cout << "========================================\n";
}

Popsmon Game::chooseStarter() {
    std::cout << "\nChoose your starter Popsmon:\n";
    std::cout << "1. \033[31mSolarion (Fire)\033[0m\n";
    std::cout << "2. \033[32mThornbreaker (Nature)\033[0m\n";
    std::cout << "3. \033[34mAquastral (Water)\033[0m\n";
    std::cout << "Choice: ";

    int choice;
    std::cin >> choice;

    while (!choice) {
            std::cout << "Please enter a number!\n";
            std::cin.clear(); // clear error flag
            std::cin.ignore(); // discard invalid input
            std::cin >> choice;
        }
    if(choice == 1) { 
        std::cout << "You chose \033[31mSolarion\033[0m\n";
        return Popsopedia::get("Solarion"); }
    if (choice == 2) { 
        std::cout << "You chose \033[32mThornbreaker\033[0m\n";
        return Popsopedia::get("Thornbreaker"); }
    if (choice == 3) { 
        std::cout << "You chose \033[34mAquastral\033[0m\n";
        return Popsopedia::get("Aquastral"); }
    else {
        std::cout << "Invalid Selection. Defaulting to Solarion\n";
        return Popsopedia::get("Solarion") ;
        }
    }


void Game::drawPartyUI(const Player& player, int activeIndex) {
    std::cout << "\n========================================\n";
    std::cout << "              YOUR PARTY\n";
    std::cout << "========================================\n";

    for (int i = 0; i < (int)player.popsmonCollection.size(); i++) {
        const auto& p = player.popsmonCollection[i];

        //Active Popsmon highlight
        if (i == activeIndex)
            std::cout << "-> " << i+1 << ". " << p.name
                      << "  (ACTIVE)\n"; 
        else {

            std::cout << i+1 << ". " << p.name << "\n";
        }
        std::cout << "      HP: " << p.health << "/" << p.maxHealth << "  \n";

    // Fainted indicator
    if (p.health <= 0) {
        std::cout << "   \033[91mFAINTED\033[0m\n";
    }

    std::cout << "\n";
    }

    std::cout << "============================================\n";
}

bool Game::battle(Player& player, Popsmon& wildPopsmon) {
    int activeIndex = 0; 
    while (true) {
         Popsmon& active = player.popsmonCollection[activeIndex];

        drawBattleUI(active, wildPopsmon);

        std::cout << "\nChoose your action:\n";
        for (int i = 0; i < (int)active.moves.size(); i++) {
        std::cout << "  " << i+1 << ". " << active.moves[i].name
                  << "  [" << typeToString(active.moves[i].type) << "]\n";
        }
        std::cout << "  " << active.moves.size() + 1 << ". \033[36mSwitch Popsmon\033[0m\n";
        std::cout << "  " << active.moves.size() + 2 << ". \033[95mCapture\033[0m\n\n";
        std::cout << "========================================\n";
        std::cout << "Action: ";

        int choice;
        std::cin >> choice;

        if (!choice) {
            std::cout << "Please enter a number!\n";
            std::cin.clear(); // clear error flag
            std::cin.ignore(); // discard invalid input
            continue;
        }
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
                if (i == activeIndex) continue; // Skip active Popsmon
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

                if (player.popsmonCollection[activeIndex].health <= 0) {
                    std::cout << "Cannot switch to a fainted Popsmon!\n";
                    continue;
                }
                std::cout << "Go, " << player.popsmonCollection[activeIndex].name << "!\n";
                continue; // skip wild turn
            } else {
                std::cout << "Invalid choice.\n";
                continue;
            }
        
        }
        else if (choice == (int)active.moves.size() + 2) {
            if (attemptCapture(wildPopsmon)) {
                std::cout << "You successfully captured the wild " << wildPopsmon.name << "!\n";
                player.addPopsmon(wildPopsmon);
                return true;
            } else {
                std::cout << "The wild " << wildPopsmon.name << " escaped!\n";
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

            // Check if player has any Popsmon left
            bool hasAlive = false;
            for (const auto& p : player.popsmonCollection) {
                if (p.health > 0) {
                    hasAlive = true;
                    break;
                }
            }

            if (!hasAlive) {
                std::cout << "You have no Popsmon left!\n";
                return false;
            }

            while (true) {
                drawPartyUI(player, activeIndex);
                std::cout << "Choose another Popsmon to send out:\n";
            
                int swapChoice;
                std::cin >> swapChoice;
                int newIndex = swapChoice - 1;

                if (newIndex < 0 || newIndex >= (int)player.popsmonCollection.size()) {
                    std::cout << "Invalid choice.\n";
                    continue;
                }

                if (player.popsmonCollection[newIndex].health <= 0) {
                    std::cout << "That popsmon has fainted!\n";
                    continue;
                }

            activeIndex = newIndex;
            std::cout << "Go, " 
                      << player.popsmonCollection[activeIndex].name 
                      << "!\n";
            
            break;
        }
        continue;
        }
    }
}

bool Game::attemptCapture(const Popsmon& wildPopsmon) { // Capture logic
    // Lower HP increases capture chance
    float healthRatio = (float)wildPopsmon.health / wildPopsmon.maxHealth; // Health ratio

    // Base chance 50%
    float baseChance = 0.5f;

    //Reduce chance based on health
    float finalChance = baseChance * (1.0f - healthRatio); // Higher chance with lower health

    // Clamp minimum chance
    if (finalChance < 0.1f) finalChance = 0.1f; // Minimum 10% chance

    float roll = std::rand() / static_cast<float>(RAND_MAX);   // Random roll between 0 and 1 
    return roll < finalChance;

    }