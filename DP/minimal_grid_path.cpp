#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i)
        cin >> grid[i];
 
    // At each step we only need current frontier positions
    vector<pair<int, int>> frontier;
    frontier.emplace_back(0, 0);
 
    string result;
    result += grid[0][0];
 
    // Visited array to avoid duplicates
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[0][0] = true;
 
    for (int step = 1; step < 2 * n - 1; ++step) {
        // Buckets for next positions by letter
        vector<vector<pair<int, int>>> buckets(26);
 
        for (auto [i, j] : frontier) {
            if (i + 1 < n && !visited[i+1][j]) {
                char c = grid[i+1][j];
                buckets[c - 'A'].emplace_back(i+1, j);
                visited[i+1][j] = true;
            }
            if (j + 1 < n && !visited[i][j+1]) {
                char c = grid[i][j+1];
                buckets[c - 'A'].emplace_back(i, j+1);
                visited[i][j+1] = true;
            }
        }
 
        // Find the minimal letter bucket
        for (int k = 0; k < 26; ++k) {
            if (!buckets[k].empty()) {
                result += (char)('A' + k);
                frontier = move(buckets[k]);
                break;
            }
        }
    }
 
    cout << result << '\n';
    return 0;
}