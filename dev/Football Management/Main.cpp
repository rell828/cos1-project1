// Football Management.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "Player.h"
#include "Team.h"

int main()
{
    // Create football team
    Team myTeam("Houston Texans");

    // Create players
    Player player1("C.J. Stroud", "QB", 7, 90);
    Player player2("Will Anderson Jr.", "DE", 51, 95);
    Player player3("Nico Collins", "WR", 12, 92);

    // Add players to team
    myTeam.addPlayer(player1);
    myTeam.addPlayer(player2);
    myTeam.addPlayer(player3);

    // Display roster
    myTeam.displayRoster();

    // Display roster size
    std::cout << "\nTotal Players: "
        << myTeam.getRosterSize()
        << "\n";

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
