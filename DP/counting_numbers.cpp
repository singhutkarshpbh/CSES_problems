#include <bits/stdc++.h>
using namespace std;
#define int long long
 
 
string num;
int dp[20][11][2][2]; // pos, prevDigit, tight, leadingZero
 
int solve(int pos, int prevDigit, bool tight, bool leadingZero) {
    if (pos == num.size()) return 1;
 
    if (dp[pos][prevDigit][tight][leadingZero] != -1)
        return dp[pos][prevDigit][tight][leadingZero];
 
    int res = 0;
    int limit = tight ? (num[pos] - '0') : 9;
 
    for (int digit = 0; digit <= limit; ++digit) {
        if (!leadingZero && digit == prevDigit) continue;
 
        bool newTight = tight && (digit == limit);
        bool newLeadingZero = leadingZero && (digit == 0);
 
        res += solve(pos + 1, newLeadingZero ? 10 : digit, newTight, newLeadingZero);
    }
 
    return dp[pos][prevDigit][tight][leadingZero] = res;
}
 
long long countValid(long long x) {
    if (x < 0) return 0; // Important fix!
    num = to_string(x);
    memset(dp, -1, sizeof(dp));
    return solve(0, 10, true, true);
}
 
int32_t main() {
    long long a, b;
    cin >> a >> b;
    long long res;
    if (a == 0) {
        res = countValid(b);
    } else {
        res = countValid(b) - countValid(a - 1);
    }
    cout << res << "\n";
    return 0;
}