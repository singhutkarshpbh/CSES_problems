#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
const int MOD = 1e9+7;
int n,m;
void dfs_fill(int pos , int mask , int nextmask , vector<int>&ways) {
    if(pos == n){
        ways.push_back(nextmask);
        return;
    }
    
    if((mask >> pos)&1) {
        dfs_fill(pos+1,mask,nextmask,ways);
    }
    else{
        dfs_fill(pos+1,mask,nextmask |(1<<pos) , ways);
        
        if(pos+1<n && !((mask >> (pos+1))&1)){
            dfs_fill(pos+2,mask,nextmask ,ways);
        }
    }
}
int main() {
	// your code goes here
	cin>>n>>m;
	int maxmask = (1<<n);
	dp.assign(m+1,vector<int>(maxmask,0));
	dp[0][0] = 1;
	
	
	for(int col=0;col<m;col++) {
	    for(int mask = 0; mask < maxmask;mask++){
	        if(dp[col][mask] == 0) continue;
	        
	        vector<int>ways;
	        dfs_fill(0, mask , 0 ,ways) ;
	        for(auto it:ways){
	            dp[col+1][it] = (dp[col+1][it] + dp[col][mask])%MOD; 
	        }
	    }
	}
	cout<<dp[m][0]<<endl;
	return 0;
}