#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

using AdjList = unordered_map<int, vector<int>>;

// Function to read the graph from a file into adjList and vertex list
void construct(AdjList& adjList, vector<int>& vertices, const string& filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int key;
        ss >> key;
        vertices.push_back(key);
        int neighbor;
        vector<int> neighbors;
        while (ss >> neighbor) {
            if (neighbor != key) neighbors.push_back(neighbor);
        }
        adjList[key] = neighbors;
    }
    file.close();
}

// Count total edges in the current graph
int getNoOfEdges(const AdjList& adjList, const vector<int>& vertices) {
    int count = 0;
    for (int v : vertices) {
        count += adjList.at(v).size();
    }
    return count;
}

// Build edge list from adjacency list
vector<pair<int, int>> buildEdges(const AdjList& adjList, const vector<int>& vertices) {
    vector<pair<int, int>> edges;
    for (int v : vertices) {
        for (int neighbor : adjList.at(v)) {
            edges.emplace_back(v, neighbor);
        }
    }
    return edges;
}

// Perform Karger's min cut algorithm once
int minCut(AdjList adjList, vector<int> vertices) {
    int label = adjList.size() + 1;
    random_device rd;
    mt19937 gen(rd());

    while (vertices.size() > 2) {
        vector<pair<int, int>> edges = buildEdges(adjList, vertices);
        uniform_int_distribution<> dis(0, edges.size() - 1);
        auto [v1, v2] = edges[dis(gen)];

        vector<int>& v1List = adjList[v1];
        vector<int>& v2List = adjList[v2];

        v1List.insert(v1List.end(), v2List.begin(), v2List.end());

        vertices.erase(remove(vertices.begin(), vertices.end(), v2), vertices.end());
        adjList.erase(v2);

        for (int v : vertices) {
            vector<int>& neighbors = adjList[v];
            for (int& n : neighbors) {
                if (n == v1 || n == v2) n = label;
            }
        }

        vector<int> updatedList = adjList[v1];
        adjList.erase(v1);
        adjList[label] = updatedList;

        auto it = find(vertices.begin(), vertices.end(), v1);
        if (it != vertices.end()) *it = label;

        vector<int>& labelList = adjList[label];
        labelList.erase(remove(labelList.begin(), labelList.end(), label), labelList.end());

        label++;
    }

    return adjList[vertices[0]].size();
}

int main() {
    string filename = "adjList.txt";

    AdjList adjList;
    vector<int> vertices;

    construct(adjList, vertices, filename);

    int n = adjList.size();
    int iterations = n;  // You may increase to n(n-1)/2 * log(n) for better probability

    int minCutFound = n * n;

    for (int i = 0; i < iterations; ++i) {
        AdjList tempAdj = adjList;
        vector<int> tempVertices = vertices;

        int result = minCut(tempAdj, tempVertices);
        cout << "Min found on call " << i << " is: " << result << endl;

        minCutFound = min(minCutFound, result);
    }

    cout << "\nMINIMAL CUT FOUND IS\n" << minCutFound << endl;

    return 0;
}
