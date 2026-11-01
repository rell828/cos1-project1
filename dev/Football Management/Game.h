#pragma once
#include <string>
#include "Team.h"

class Game
{
private:
    int homeScore;
    int awayScore;
    std::string opponentName;

public:
    // Constructor
    Game();

    // Simulate a football game
    void simulateGame(const Team& team,
        const std::string& opponent);

    // Display game results
    void displayResult() const;
};
