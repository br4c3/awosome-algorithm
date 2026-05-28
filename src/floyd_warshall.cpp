// floyd_warshall.cpp
// Floyd-Warshall algorithm finds all-pairs shorest paths.
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

constexpr int INF = 1e9;

int main() {
    constexpr size_t N = 4;

    std::vector<std::vector<int>> dist(N, std::vector<int>(N, INF));

    // Initialize pivot to 0
    for (size_t i = 0; i < N; ++i) {
        dist[i][i] = 0;
    }

    // A=0, B=1, C=2, D=3
    dist[0][1] = 5;   // A -> B
    dist[0][3] = 10;  // A -> D
    dist[1][2] = 3;   // B -> C
    dist[2][3] = 1;   // C -> D
    dist[3][0] = 2;   // D -> A

    // Floyd-Warshall
    // min(dp[i][j], dp[i][k] + dist[k][j])
    for (size_t k = 0; k < N; ++k) {
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < N; ++j) {
                if (dist[i][k] == INF || dist[k][j]) {
                    continue;
                }
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    char name[] = {'A', 'B', 'C', 'D'};

    std::cout << "    ";
    for (char i : name) {
        std::cout << std::setw(4) << i;
    }
    std::cout << "\n";

    for (int i = 0; i < N; i++) {
        std::cout << name[i] << " : ";
        for (int j = 0; j < N; j++) {
            if (dist[i][j] == INF) {
                std::cout << std::setw(4) << "INF";
            } else {
                std::cout << std::setw(4) << dist[i][j];
            }
        }
        std::cout << "\n";
    }

    return 0;
}