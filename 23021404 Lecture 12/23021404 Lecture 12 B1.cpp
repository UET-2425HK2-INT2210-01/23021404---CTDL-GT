#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(int n, const vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(n + 1); // 1-based indexing
    vector<int> inDegree(n + 1, 0);

    // Build the graph and calculate in-degrees
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        graph[u].push_back(v);
        inDegree[v]++;
    }

    // Initialize queue with nodes having 0 in-degree
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        // Decrease in-degree of neighbors
        for (int v : graph[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return result;
}

int main() {
    ifstream infile("jobs.txt");
    ofstream outfile("jobs.out");

    int n, m;
    infile >> n >> m;

    vector<pair<int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v;
        infile >> u >> v;
        edges.emplace_back(u, v);
    }

    vector<int> sortedJobs = topologicalSort(n, edges);

    for (int i = 0; i < sortedJobs.size(); ++i) {
        if (i > 0) outfile << " ";
        outfile << sortedJobs[i];
    }

    infile.close();
    outfile.close();

    return 0;
}
