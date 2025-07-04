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
    cin>>n;
    char arr[n][n];
    rep(i,0,n){
        rep(j,0,n){
            cin>>arr[i][j];
        }
    }
    vector<vector<int>>dp(n,vector<int>(n,0));
    if(arr[0][0] == '.') dp[0][0] = 1;
    rep(i,0,n){
        rep(j,0,n){
            if(arr[i][j] == '.'){
                int up =  0 , left  = 0;
                if(i > 0){
                    up = dp[i-1][j];
                }
                if(j > 0){
                    left = dp[i][j-1];
                }
                dp[i][j] =(dp[i][j] +  up + left)%MOD;
            }
        }
    }
    cout<<dp[n-1][n-1]<<endl;
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