#pragma once
#include <string>

class Player
{
private:
    std::string name;
    std::string position;
    int jerseyNumber;
    int overallRating;

    // Player statistics
    int passingYards;
    int rushingYards;
    int receivingYards;
    int touchdowns;

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

    // Statistics getters
    int getPassingYards() const;
    int getRushingYards() const;
    int getReceivingYards() const;
    int getTouchdowns() const;

    // Update player statistics
    void addStats(int passing, int rushing,
        int receiving, int touchdownCount);

    // Display player information
    void displayPlayer() const;
};