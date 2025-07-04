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
	const int MAX_SUM = 1000 * 100 + 1;
    vector<bool> dp(MAX_SUM, false);
    
    dp[0] = 1;
    for(auto it:arr) {
        for(int i = MAX_SUM;i >= it;i--){
            if(dp[i-it]){
                dp[i] = 1;
            }
        }
    }
    int cnt = 0;
    for(int i=1;i<=MAX_SUM;i++){
        if(dp[i]){
            cnt++;
        }
    }
    
    cout<<cnt<<endl;
    for(int i=1;i<=MAX_SUM;i++){
        if(dp[i]){
            cout<<i<<" ";
        }
    }
	cout<<endl;
	return 0;
}