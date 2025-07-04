#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	
	int n,m;
	cin>>n>>m;
	vector<int>a(n) , b(m);
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	
	for(int i=0;i<m;i++){
	    cin>>b[i];
	}
	
	int dp[1001][1001];
	memset(dp,0,sizeof(dp));
	
	for(int i=1;i<=n;i++){
	    for(int j = 1;j<=m;j++){
	        if(a[i-1] == b[j-1]){
	            dp[i][j] = dp[i-1][j-1]+1;
	        }
	        else{
	            dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
	        }
	    }
	}
	vector<int>lcs;
	int i=n,j=m;
	while(i > 0 && j > 0 ) {
	    if(a[i-1] == b[j-1]){
	        lcs.push_back(a[i-1]);
	        i--,j--;
	    }
	    else if(dp[i-1][j] > dp[i][j-1]){
	        i--;
	    }
	    else{
	        j--;
	    }
	}
	reverse(lcs.begin(),lcs.end());
	cout<<lcs.size()<<endl;
	for(auto it:lcs){
	    cout<<it<<" ";
	}
	cout<<endl;
}