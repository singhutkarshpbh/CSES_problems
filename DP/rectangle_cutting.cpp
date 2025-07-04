#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main() {
 
	const int N = 501;
	int dp[501][501];
	
	const int INF = 1e9;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            dp[i][j] = INF;
 
	int a,b;
	cin>>a>>b;  
	
	for(int w = 1; w<=a;w++){
	    for(int h = 1;h<=b;h++){
	        if(w == h){
	            dp[w][h] = 0;
	        }
	        else{
	            for(int k = 1;k<w;k++){
	                dp[w][h] = min(dp[w][h] , 1+dp[w-k][h] + dp[k][h]);
	            }
	            for(int k = 1;k<h;k++){
	                dp[w][h] = min(dp[w][h]  , 1+dp[w][h-k]+dp[w][k]);
	            }
	        }
	    }
	}
	cout<<dp[a][b]<<endl;
}