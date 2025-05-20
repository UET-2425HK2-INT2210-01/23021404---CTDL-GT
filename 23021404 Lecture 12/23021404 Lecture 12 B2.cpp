#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, d;
};

class UnionFind {
    vector<int> parent, rank;
public:
    UnionFind(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    bool unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU == rootV) return false;

        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootU] = rootV;
            if (rank[rootU] == rank[rootV]) {
                rank[rootV]++;
            }
        }
        return true;
    }
};

vector<Edge> kruskalMST(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.d < b.d;
    });

    UnionFind uf(n);
    vector<Edge> mst;
    int totalCost = 0;

    for (const Edge& edge : edges) {
        if (uf.unite(edge.u, edge.v)) {
            mst.push_back(edge);
            totalCost += edge.d;
        }
    }

    return mst;
}

int main() {
    ifstream infile("connection.txt");
    ofstream outfile("connection.out");

    int n, m;
    infile >> n >> m;

    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        infile >> u >> v >> d;
        edges.push_back({u, v, d});
    }

    vector<Edge> mst = kruskalMST(n, edges);

    // Calculate total cost
    int totalCost = 0;
    for (const Edge& edge : mst) {
        totalCost += edge.d;
    }

    // Write output
    outfile << totalCost << endl;
    for (const Edge& edge : mst) {
        outfile << edge.u << " " << edge.v << " " << edge.d << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
