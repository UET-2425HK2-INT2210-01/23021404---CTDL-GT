#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph; // danh sách kề
vector<bool> visited;      // đánh dấu các đỉnh đã thăm

void dfs(int node) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; // số đỉnh và số cạnh

    graph.resize(n + 1);   // đánh số từ 1 đến n
    visited.resize(n + 1, false);

    // đọc các cạnh
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // vì là đồ thị vô hướng
    }

    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);         // duyệt từ đỉnh i
            components++;   // mỗi lần gọi dfs là tìm ra 1 thành phần liên thông
        }
    }

    cout << components << endl;

    return 0;
}
