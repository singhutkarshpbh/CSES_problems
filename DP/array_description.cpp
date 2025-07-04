#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
#define int long long
int32_t main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	vector<int>a(n);
	for(int i=0;i<n;i++) {
	    cin>>a[i];
	}
	vector<vector<int>>dp(n,vector<int>(m+2,0));
	
	if(a[0] == 0) {
	    for(int x = 1;x <= m;x++){
	        dp[0][x] = 1;
	    }
	}
	else{
	    dp[0][a[0]] = 1;    
	}
	for(int i=1;i<n;i++){
	    for(int x = 1;x<=m;x++){
	       if(a[i] == 0 || a[i] ==x){
	           dp[i][x] = (dp[i-1][x-1] + dp[i-1][x] + dp[i-1][x+1])%MOD;
	       }
	    }
	}
	int res = 0;
	for(int x = 1; x<= m;x++){
	    res = (res + dp[n-1][x])%MOD;
	}
	cout<<res<<endl;
}