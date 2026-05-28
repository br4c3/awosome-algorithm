// prim.cpp
// The Prim's algorithm finds MST(Minimum Spanning Tree)

// input.txt
// 5 6
// 0 1 2
// 0 2 3
// 1 2 1
// 1 3 4
// 2 3 5
// 3 4 7

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

struct Edge {
    int to;
    int weight;
};

int prim(int n, std::vector<std::vector<Edge>>& graph, int start) {
    std::vector<bool> visited(n, false);

    // {weight, vertex}
    std::priority_queue<
        std::pair<int, int>,
        std::vector<std::pair<int, int>>,
        std::greater<>
    > pq;

    pq.emplace(0, start);

    int totalCost = 0;

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (visited[cur]) continue;

        visited[cur] = true;
        totalCost += cost;

        std::cout << cur << ' ' << cost << '\n';

        for (const Edge& edge : graph[cur]) {
            if (!visited[edge.to]) {
                pq.emplace(edge.weight, edge.to);
            }
        }
    }
    std::cout << std::flush;

    return totalCost;
}

int main() {
    int V, E;
    std::cin >> V >> E;

    std::vector<std::vector<Edge>> graph(V);

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    std::cout << prim(V, graph, 0) << std::endl;

    return 0;
}