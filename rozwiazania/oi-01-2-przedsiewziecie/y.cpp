#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr long long INF = 1e18;

class Solution {

    int noVertices;
    vector<int> time;
    vector<int> color;
    vector<int> topologicalOrder;
    vector<long long> timeToGetHere;
    vector<long long> timeToFinish;
    vector<vector<int>> adj;

    long long overallTimeToFinish;

public:

    bool findCycleDfs(int v) {
        color[v] = 1;
        for (auto u : adj[v]) {
            if (color[u] == 1) {
                return true;
            }
            if (color[u] == 0) {
                if (findCycleDfs(u)) {
                    return true;
                }
            }
        }
        color[v] = 2;
        return false;
    }

    bool findCycle() {
        for (int v = 1; v <= noVertices; ++v) {
            if (!color[v]) {
                if (findCycleDfs(v)) {
                    return true;
                }
            }
        }
        return false;
    }

    void topologicalSortDfs(int v) {
        color[v] = 1;
        for (auto u : adj[v]) {
            if (!color[u]) {
                topologicalSortDfs(u);
            }
        }
        topologicalOrder.push_back(v);
    }

    void topologicalSort() {
        color.assign(noVertices + 1, 0);
        topologicalOrder.reserve(noVertices);
        for (int v = 1; v <= noVertices; ++v) {
            if (!color[v]) {
                topologicalSortDfs(v);
            }
        }
        reverse(topologicalOrder.begin(), topologicalOrder.end());
    }

    void calculateTimeToGetHere() {
        timeToGetHere.assign(noVertices + 1, 0);
        for (auto v : topologicalOrder) {
            for (auto u : adj[v]) {
                timeToGetHere[u] = max(timeToGetHere[u], timeToGetHere[v] + time[v]);
            }
        }
    }

    void calculatetimeToFinish() {
        timeToFinish.assign(noVertices + 1, 0);
        for (int i = topologicalOrder.size() - 1; i >= 0; --i) {
            int v = topologicalOrder[i];
            for (auto u : adj[v]) {
                timeToFinish[v] = max(timeToFinish[v], timeToFinish[u] + time[u]);
            }
        }
    }

    void readInput(istream& is) {
        int noEdges;
        is >> noVertices >> noEdges;

        adj.resize(noVertices + 1);
        time.resize(noVertices + 1);
        color.assign(noVertices + 1, 0);

        for (int i = 1; i <= noVertices; ++i) {
            is >> time[i];
        }

        for (int i = 0; i < noEdges; ++i) {
            int vertexA, vertexB;
            char direction;
            is >> vertexA >> direction >> vertexB;
            adj[vertexB].push_back(vertexA);
        }
    }

    void processQueries(istream& is, ostream& os, bool isCyclic) {
        int noQueries;
        is >> noQueries;
        while (noQueries--) {
            int vertex, timeIncrease;
            is >> vertex >> timeIncrease;
            if (!isCyclic) {
                long long timeToSpare = overallTimeToFinish - timeToGetHere[vertex] - time[vertex] - timeToFinish[vertex] - timeIncrease;
                if (timeToSpare >= 0) {
                    os << "TAK\n";
                }
                else {
                    os << "NIE " << -timeToSpare << '\n';
                }
            }
        }
    }

    long long calculateOverallTime() {
        long long result = 0;
        for (int v = 1; v <= noVertices; ++v) {
            result = max(result, timeToGetHere[v] + time[v]);
        }
        return overallTimeToFinish = result;
    }

    void solve(istream& is, ostream& os) {
        readInput(is);

        bool isCyclic = findCycle();
        if (isCyclic) {
            os << "CYKL\n";
        }
        else {
            topologicalSort();
            calculateTimeToGetHere();
            calculatetimeToFinish();
            os << "OK " << calculateOverallTime() << '\n';
        }
        processQueries(is, os, isCyclic);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int noTestCases;
    cin >> noTestCases;

    while (noTestCases--) {
        Solution test;
        test.solve(cin, cout);
    }
}