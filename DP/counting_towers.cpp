#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<long long> f(N), g(N);
    f[1] = 1;
    g[1] = 1;
    for (int i = 2; i < N; ++i) {
        f[i] = (4 * f[i - 1] + g[i - 1]) % MOD;
        g[i] = (f[i - 1] + 2 * g[i - 1]) % MOD;
    }
 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (f[n] + g[n]) % MOD << '\n';
    }
}