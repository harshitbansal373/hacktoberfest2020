/*
Kruskal's algorithm for finding the Minimum Spanning Tree of a weighted 
undirected graph .
Implemented in C++14 using UnionFind(improves time complexity considerably).
Author: github.com/yadavnaman
*/
vector<int> parent, size;

void initialise(int vertex) {
    parent[vertex] = vertex;
    size[vertex] = 1;
}
//find representative of the set in which vertex is present
int find(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
//union set of vertex v1 and vertex v2 using size
void uni(int v1, int v2) {
    v1 = find_set(v1);
    v2 = find_set(v2);
    if (v1 != v2) {
        if (size[v1] < size[v2])
            swap(v1, v2);
        parent[v2] = v1;
        size[v1] += size[v2];
    }
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& otherEdge) {
        return weight < otherEdge.weight;
    }
};

int n;
vector<Edge> edges;

int totalCost = 0;
vector<Edge> result;
parent.resize(n);
size.resize(n);
sort(edges.begin(), edges.end());


for (int i = 0; i < n; i++)
    initialise(i);

for (Edge edge : edges) {
    if (find(edge.u) != find(edge.v)) {
        totalCost += edge.weight;
        result.push_back(edge);
        uni(edge.u, edge.v);
    }
}