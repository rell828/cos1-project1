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

    static std::mt19937 generator(std::random_device{}());

    // Get your team's average player rating
    double teamRating = team.getAverageRating();

    // Generate an opponent rating between 60 and 95
    std::uniform_int_distribution<int> opponentRatings(60, 95);
    int opponentRating = opponentRatings(generator);

    // Random variation keeps games unpredictable
    std::uniform_int_distribution<int> variation(-12, 12);

    // Ratings influence the final scores
    homeScore = static_cast<int>(teamRating * 0.35)
        + variation(generator);

    awayScore = static_cast<int>(opponentRating * 0.35)
        + variation(generator);

    // Prevent negative scores
    if (homeScore < 0)
        homeScore = 0;

    if (awayScore < 0)
        awayScore = 0;

    std::cout << "\nSimulating game against "
        << opponentName << "...\n";

    std::cout << "Your Team Rating: "
        << teamRating << "\n";

    std::cout << "Opponent Rating: "
        << opponentRating << "\n";

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