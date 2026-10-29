#include "Player.h"
#include <iostream>

Player::Player()
{
    name = "Unknown";
    position = "Unknown";
    jerseyNumber = 0;
    overallRating = 50;
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

void Player::displayPlayer() const
{
    std::cout << "\nPlayer: " << name << "\n";
    std::cout << "Position: " << position << "\n";
    std::cout << "Jersey Number: " << jerseyNumber << "\n";
    std::cout << "Overall Rating: " << overallRating << "\n";
}