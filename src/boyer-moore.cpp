// boyer-moore.cpp
// Boyer-Moore's pattern matching algorithm

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> buildLastTable(const string& pattern) {
    vector<int> last(256, -1);

    for (int i = 0; i < pattern.size(); i++) {
        last[(unsigned char)pattern[i]] = i;
    }

    return last;
}

vector<int> boyerMooreSearch(const string& text, const string& pattern) {
    vector<int> result;

    int n = text.size();
    int m = pattern.size();

    if (m == 0 || n < m) return result;

    vector<int> last = buildLastTable(pattern);

    int i = m - 1; // text index
    int j = m - 1; // pattern index

    while (i < n) {
        if (text[i] == pattern[j]) {
            if (j == 0) {
                result.push_back(i);

                i = i + m;
                j = m - 1;
            } else {
                i--;
                j--;
            }
        } else {
            int lastPos = last[(unsigned char)text[i]];

            int shift = m - min(j, 1 + lastPos);

            i = i + shift;
            j = m - 1;
        }
    }

    return result;
}

int main() {
    string text = "a pattern matching algorithm";
    string pattern = "rithm";

    vector<int> matches = boyerMooreSearch(text, pattern);

    cout << "Matched indices: ";
    for (int idx : matches) {
        cout << idx << " ";
    }
    cout << '\n';

    return 0;
}