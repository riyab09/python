#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int src, dest, weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int find(vector<int>& parent, int i) {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}

// Custom insertion sort for Edge list
void sortEdges(vector<Edge>& edges) {
    for (size_t i = 1; i < edges.size(); ++i) {
        Edge key = edges[i];
        int j = i - 1;
        while (j >= 0 && edges[j].weight > key.weight) {
            edges[j + 1] = edges[j];
            j--;
        }
        edges[j + 1] = key;
    }
}

void kruskal(vector<vector<int>>& graph, int numVertices) {
    vector<Edge> edges;
    for (int i = 0; i < numVertices; i++) {
        for (int j = i + 1; j < numVertices; j++) {
            if (graph[i][j] != 0) {
                edges.push_back({i, j, graph[i][j]});
            }
        }
    }

    sortEdges(edges);  // Use custom sort instead of std::sort

vector<int> parent(numVertices);
    for (int i = 0; i < numVertices; i++) {
        parent[i] = i;
    }

    vector<Edge> mst;
    int sum = 0;

    for (const Edge& edge : edges) {
        int srcParent = find(parent, edge.src);
        int destParent = find(parent, edge.dest);
        if (srcParent != destParent) {
            mst.push_back(edge);
            parent[srcParent] = destParent;
            sum += edge.weight;
        }
    }

    cout << "Edges in the MST:\n";
    for (const Edge& edge : mst) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << "\n";
    }
    cout << "Minimum weight of MST: " << sum << "\n";
}

int main() {
    int n;
    cout << "Enter the size of the graph: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Enter the weight " << i << "->" << j << " of the graph: ";
            cin >> graph[i][j];
        }
    }

    kruskal(graph, n);

    return 0;
}
