#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <fstream>
#include <sstream>

struct Player {
    std::string name;
    std::string position;
    int touchdowns = 0;
    int passingYards = 0;
    int interceptions = 0;
    int recievingYards = 0;
    int recievingTouchdowns = 0;
    int fumbles = 0;
    int sacks = 0;
    int rushingYards = 0;
    int defensiveTouchdowns = 0;
    int defensiveSacks = 0;
    int defensiveYards = 0;
    int deflections = 0;
    int tackles = 0;
    int forcedFumbles = 0;
    int fumbleRecoveries = 0;
    int pancakes = 0;
    int safeties = 0;
    int safetiesScored = 0;
    int sacksAllowed = 0;
    int attempts = 0;
    int completions = 0;
    int receivingTargets = 0;
    int receptions = 0;
    int receivingDrops = 0;
    int receivingYardsAfterCatch = 0; // not currently used but could be added in the future
    int receivingYardsPerReception = 0; // same as above
    int receivingYardsPerTarget = 0; // same as above
    int gamesPlayed = 0; 
    int wins = 0;
    int losses = 0;
    int pressures = 0;
    int completionsAllowed = 0; 
    int yardageAllowed = 0;
};

struct StatEntry {
    std::string label;
    int Player::*field;
};

std::string toTitleCase(const std::string& str) {
    std::string title = str;
    bool newWord = true;

    for (char& c : title) {
        if(c == ' ') {
            newWord = true;
        }
        else if (newWord) {
            c = std::toupper(c);
            newWord = false;
        }
        else {
            c = std::tolower(c);
        }
    }
    return title;
}

std::string toUpperCase(const std::string& str) {
    std::string upper = str;
    for (char& c : upper) {
        c = std::toupper(c);
    }
    return upper;
}

std::string toLowerCase(const std::string& str) {
    std::string lower = str;
    for (char& c : lower) {
        c = std::tolower(c);
    }
    return lower;
}

void displayMenu() {    
    std::cout << std::endl << "Menu:" << std::endl << std::endl;
    std::cout << "1. Add Player" << std::endl;
    std::cout << "2. Remove Player" << std::endl;
    std::cout << "3. Player Stat Menu" << std::endl;
    std::cout << "4. Quit" << std::endl << std::endl;
}

std::vector<StatEntry> getStats(const Player& p) {
    
    std::vector<StatEntry> stats;

    if (p.position == "QB") {
        stats = {
            {"Touchdowns", &Player::touchdowns},
            {"Passing Yards", &Player::passingYards},
            {"Rushing Yards", &Player::rushingYards},
            {"Sacked", &Player::sacks},
            {"Safeties", &Player::safeties},
            {"Interceptions", &Player::interceptions},
            {"Fumbles", &Player::fumbles},
            {"Fumbles Recovered ", &Player::fumbleRecoveries},
            {"Attempts", &Player::attempts},
            {"Completions", &Player::completions},
            {"Games Played", &Player::gamesPlayed},
            {"Wins", &Player::wins},
            {"Losses", &Player::losses}
        };
    }
       
    else if (p.position == "RB") {
            stats = {
                {"Touchdowns", &Player::touchdowns},
                {"Rushing Yards", &Player::rushingYards},
                {"Receiving Yards", &Player::recievingYards},
                {"Receiving Touchdowns", &Player::recievingTouchdowns},
                {"Receiving Targets", &Player::receivingTargets},
                {"Receptions", &Player::receptions},
                {"Receiving Drops", &Player::receivingDrops},
                {"Pancakes", &Player::pancakes},
                {"Fumbles", &Player::fumbles},
                {"Fumbles Recovered ", &Player::fumbleRecoveries},
                {"Sacks Allowed", &Player::sacksAllowed},
                {"Safeties", &Player::safeties},
                {"Interceptions", &Player::interceptions},
                {"Games Played", &Player::gamesPlayed},
                {"Wins", &Player::wins},
                {"Losses", &Player::losses}
            };
        }
       
        else if (p.position == "WR" || p.position == "TE") {
            stats = {
                {"Touchdowns", &Player::touchdowns},
                {"Receiving Yards", &Player::recievingYards},
                {"Receiving Touchdowns", &Player::recievingTouchdowns},
                {"Receiving Targets", &Player::receivingTargets},
                {"Receptions", &Player::receptions},
                {"Receiving Drops", &Player::receivingDrops},
                {"Pancakes", &Player::pancakes},
                {"Fumbles", &Player::fumbles},
                {"Fumbles Recovered ", &Player::fumbleRecoveries},
                {"Sacks Allowed", &Player::sacksAllowed},
                {"Safeties", &Player::safeties},
                {"Interceptions", &Player::interceptions},
                {"Games Played", &Player::gamesPlayed},
                {"Wins", &Player::wins},
                {"Losses", &Player::losses}
            };
        }
       
        else if (p.position == "OT" || p.position == "OG" || p.position == "C") {
            stats = {
                {"Pancakes", &Player::pancakes},
                {"Sacks Allowed", &Player::sacksAllowed},
                {"Fumbles Recovered ", &Player::fumbleRecoveries},
                {"Games Played", &Player::gamesPlayed},
                {"Wins", &Player::wins},
                {"Losses", &Player::losses}
            };
        }
       
        else if (p.position == "DE" || p.position == "DT") {
            stats = {
                {"Tackles", &Player::tackles},
                {"Pressures", &Player::pressures},
                {"Sacks", &Player::defensiveSacks},
                {"Fumbles Forced", &Player::forcedFumbles},
                {"Fumbles Recovered", &Player::fumbleRecoveries},
                {"Deflections", &Player::deflections},
                {"Interceptions", &Player::interceptions},
                {"Safeties Forced", &Player::safetiesScored},
                {"Defensive Yardage", &Player::defensiveYards},
                {"Touchdowns", &Player::defensiveTouchdowns},
                {"Games Played", &Player::gamesPlayed},
                {"Wins", &Player::wins},
                {"Losses", &Player::losses}
            };
        }
       
        else if (p.position == "OLB" || p.position == "ILB") {
            stats = {
                {"Tackles", &Player::tackles},
                {"Pressures", &Player::pressures},
                {"Sacks", &Player::defensiveSacks},
                {"Fumbles Forced", &Player::forcedFumbles},
                {"Fumbles Recovered", &Player::fumbleRecoveries},
                {"Completions Allowed", &Player::completionsAllowed},
                {"Yardage Allowed", &Player::yardageAllowed},
                {"Deflections", &Player::deflections},
                {"Interceptions", &Player::interceptions},
                {"Safeties Forced", &Player::safetiesScored},
                {"Defensive Yardage", &Player::defensiveYards},
                {"Touchdowns", &Player::defensiveTouchdowns},
                {"Games Played", &Player::gamesPlayed},
                {"Wins", &Player::wins},
                {"Losses", &Player::losses}
            };  
        }
    
        else if (p.position == "CB" || p.position == "FS" || p.position == "SS") {
        stats = {
                {"Tackles", &Player::tackles},
                {"Pressures", &Player::pressures},
                {"Sacks", &Player::defensiveSacks},
                {"Fumbles Forced", &Player::forcedFumbles},
                {"Fumbles Recovered", &Player::fumbleRecoveries},
                {"Completions Allowed", &Player::completionsAllowed},
                {"Yardage Allowed", &Player::yardageAllowed},
                {"Deflections", &Player::deflections},
                {"Interceptions", &Player::interceptions},
                {"Safeties Forced", &Player::safetiesScored},
                {"Defensive Yardage", &Player::defensiveYards},
                {"Touchdowns", &Player::defensiveTouchdowns},
                {"Games Played", &Player::gamesPlayed},
                {"Wins", &Player::wins},
                {"Losses", &Player::losses}
            };
    }         
        
    else {
                std::cout << "Position: Unknown" << std::endl << '\n';
            }

    return stats;
}

void printStats(const Player& p, const std::vector<StatEntry>& stats) {

std::cout << "Position: " << p.position << std::endl;
    for (const auto& s : stats) {
        std::cout << s.label << ": " << p.*s.field << std::endl;
    }
}

void editStats(Player& p, std::vector<StatEntry>& stats) {
    
    std::string userInput;

    std::cout << std::endl << "Please select a stat to edit for " << p.name << std::endl;
    std::cout << "0. Cancel" << std::endl;

    for (size_t i = 0; i < stats.size(); i++) {
        std::cout << i + 1 << ". " << stats[i].label << ": " << p.*stats[i].field << std::endl;
    }

    std::getline(std::cin, userInput);
    int statChoice = 0;
    
    try {
        statChoice = stoi(userInput);
    }

    catch (const std::invalid_argument&) {
        std::cout << std::endl << "Invalid input! Returning to menu." << std::endl;
        return;
    }

    catch (const std::out_of_range&) {
        std::cout << std::endl << "Input out of range! Returning to menu." << std::endl;
        return;
    }


    if (statChoice == 0) {
        std::cout << std::endl << "Edit cancelled! Returning to menu." << std::endl;
        return;
    }

    else if (statChoice >= 1 && statChoice <= (int)stats.size()) {
        auto& stat = stats[statChoice - 1];
        std::cout << stat.label << ": " << p.*stat.field << std::endl;
        std::getline(std::cin, userInput);
        int newValue = 0;

        try {
            newValue = stoi(userInput);
        }

        catch (const std::invalid_argument&) {
            std::cout << std::endl << "Invalid input! Returning to menu." << std::endl;
            return;
        }

        catch (const std::out_of_range&) {
            std::cout << std::endl << "Input out of range! Returning to menu." << std::endl;
            return;
        }

        p.*stat.field = newValue;
        std::cout << std::endl << "Stat updated!" << std::endl;
    }

    else {
        std::cout << std::endl << "Invalid choice! Returning to menu." << std::endl;
    }
}

int findPlayer(const std::vector<Player>& players, const std::string& playerName) {
    for (size_t i = 0; i < players.size(); i++) {
        if (toLowerCase(players[i].name) == toLowerCase(playerName)) {
            return i;
        }
    }
    return -1;
}

void savePlayersToFile(const std::vector<Player>& players, const std::string& filename) {
std::ofstream file(filename);

    if (!file) {
        throw std::runtime_error("Unable to open file!");
    }

    for (const auto& p : players) {
       file << p.name << '\n';
       file << p.position << '\n';
       for (const auto& entry : getStats(p)) {
           file << entry.label << ": " << p.*entry.field << '\n';
       }

    file << "----" << '\n'; 
    }
    file.close();
}

void loadPlayersFromFile(std::vector<Player>& players, const std::string& filename) {
    std::ifstream file(filename);
    std::string line; 
    Player currentPlayer;

    if (!file) {
        return;
    }

    while (std::getline(file, line)) {
        
        if (line == "----") {
            players.push_back(currentPlayer);
            currentPlayer = Player();
        }
        
        else if (currentPlayer.name.empty()) {
            currentPlayer.name = line;
        }
        
        else if (currentPlayer.position.empty()) {
            currentPlayer.position = line;
        }

        else { 
            size_t pos = line.find(": ");
            std::string label = line.substr(0, pos);
            std::string valueStr = line.substr(pos + 2);
            int num = stoi(valueStr);
                for (const auto& entry : getStats(currentPlayer)) {
                    if (entry.label == label) {
                        currentPlayer.*entry.field = num;
                        break;
                }
            }
        }
    }
    file.close();
 }

int main() {
  
    std::vector<std::string> validPositions = {"QB", "RB", "WR", "TE", "OT", "OG", "C", "DE", "DT", "OLB", "ILB", "CB", "FS", "SS"};
    std::vector<Player> players;
    std::string version = "0.0.1";
    std::string playerName; 
    std::string userInput;
    std::string positionName;
    
    std::cout << "NFL Stat Indicator v" << version << std::endl << std::endl;
    loadPlayersFromFile(players, "players.txt");
    
    while(true) {
        
        
        displayMenu();
            
        std::cout << "Enter your choice: " << std::endl << std::endl;
        std::cin >> userInput;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore leftover newline from previous cin >> so getline doesn't skip input
       
        if (userInput == "1") {  
            std::cout << std::endl << "Enter Name of Player: " << std::endl;
            std::getline(std::cin, playerName);
            std::cout << "Enter Position (QB, RB, WR, TE, OT, OG, C, DE, DT, OLB, ILB, CB, FS, SS): " << std::endl;
            std::getline(std::cin, positionName);

            
            int index = findPlayer(players, playerName);    

            if (playerName.empty()) {
                std::cout << std::endl << "Player name cannot be empty!" << std::endl;
            }
            
            else if (index != -1) {
                std::cout << std::endl << "Player already exists!" << std::endl;
            }  
            
            else if (positionName.empty()) {
                std::cout << std::endl << "Position cannot be empty!" << std::endl;
            }

            else if (std::find(validPositions.begin(), validPositions.end(), toUpperCase(positionName)) == validPositions.end()) {
                std::cout << std::endl << "Invalid position! Please enter a valid position." << std::endl;
            }

            else {
                Player newPlayer;
                newPlayer.name = toTitleCase(playerName);
                newPlayer.position = toUpperCase(positionName);
                players.push_back(newPlayer);
                std::cout << std::endl << "New Player added!" << std::endl;
            }
        }                 
        
        else if (userInput == "2") {
            std::cout << std::endl << "Enter Name of Player to Remove: ";
            std::getline(std::cin, playerName);
            
            int index = findPlayer(players, playerName);
            if (index != -1) {
                players.erase(players.begin() + index);
                std::cout << std::endl << "Player removed!" << std::endl;
            }

            else {
                std::cout << std::endl << "Player not found!" << std::endl;
            }
        }
               
        else if (userInput == "3") {
            
            if(players.empty()) {
                std::cout << std::endl << "No players added yet!" << std::endl;
                continue;
            }

            std::cout << std::endl << "Current Players: " << std::endl;

            std::vector<std::vector<StatEntry>> allStats;
            
            for (auto& p : players) {
            auto stats = getStats(p);
            allStats.push_back(stats);
            std::cout << '\n' << p.name << std::endl;
            printStats(p, stats);
            }
            
            std::cout << std::endl << "Please enter player # to edit (0 to cancel): " << std::endl;
            for (size_t i = 0; i < players.size(); i++) {
                std::cout << i + 1 << ". " << players[i].name << std::endl;
            }

            userInput.clear();
            std::getline(std::cin, userInput);
            int choice = 0;

            try {
                choice = stoi(userInput);
            }
            
            catch (const std::invalid_argument&) {
                std::cout << std::endl << "Invalid input! Returning to menu." << std::endl;
                continue;
            }

            catch (const std::out_of_range&) {
                std::cout << std::endl << "Input out of range! Returning to menu." << std::endl;
                continue;
            }

    
            if (choice == 0) continue;

            else if (choice >= 1 && choice <= (int)players.size()) {
                editStats(players[choice - 1], allStats[choice - 1]);
            }
            else {
                std::cout << std::endl << "Invalid choice! Returning to menu." << std::endl;
            }   
        }

        else if (userInput == "4") {
            break;
        }
        else {
            std::cout << std::endl << "Invalid choice! Please try again." << std::endl;
        }
    } 
    savePlayersToFile(players, "players.txt");
    return 0;    
}