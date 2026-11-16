#include "Team.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>


Team::Team(const std::string& name)
{
    teamName = name;
}

void Team::addPlayer(const Player& player)
{
    // Prevent duplicate jersey numbers
    for (const Player& existing : roster)
    {
        if (existing.getJerseyNumber() ==
            player.getJerseyNumber())
        {
            std::cout << "Jersey number already exists!\n";
            return;
        }
    }

    roster.push_back(player);
    std::cout << player.getName()
        << " added to the roster!\n";
}

bool Team::removePlayer(int jerseyNumber)
{
    for (size_t i = 0; i < roster.size(); i++)
    {
        if (roster[i].getJerseyNumber() == jerseyNumber)
        {
            roster.erase(roster.begin() + i);
            return true;
        }
    }

    return false;
}

void Team::displayRoster() const
{
    std::cout << "\n===== " << teamName
        << " ROSTER =====\n";

    if (roster.empty())
    {
        std::cout << "No players on roster.\n";
        return;
    }

    for (const Player& player : roster)
    {
        player.displayPlayer();
        std::cout << "-----------------\n";
    }
}

int Team::getRosterSize() const
{
    return static_cast<int>(roster.size());
}


double Team::getAverageRating() const
{
    if (roster.empty())
    {
        return 0.0;
    }

    double totalRating = 0;

    for (const Player& player : roster)
    {
        totalRating += player.getOverallRating();
    }

    return totalRating / roster.size();

   
}


  Player* Team::findPlayer(int jerseyNumber)
   {
    for (Player& player : roster)
    {
        if (player.getJerseyNumber() == jerseyNumber)
        {
            return &player;
        }
    }

    return nullptr;
}
  // Save team data to a file
  bool Team::saveTeamData() const
  {
      std::ofstream file("team_data.txt");

      if (!file.is_open())
      {
          std::cout << "Unable to save team data.\n";
          return false;
      }

      file << std::quoted(teamName) << "\n";

      for (const Player& player : roster)
      {
          file << std::quoted(player.getName()) << " "
              << std::quoted(player.getPosition()) << " "
              << player.getJerseyNumber() << " "
              << player.getOverallRating() << "\n";
      }

      std::cout << "Team data saved successfully!\n";
      return true;
  }

  // Load team data from a file
  bool Team::loadTeamData()
  {
      std::ifstream file("team_data.txt");

      if (!file.is_open())
      {
          std::cout << "Save file not found.\n";
          return false;
      }

      std::string loadedTeamName;

      if (!(file >> std::quoted(loadedTeamName)))
      {
          std::cout << "Invalid save file.\n";
          return false;
      }

      std::string line;
      std::getline(file, line);

      std::vector<Player> loadedRoster;

      while (std::getline(file, line))
      {
          if (line.empty())
          {
              continue;
          }

          std::istringstream record(line);

          std::string name;
          std::string position;
          int jerseyNumber;
          int rating;
          std::string extra;

          if (!(record >> std::quoted(name)
              >> std::quoted(position)
              >> jerseyNumber
              >> rating))
          {
              std::cout << "Invalid player data in save file.\n";
              return false;
          }

          if (record >> extra)
          {
              std::cout << "Unexpected extra data in save file.\n";
              return false;
          }

          if (jerseyNumber < 0 || jerseyNumber > 99 ||
              rating < 1 || rating > 99)
          {
              std::cout << "Invalid player information in save file.\n";
              return false;
          }

          for (const Player& existing : loadedRoster)
          {
              if (existing.getJerseyNumber() == jerseyNumber)
              {
                  std::cout << "Duplicate jersey number in save file.\n";
                  return false;
              }
          }

          loadedRoster.push_back(
              Player(name, position, jerseyNumber, rating)
          );
      }

      if (file.bad())
      {
          std::cout << "Error reading save file.\n";
          return false;
      }

      teamName = loadedTeamName;
      roster = loadedRoster;

      std::cout << "Team data loaded successfully!\n";
      return true;
  }