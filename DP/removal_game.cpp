#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
	// your code goes here
	
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	vector<int>prefix(n,0);
	prefix[0] = arr[0];
	for(int i=1;i<n;i++){
	    prefix[i] = prefix[i-1]+ arr[i];
	}
	auto getsum =  [&](int l,int r){
	    if(l == 0) {
	        return prefix[r];
	    }
	    return prefix[r] - prefix[l-1];
	};
	
	vector<vector<int>>dp(n,vector<int>(n,0));
	
	for(int len = 0;len < n;len++) {
	    for(int l= 0;l+len < n ; l++){
	        int r = l+len;
	        if(l == r) {
	            dp[l][r] = arr[l];
	        }
	        else{
	            int tot = getsum(l,r);
	            dp[l][r] = tot-min(dp[l+1][r] , dp[l][r-1]);
	            
	        }
	    }
	}
	cout<<dp[0][n-1]<<endl;
	return 0;
}