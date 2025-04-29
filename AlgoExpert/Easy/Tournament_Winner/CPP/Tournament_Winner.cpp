/*
Problem Name: Tournament Winner
Difficulty: Easy
Platform: AlgoExpert

Problem Description:
There is an algorithms tournament taking place where teams compete against each other.
Each competition has one home team and one away team, and the winner receives 3 points.
The team with the highest total points at the end wins the tournament.

Given a list of competitions and their results, return the name of the winning team.

Time Complexity: O(n)
Space Complexity: O(k), where k = number of teams
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Helper function to update scores
void updateScores(const string& winningTeam, unordered_map<string, int>& scores) {
    if (scores.find(winningTeam) == scores.end()) {
        scores[winningTeam] = 0;
    }
    scores[winningTeam] += 3;
}

// Main function
string tournamentWinner(vector<vector<string>> competitions, vector<int> results) {
    string currentBestTeam = "";
    unordered_map<string, int> scores;
    scores[currentBestTeam] = 0;

    for (int i = 0; i < competitions.size(); ++i) {
        string homeTeam = competitions[i][0];
        string awayTeam = competitions[i][1];
        string winningTeam = results[i] == 1 ? homeTeam : awayTeam;

        updateScores(winningTeam, scores);

        if (scores[winningTeam] > scores[currentBestTeam]) {
            currentBestTeam = winningTeam;
        }
    }

    return currentBestTeam;
}

