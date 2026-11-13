#include "FootballManager.h"
#include <iostream>
#include <string>
#include <stdexcept>


// Constructor: Set up the Houston Texans
FootballManager::FootballManager()
    : myTeam("Houston Texans")
{
    myTeam.addPlayer(Player("C.J. Stroud", "QB", 7, 90));
    myTeam.addPlayer(Player("Nico Collins", "WR", 12, 92));
    myTeam.addPlayer(Player("Will Anderson Jr.", "DE", 51, 95));
}

// Validate numeric input
int FootballManager::getValidNumber(int min, int max)
{
    std::string input;

    while (true)
    {
        std::getline(std::cin, input);

        try
        {
            int number = std::stoi(input);

            if (input.find_first_not_of("0123456789")
                != std::string::npos)
            {
                std::cout << "Invalid input. Enter a whole number: ";
                continue;
            }

            if (number >= min && number <= max)
            {
                return number;
            }

            std::cout << "Enter a number between "
                << min << " and " << max << ": ";
        }
        catch (const std::invalid_argument&)
        {
            std::cout << "Invalid input. Please enter a number: ";
        }
        catch (const std::out_of_range&)
        {
            std::cout << "Number is too large. Try again: ";
        }
    }
}

// Display main menu
void FootballManager::DisplayMenu()
{
    std::cout << "\n================================\n";
    std::cout << "    FOOTBALL TEAM MANAGER\n";
    std::cout << "================================\n";
    std::cout << "1. View Team Roster\n";
    std::cout << "2. Add Player\n";
    std::cout << "3. Remove Player\n";
    std::cout << "4. Simulate Game\n";
    std::cout << "5. View Team Rating\n";
    std::cout << "6. View Player Details\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

// View roster
void FootballManager::ViewRoster()
{
    myTeam.displayRoster();
}
void FootballManager::ViewTeamRating()
{
    std::cout << "\n===== TEAM RATING =====\n";
    std::cout << "Team: Houston Texans\n";
    std::cout << "Players: " << myTeam.getRosterSize() << "\n";

    if (myTeam.getRosterSize() == 0)
    {
        std::cout << "No players on the roster.\n";
        std::cout << "Add players to calculate a team rating.\n";
        return;
    }

    std::cout << "Overall Rating: "
        << myTeam.getAverageRating() << "\n";
}

// Add a new player
void FootballManager::AddPlayer()
{
    std::string name;
    std::string position;

    std::cout << "\nEnter player name: ";
    std::getline(std::cin, name);

    while (name.find_first_not_of(" \t") == std::string::npos)
    {
        std::cout << "Name cannot be empty: ";
        std::getline(std::cin, name);
    }

    std::cout << "Enter position (QB, RB, WR, etc.): ";
    std::getline(std::cin, position);

    while (position.find_first_not_of(" \t") == std::string::npos)
    {
        std::cout << "Position cannot be empty: ";
        std::getline(std::cin, position);
    }

    std::cout << "Enter jersey number (0-99): ";
    int jersey = getValidNumber(0, 99);

    std::cout << "Enter overall rating (1-99): ";
    int rating = getValidNumber(1, 99);

    Player newPlayer(name, position, jersey, rating);
    myTeam.addPlayer(newPlayer);
}

// Remove a player
void FootballManager::RemovePlayer()
{
    std::cout << "\nEnter jersey number to remove (0-99): ";
    int jersey = getValidNumber(0, 99);

    if (myTeam.removePlayer(jersey))
    {
        std::cout << "Player removed successfully!\n";
    }
    else
    {
        std::cout << "Player not found.\n";
    }
}

// Simulate a football game
void FootballManager::SimulateGame()
{
    // Prevent games when the roster is empty
    if (myTeam.getRosterSize() == 0)
    {
        std::cout << "\nCannot simulate a game!\n";
        std::cout << "Your team has no players.\n";
        std::cout << "Please add players before simulating.\n";
        return;
    }

    std::string opponent;

    std::cout << "\nEnter opponent team name: ";
    std::getline(std::cin, opponent);

    while (opponent.find_first_not_of(" \t") == std::string::npos)
    {
        std::cout << "Opponent name cannot be empty: ";
        std::getline(std::cin, opponent);
    }

    footballGame.simulateGame(myTeam, opponent);
    footballGame.displayResult();
}


void FootballManager::ViewPlayerDetails()
{
    std::cout << "Enter jersey number: ";

    int jersey = getValidNumber(0, 99);

    Player* player = myTeam.findPlayer(jersey);

    if (player == nullptr)
    {
        std::cout << "Player not found.\n";
        return;
    }

    std::cout << "Player Name: " << player->getName() << "\n";
    std::cout << "Position: " << player->getPosition() << "\n";
    std::cout << "Overall Rating: " << player->getOverallRating() << "\n";
}


// Run the application
void FootballManager::Run()
{
    int choice;

    do
    {
        DisplayMenu();

        choice = getValidNumber(0, 6);

        switch (choice)
        {
        case 1:
            ViewRoster();
            break;

        case 2:
            AddPlayer();
            break;

        case 3:
            RemovePlayer();
            break;

        case 4:
            SimulateGame();
            break;

        case 5:
            ViewTeamRating();
            break;

        case 6:
            ViewPlayerDetails();
            break;

        case 0:
            std::cout << "\nThanks for playing Football Team Manager!\n";
            break;
        }

    } while (choice != 0);
}