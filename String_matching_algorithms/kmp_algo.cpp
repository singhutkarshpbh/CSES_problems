#include <iostream>
#include <vector>
using namespace std;

// Function to build the Longest Prefix Suffix (LPS) array
vector<int> buildLPS(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);

    int len = 0; // length of the previous longest prefix suffix
    for (int i = 1; i < m; ) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
    }
    return lps;
}

// KMP search algorithm
vector<int> KMP(const string& text, const string& pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> lps = buildLPS(pattern);
    vector<int> result;

    int i = 0, j = 0; // i -> text index, j -> pattern index
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            result.push_back(i - j); // Match found at index i - j
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return result;
}

// Example usage
int main() {
    string text = "ababcababcabc";
    string pattern = "abc";

    vector<int> matches = KMP(text, pattern);

    for (int index : matches)
        cout << "Pattern found at index: " << index << endl;

    return 0;
}
