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
    ll n,x;
    cin>>n>>x;
    vector<ll>coins(n);
    rep(i,0,n){
        cin>>coins[i];
    }
    vector<ll> dp(x+1,1e9+7);
    dp[0] = 0;
    for(int i=1;i<=x;i++){
        for(int j = 0 ; j < n;j++){
            if(i - coins[j] >= 0 ){
            dp[i] = min(dp[i] , dp[i-coins[j]]+1);
            }
        }
    }
    if(dp[x] == 1e9+7){
        cout<<-1<<endl;
    }
    else{
        cout<<dp[x]<<endl;
    }
 
return 0;
}