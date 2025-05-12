#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <climits>
#include <algorithm>


using namespace std;

const int INF = 1e9;

int main() {
    ifstream fin("dirty.txt");
    ofstream fout("dirty.out");

    int n, m, s, e;
    fin >> n >> m >> s >> e;

    vector<tuple<int, int, int>> edges;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    vector<int> prev(n + 1, -1);
    vector<int> d(n + 1, INF);
    d[s] = 0;

    // Đọc các cạnh
    for (int i = 0; i < m; ++i) {
        int u, v, cost;
        fin >> u >> v >> cost;
        edges.emplace_back(u, v, cost);
        dist[u][v] = cost;
    }

    // Bellman-Ford từ s đến e
    for (int i = 1; i < n; ++i) {
        for (auto [u, v, cost] : edges) {
            if (d[u] != INF && d[u] + cost < d[v]) {
                d[v] = d[u] + cost;
                prev[v] = u;
            }
        }
    }

    // Ghi tổng độ bẩn đường đi ngắn nhất từ s đến e
    if (d[e] == INF) fout << "INF\n";
    else fout << d[e] << '\n';

    // Truy vết đường đi từ s đến e
    if (d[e] != INF) {
        vector<int> path;
        for (int v = e; v != -1; v = prev[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        for (int v : path)
            fout << v << ' ';
        fout << '\n';
    } else {
        fout << "NO PATH\n";
    }

    // Floyd-Warshall cho tất cả cặp đỉnh
    for (int i = 1; i <= n; ++i) dist[i][i] = 0;

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    // Ghi ma trận khoảng cách
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dist[i][j] == INF)
                fout << "INF ";
            else
                fout << dist[i][j] << ' ';
        }
        fout << '\n';
    }

    return 0;
}
