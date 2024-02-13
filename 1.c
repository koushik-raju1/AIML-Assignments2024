#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " "; // Print the value of the current vertex

        for (int neighbor : graph[curr]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    // Initialize the graph (adjacency list)
    // ...
    // Call bfs(graph, starting_vertex);
    return 0;
}
