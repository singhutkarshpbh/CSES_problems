#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<long long, long long> pl;
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(), x.end()
#define sortall(a) sort(a.begin(), a.end())
#define rsort(a) sort(a.rbegin(), a.rend())
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define sq(a) (a) * (a)
#define int long long
#define float long double
#define inf __INT64_MAX__
#define setbits(k) __builtin_popcount(k)
#define msb(n) __builtin_clz(n)
const int MOD = 1e9+7;
void solve(){
    int n;
  cin >> n;
  map<int,int> compress;
  vector<int> a(n),b(n),p(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> p[i];
    b[i]++;
    compress[a[i]], compress[b[i]];
  }
 
  int coords = 0;
  for (auto&v : compress) {
    v.second = coords++;
  }
 
  vector<vector<pair<int,int>>> project(coords);
  for (int i = 0; i < n; i++) {
    project[ compress[b[i]] ].emplace_back( compress[a[i]], p[i] );
  }
 
  vector<long long> dp(coords, 0);
  for (int i = 0; i < coords; i++) {
    if (i > 0) {
      dp[i] = dp[i-1];
    }
    for (auto p : project[i]) {
      dp[i] = max(dp[i], dp[p.first]+p.second);
    }
  }
  cout << dp[coords-1] << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
    while (t--)
    {
        solve();
 
    }
    return 0;
}