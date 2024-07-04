#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(int start, vector<vector<int>>& graph, vector<bool>& visited) {
    int count = 0;
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[node][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return count + 1;
}

int DemTPLT(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    int components = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            components += BFS(i, graph, visited);
        }
    }

    return components;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    int components = DemTPLT(graph);
    cout << components;

    return 0;
}