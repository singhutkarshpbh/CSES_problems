#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef vector<long long> vl;
typedef pair<long long,long long> pl;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define sortall(a) sort(a.begin(),a.end())
#define rsort(a) sort(a.rbegin(),a.rend())
#define rep(i,a,b) for (int i = a; i < b; i++)
#define rrep(i,a,b) for (int i = a; i >=b; i--)
#define sq(a) (a)*(a)
#define inf __INT64_MAX__
#define setbits(k) __builtin_popcount(k)
#define msb(n) __builtin_clz(n)
int main (){
    ll n;
    cin>>n;
    vector<ll> dp(n+1,INT_MAX);
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        ll temp = i;
        while(temp){
            ll x = temp%10;
            dp[i] = min(dp[i] , dp[i-x]+1);
            temp/=10;
        }
    }
    cout<<dp[n]<<endl;
 
return 0;
}
