#include <bits/stdc++.h>
using namespace std;
 
 
int dp[5001][5001];
int solve(string& n,string& m,int i ,int j){
    if(i < 0){
        return j+1;
    }
    if(j < 0) {
        return i+1;
    }
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int t1 = 1 + solve(n,m,i-1,j);
    int t2 = 1 + solve(n,m,i,j-1);
    int t3 = 0 ;
    if(n[i] != m[j]){
        t3 = 1 + solve(n,m,i-1,j-1);
    }
    else{
        t3 =solve(n,m,i-1,j-1);
    }
    
    return dp[i][j] = min({t1,t2,t3});
}
int main() {
	// your code goes here
	string n,m;
	cin>>n>>m;
	memset(dp,-1,sizeof(dp));
	int a = n.size() , b = m.size();
	cout<<solve(n,m,a-1,b-1);
}