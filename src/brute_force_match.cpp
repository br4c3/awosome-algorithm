// brute_force_match.cpp

#include <iostream>
#include <vector>
#include <string>

int BruteForceMatch(std::string& text, std::string& pattern) {
    int n = text.size();
    int m = pattern.size();

    for (int i = 0; i <= n-m; ++i) {
        int j = 0;

        while (j < m && text[i + j] == pattern[j]) {
            ++j;
        }

        if (j == m) {
            return i;
        }
    }

    return -1; // No match
}

int main() {
    std::string T = "HELLOWORLD";
    std::string P = "WORLD";

    int result = BruteForceMatch(T, P);
    std::cout << result << std::endl;

    return 0;
}