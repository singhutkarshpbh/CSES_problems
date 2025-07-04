#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
struct Fenwick {
    int n;
    vector<int> bit;
 
    Fenwick(int n) : n(n) {
        bit.assign(n + 2, 0);
    }
 
    void update(int i, int delta) {
        for (; i <= n; i += i & -i)
            bit[i] = (bit[i] + delta) % MOD;
    }
 
    int query(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i)
            res = (res + bit[i]) % MOD;
        return res;
    }
};
 
int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
 
    // Coordinate compression
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
 
    Fenwick fen(b.size());
 
    int total = 0;
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        int count_smaller = fen.query(idx - 1);
        int cnt = (count_smaller + 1) % MOD;
        fen.update(idx, cnt);
        total = (total + cnt) % MOD;
    }
 
    cout << total << "\n";
    return 0;
}