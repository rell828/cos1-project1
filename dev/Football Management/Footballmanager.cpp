#include "FootballManager.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

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
    int number;

    while (true)
    {
        if (cin >> number && number >= min && number <= max)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return number;
        }

        cout << "Invalid input. Enter a number from "
            << min << " to " << max << ": ";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Display main menu
void FootballManager::DisplayMenu()
{
    cout << "\n================================\n";
    cout << "    FOOTBALL TEAM MANAGER\n";
    cout << "================================\n";
    cout << "1. View Team Roster\n";
    cout << "2. Add Player\n";
    cout << "3. Remove Player\n";
    cout << "4. Simulate Game\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

// View roster
void FootballManager::ViewRoster()
{
    myTeam.displayRoster();
}

// Add a new player
void FootballManager::AddPlayer()
{
    string name;
    string position;

    cout << "\nEnter player name: ";
    getline(cin, name);

    while (name.find_first_not_of(" \t") == string::npos)
    {
        cout << "Name cannot be empty: ";
        getline(cin, name);
    }

    cout << "Enter position (QB, RB, WR, etc.): ";
    getline(cin, position);

    while (position.find_first_not_of(" \t") == string::npos)
    {
        cout << "Position cannot be empty: ";
        getline(cin, position);
    }

    cout << "Enter jersey number (0-99): ";
    int jersey = getValidNumber(0, 99);

    cout << "Enter overall rating (1-99): ";
    int rating = getValidNumber(1, 99);

    Player newPlayer(name, position, jersey, rating);
    myTeam.addPlayer(newPlayer);
}

// Remove a player
void FootballManager::RemovePlayer()
{
    cout << "\nEnter jersey number to remove (0-99): ";
    int jersey = getValidNumber(0, 99);

    if (myTeam.removePlayer(jersey))
    {
        cout << "Player removed successfully!\n";
    }
    else
    {
        cout << "Player not found.\n";
    }
}

// Simulate a football game
void FootballManager::SimulateGame()
{
    string opponent;

    cout << "\nEnter opponent team name: ";
    getline(cin, opponent);

    while (opponent.find_first_not_of(" \t") == string::npos)
    {
        cout << "Opponent name cannot be empty: ";
        getline(cin, opponent);
    }

    footballGame.simulateGame(myTeam, opponent);
    footballGame.displayResult();
}

// Run the application
void FootballManager::Run()
{
    int choice;

    do
    {
        DisplayMenu();
        choice = getValidNumber(0, 4);

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

        case 0:
            cout << "\nThanks for playing Football Team Manager!\n";
            break;
        }

    } while (choice != 0);
}