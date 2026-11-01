#include "Game.h"
#include <iostream>
#include <random>

Game::Game()
{
    homeScore = 0;
    awayScore = 0;
    opponentName = "Unknown";
}

void Game::simulateGame(const Team& team,
    const std::string& opponent)
{
    opponentName = opponent;

    // Random number generator
    static std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> score(0, 42);

    homeScore = score(generator);
    awayScore = score(generator);

    std::cout << "\nSimulating game against "
        << opponentName << "...\n";

    std::cout << "Players on your roster: "
        << team.getRosterSize() << "\n";
}

void Game::displayResult() const
{
    std::cout << "\n===== GAME RESULTS =====\n";
    std::cout << "Your Team: " << homeScore << "\n";
    std::cout << opponentName << ": " << awayScore << "\n";

    if (homeScore > awayScore)
    {
        std::cout << "Your team wins!\n";
    }
    else if (awayScore > homeScore)
    {
        std::cout << "Your team loses!\n";
    }
    else
    {
        std::cout << "It's a tie!\n";
    }
}