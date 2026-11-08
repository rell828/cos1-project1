#pragma once
#include "Team.h"

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
public:
    FootballManager();
    void Run();

  
};