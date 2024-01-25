#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    if (vertices <= 0 || edges < 0) {
        cout << "Invalid input for vertices or edges. Exiting.\n";
        return;
    }

    vector<int> adj[vertices];
    int visited[vertices] = {0};

    cout << "Enter edges (pair of vertices):\n";
    int a, b;
    for (int i = 0; i < edges; i++) {
        cin >> a >> b;

        if (a < 0 || a >= vertices || b < 0 || b >= vertices) {
            cout << "Invalid edge. Exiting.\n";
            return;
        }

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << "Enter start vertex: ";
    int startVertex;
    cin >> startVertex;

    if (startVertex < 0 || startVertex >= vertices) {
        cout << "Invalid start vertex. Exiting.\n";
        return;
    }

    queue<int> q;
    q.push(startVertex);
    visited[startVertex] = 1;

    cout << "BFS traversal starting from vertex " << startVertex << ":\n";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int value : adj[node]) {
            if (visited[value] == 0) {
                visited[value] = 1;
                q.push(value);
            }
        }
    }

    cout << endl;
}

int main() {
    bfs();
    return 0;
}
