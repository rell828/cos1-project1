#pragma once
#include <string>
#include <vector>
#include "Player.h"

class Team
{
private:
    std::string teamName;
    std::vector<Player> roster;

public:
    // Constructor
    Team(const std::string& name);

    // Add player to roster
    void addPlayer(const Player& player);

    // Remove player by jersey number
    bool removePlayer(int jerseyNumber);

    // Display team roster
    void displayRoster() const;

    // Get number of players
    int getRosterSize() const;
};