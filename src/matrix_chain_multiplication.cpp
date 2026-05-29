// matrix_chain_multiplication.cpp
// Find the minimum number of scalar multiplications
#include <iostream>
#include <vector>
#include <string>

constexpr int INF = 1e9;

std::string build(int i, int j, const std::vector<std::vector<int>>& braces) {
    if (i == j) {
        return "W" + std::to_string(i);
    }

    int k = braces[i][j];

    return "("
        + build(i, k, braces)
        + build(k + 1, j, braces)
        + ")";
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;

        std::vector<int> p(N+1);
        std::vector<std::vector<int>> dp(N+1, std::vector<int>(N+1, INF));
        std::vector<std::vector<int>> braces(N+1,std::vector<int>(N+1, 0));
        for (size_t i = 0; i <= N; ++i) {
            std::cin >> p[i];
            dp[i][i] = 0;
        }

        for (size_t l = 2; l <= N; ++l) {
            for (size_t i = 1; i + l-1 <= N; ++i) {
                size_t j = i + l - 1;

                dp[i][j] = INF;

                for (size_t k = i; k < j; ++k) {
                    int cost = dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j];
                    if (dp[i][j] > cost) {
                        dp[i][j] = cost;
                        braces[i][j] = k;
                    }
                }
            }
        }

        std::cout << dp[1][N] << '\n';
        std::cout << build(1, N, braces) << std::endl;
    }

    return 0;
}