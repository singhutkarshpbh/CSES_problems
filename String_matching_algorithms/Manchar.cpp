#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestPalindrome(string s) {
    if (s.empty()) return "";

    // Step 1: Transform the string (add # between characters)
    string t = "#";
    for (char c : s) {
        t += c;
        t += '#';
    }

    int n = t.length();
    vector<int> P(n, 0); // P[i] = length of palindrome centered at i (in transformed string)
    int center = 0, right = 0;

    // Step 2: Main Manacher's loop
    for (int i = 1; i < n - 1; ++i) {
        int mirror = 2 * center - i; // Mirror of i with respect to center

        if (i < right)
            P[i] = min(right - i, P[mirror]);

        // Try to expand palindrome centered at i
        while ( t[i + (1 + P[i])] == t[i - (1 + P[i])])
            P[i]++;

        // If palindrome centered at i expands past r;
        if (i + P[i] > right) {
            center = i;
            right = i + P[i];
        }
    }

    // Step 3: Find the longest palindrome in original string
    int maxLen = 0, centerIndex = 0;
    for (int i = 0; i < n ; ++i) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    // Start index in original string
    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}

// Example usage
int main() {
    string s = "babad";
    cout << "Longest Palindromic Substring: " << longestPalindrome(s) << endl;
    return 0;
}
