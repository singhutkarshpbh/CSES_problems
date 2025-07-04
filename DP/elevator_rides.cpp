#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main() {
	// your code goes here
	int n,x;
	cin>>n>>x;
	vector<int>arr(n);
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	const int N= 1<<n;
	vector<pair<int,int>>dp(N  , {n+1,0});
	dp[0] = {1,0};
	
	for(int mask = 0; mask < N;mask++) {
	    auto [rides,cur_w] = dp[mask];
	    
	    for(int i=0;i<n;i++) {
	        if(!(mask&(1<<i))){
	            int newmask = mask | (1<<i);
	            if(cur_w + arr[i] <= x) {
	                auto option = make_pair(rides,cur_w+arr[i]);
	                dp[newmask] = min(dp[newmask] , option);
	            }
	            else{
	                auto option = make_pair(rides+1,arr[i]);
	                dp[newmask] = min(dp[newmask] , option);
	            }
	        }
	    }
	}
	cout<<dp[N-1].first<<endl;
}