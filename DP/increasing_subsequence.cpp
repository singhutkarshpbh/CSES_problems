#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<long long, long long> pl;
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(), x.end()
#define sortall(a) sort(a.begin(), a.end())
#define rsort(a) sort(a.rbegin(), a.rend())
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define sq(a) (a) * (a)
#define int long long
#define float long double
#define inf __INT64_MAX__
#define setbits(k) __builtin_popcount(k)
#define msb(n) __builtin_clz(n)
const int MOD = 1e9+7;
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>arr(n);
    
    rep(i,0,n) cin>>arr[i];
    vector<int>sub_seq;
    rep(i,0,n){
        int ele = arr[i];
        int it = lower_bound(sub_seq.begin(),sub_seq.end(),ele) - sub_seq.begin();
        if(it == sub_seq.size()) sub_seq.pb(ele);
        else sub_seq[it] = ele;
    }
    cout<<sub_seq.size()<<endl;
    return 0;
}