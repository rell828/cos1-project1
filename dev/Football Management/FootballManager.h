#pragma once
#include "Player.h"
#include "Team.h"
#include "Game.h"

class FootballManager
{
private:
    Team myTeam;
    Game footballGame;

    int getValidNumber(int min, int max);

    void DisplayMenu();
    void ViewRoster();
    void AddPlayer();
    void RemovePlayer();
    void SimulateGame();
    void ViewTeamRating();
    void ViewPlayerDetails();

    // Pointer-based player management
    void DisplayPlayerDetails(Player* player);
    void UpdatePlayerRating(Player* player, int newRating);

public:
    FootballManager();

    void Run();
};