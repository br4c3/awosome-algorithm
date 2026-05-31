// KMP.cpp

#include <iostream>

std::vector<int> buildLPS(const std::string& pattern) {
    int m = pattern.size();
    std::vector<int> lps(m, 0);

    int len = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            lps[i] = ++len;
            ++i;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                ++i;
            }
        }
    }

    return lps;
}

std::vector<int> kmpSearch(const std::string& text, const std::string& pattern) {
    std::vector<int> result;

    if (pattern.empty()) return result;

    std::vector<int> lps = buildLPS(pattern);

    int n = text.size();
    int m = pattern.size();

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n) {
        if (text[i] == pattern[j]) {
            ++i;
            ++j;
        }

        if (j == m) {
            result.push_back(i-j);
            j = lps[j-1];
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j-1];
            } else {
                ++i;
            }
        }
    }

    return result;
}

int main() {
    std::string text = "ababcabcabababd";
    std::string pattern = "ababd";

    std::vector<int> matchs = kmpSearch(text, pattern);

    std::cout << "Matched indices: ";
    for (int idx : matchs) {
        std::cout << idx << " ";
    }
    std::cout << std::endl;

    return 0;
}