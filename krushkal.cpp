#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int source, destination, weight;
};

// Function to compare edges based on their weights
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Function to find the parent of a vertex in a disjoint set
int findParent(int vertex, vector<int>& parent) {
    if (parent[vertex] == -1)
        return vertex;
    return findParent(parent[vertex], parent);
}

// Function to perform Kruskal's algorithm and output the least expensive tree of roads
void kruskalMST(vector<Edge>& edges, int n) {
    // Sort the edges in non-decreasing order of their weights
    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(n, -1);  // To track the parent of each vertex
    vector<Edge> result;        // To store the edges of the minimum spanning tree

    for (const Edge& edge : edges) {
        int sourceParent = findParent(edge.source, parent);
        int destParent = findParent(edge.destination, parent);

        // If adding this edge doesn't form a cycle, include it in the result
        if (sourceParent != destParent) {
            result.push_back(edge);
            parent[sourceParent] = destParent;
        }
    }

    // Output the least expensive tree of roads
    cout << "Least Expensive Tree of Roads:\n";
    for (const Edge& edge : result)
        cout << "Road from Town " << edge.source << " to Town " << edge.destination << " with cost " << edge.weight << "\n";
}

int main() {
    int n;
    cout << "Enter the number of towns: ";
    cin >> n;

    int m;
    cout << "Enter the number of roads: ";
    cin >> m;

    vector<Edge> edges(m);

    cout << "Enter the source, destination, and cost of each road:\n";
    for (int i = 0; i < m; ++i)
        cin >> edges[i].source >> edges[i].destination >> edges[i].weight;

    kruskalMST(edges, n);

    return 0;
}
