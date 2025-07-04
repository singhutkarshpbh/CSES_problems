#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9+7;
#define int long long
int32_t main() {
	// your code goes here
	
	int n;
	cin>>n;
	int s = ((n)*(n+1))/2;
	if(s%2!=0) cout<<0<<endl;
	else{
	    int target = s/2;
	    vector<int>dp(target+1,0);
	    dp[0] =1;
	    for(int i =1;i<=n;i++){
	        for(s = target;s >= i; s--) {
	            dp[s] = (dp[s] + dp[s-i])%MOD;
	        }
	    }
	    int ans = dp[target];
	    ans = (ans*500000004)%MOD;
	    cout<<ans<<endl;
	}
}