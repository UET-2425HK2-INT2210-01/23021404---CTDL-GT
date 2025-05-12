#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;

    vector<vector<int>> adj(n + 1); // Danh sách kề, đánh số từ 1

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> dist(n + 1, -1); // Khoảng cách từ X đến mỗi đỉnh, -1 nghĩa là chưa thăm
    queue<int> q;

    dist[X] = 0;
    q.push(X);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    cout << dist[Y] << endl;
    return 0;
}
