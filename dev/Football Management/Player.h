#pragma once
#include <string>

class Player
{
private:
    std::string name;
    std::string position;
    int jerseyNumber;
    int overallRating;

public:
    // Default constructor
    Player();

    // Overloaded constructor
    Player(const std::string& name,
        const std::string& position,
        int jerseyNumber,
        int overallRating);

    // Getters
    std::string getName() const;
    std::string getPosition() const;
    int getJerseyNumber() const;
    int getOverallRating() const;

    // Display player information
    void displayPlayer() const;
};