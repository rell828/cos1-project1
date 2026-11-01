#include "Team.h"
#include <iostream>

Team::Team(const std::string& name)
{
    teamName = name;
}

void Team::addPlayer(const Player& player)
{
    // Prevent duplicate jersey numbers
    for (const Player& existing : roster)
    {
        if (existing.getJerseyNumber() ==
            player.getJerseyNumber())
        {
            std::cout << "Jersey number already exists!\n";
            return;
        }
    }

    roster.push_back(player);
    std::cout << player.getName()
        << " added to the roster!\n";
}

bool Team::removePlayer(int jerseyNumber)
{
    for (size_t i = 0; i < roster.size(); i++)
    {
        if (roster[i].getJerseyNumber() == jerseyNumber)
        {
            roster.erase(roster.begin() + i);
            return true;
        }
    }

    return false;
}

void Team::displayRoster() const
{
    std::cout << "\n===== " << teamName
        << " ROSTER =====\n";

    if (roster.empty())
    {
        std::cout << "No players on roster.\n";
        return;
    }

    for (const Player& player : roster)
    {
        player.displayPlayer();
        std::cout << "-----------------\n";
    }
}

int Team::getRosterSize() const
{
    return static_cast<int>(roster.size());
}