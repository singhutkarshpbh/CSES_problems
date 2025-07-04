#include<bits/stdc++.h>
using namespace std ;
int m = 1e9+7;
typedef double D ;
typedef long long ll ;
typedef long double ld ;
typedef unsigned int ui ;
typedef unsigned long long ull ;
# define F first
# define S second
# define R return
# define C continue
# define pb push_back
# define pf push_front
# define mp make_pair
# define Fi(i,L,R) for (int i = L ; i <= R ; i++)
# define Fd(i,R,L) for (int i = R ; i >= L ; i--)
const ll MOD = 1e9 + 7 ;
const ld PI = 3.1415926535897932384626 ;
int main (){
   
        ll n;
        cin>>n;
 
        vector<ll> dp(n+1,0);
        dp[0] = 1;
 
        for(int i=1;i<=n;i++){
            for(int x = 1; x<=6;x++){
                if(x > i){
                    break;
                }
                dp[i] = (dp[i]+dp[i-x])%m;
            }
        }
 
        cout<<dp[n]<<endl;
    
 
return 0;
}
