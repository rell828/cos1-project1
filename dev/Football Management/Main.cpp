// Football Management.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include <limits>
#include "Player.h"
#include "Team.h"
#include "Game.h"

using namespace std;

// Function to get a valid number
int getValidNumber(int min, int max)
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

int main()
{
    Team myTeam("Houston Texans");
    Game footballGame;

    // Starting roster
    myTeam.addPlayer(Player("C.J. Stroud", "QB", 7, 90));
    myTeam.addPlayer(Player("Nico Collins", "WR", 12, 92));
    myTeam.addPlayer(Player("Will Anderson Jr.", "DE", 51, 95));

    int choice;

    do
    {
        cout << "\n================================\n";
        cout << "    FOOTBALL TEAM MANAGER\n";
        cout << "================================\n";
        cout << "1. View Team Roster\n";
        cout << "2. Add Player\n";
        cout << "3. Remove Player\n";
        cout << "4. Simulate Game\n";
        cout << "0. Exit\n";

        choice = getValidNumber(0, 4);

        switch (choice)
        {
        case 1:
        {
            myTeam.displayRoster();
            break;
        }

        case 2:
        {
            string name;
            string position;

            cout << "\nEnter player name: ";
            getline(cin, name);

            while (name.empty())
            {
                cout << "Name cannot be empty: ";
                getline(cin, name);
            }

            cout << "Enter position (QB, RB, WR, etc.): ";
            getline(cin, position);

            while (position.empty())
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

            break;
        }

        case 3:
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

            break;
        }
        case 4:
        {
            string opponent;

            cout << "\nEnter opponent team name: ";
            getline(cin, opponent);

            while (opponent.find_first_not_of(" \t") ==
                string::npos)
            {
                cout << "Opponent name cannot be empty: ";
                getline(cin, opponent);
            }

            footballGame.simulateGame(myTeam, opponent);
            footballGame.displayResult();

            break;
        }

        case 0:
        {
            cout << "\nThanks for playing Football Team Manager!\n";
            break;
        }


        }

    } while (choice != 0);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
