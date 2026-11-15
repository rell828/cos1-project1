#include "Player.h"
#include <iostream>

Player::Player()
{
    name = "Unknown";
    position = "Unknown";
    jerseyNumber = 0;
    overallRating = 50;

    passingYards = 0;
    rushingYards = 0;
    receivingYards = 0;
    touchdowns = 0;
}

Player::Player(const std::string& name,
    const std::string& position,
    int jerseyNumber,
    int overallRating)
{
    this->name = name;
    this->position = position;
    this->jerseyNumber = jerseyNumber;
    this->overallRating = overallRating;

    passingYards = 0;
    rushingYards = 0;
    receivingYards = 0;
    touchdowns = 0;
}

std::string Player::getName() const
{
    return name;
}

std::string Player::getPosition() const
{
    return position;
}

int Player::getJerseyNumber() const
{
    return jerseyNumber;
}

int Player::getOverallRating() const
{
    return overallRating;
}

// Statistics getters
int Player::getPassingYards() const
{
    return passingYards;
}

int Player::getRushingYards() const
{
    return rushingYards;
}

int Player::getReceivingYards() const
{
    return receivingYards;
}

int Player::getTouchdowns() const
{
    return touchdowns;
}

// Add new statistics to existing totals
void Player::addStats(int passing, int rushing,
    int receiving, int touchdownCount)
{
    passingYards += passing;
    rushingYards += rushing;
    receivingYards += receiving;
    touchdowns += touchdownCount;
}

// Display player information
void Player::displayPlayer() const
{
    std::cout << "\nPlayer: " << name << "\n";
    std::cout << "Position: " << position << "\n";
    std::cout << "Jersey Number: " << jerseyNumber << "\n";
    std::cout << "Overall Rating: " << overallRating << "\n";

    std::cout << "\n===== PLAYER STATISTICS =====\n";
    std::cout << "Passing Yards: " << passingYards << "\n";
    std::cout << "Rushing Yards: " << rushingYards << "\n";
    std::cout << "Receiving Yards: " << receivingYards << "\n";
    std::cout << "Touchdowns: " << touchdowns << "\n";
}


