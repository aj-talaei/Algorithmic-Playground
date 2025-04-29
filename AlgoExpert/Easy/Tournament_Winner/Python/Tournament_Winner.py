"""
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
"""
def tournamentWinner(competitions, results):
    currentBestTeam = ""
    scores = {currentBestTeam: 0}
    for idx, competition in enumerate(competitions):
        homeTeam, awayTeam = competition
        winningTeam = homeTeam if results[idx] == 1 else awayTeam
        updateScores(winningTeam, scores)
        if scores[winningTeam] > scores[currentBestTeam]:
            currentBestTeam = winningTeam
    return currentBestTeam

def updateScores(winningTeam, scores):
    if winningTeam not in scores:
        scores[winningTeam] = 0
    scores[winningTeam] += 3