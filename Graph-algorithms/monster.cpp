#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
#define f first
#define s second
 
const int INF = 1e18;
 
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const char DIR[] = {'D', 'U', 'R', 'L'};
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    vector<string> grid(n);
    for (auto &row : grid) cin >> row;
 
    queue<pii> mq;
    vector<vector<int>> mon_time(n, vector<int>(m, INF));
    pii start;
 
    // Collect all monster positions and player position
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                mq.push({i, j});
                mon_time[i][j] = 0;
            }
            if (grid[i][j] == 'A') {
                start = {i, j};
            }
        }
    }
 
    // BFS to precompute monster arrival times
    while (!mq.empty()) {
        auto [x, y] = mq.front(); mq.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >=0 && ny >=0 && nx<n && ny<m && grid[nx][ny] != '#' && mon_time[nx][ny]==INF) {
                mon_time[nx][ny] = mon_time[x][y]+1;
                mq.push({nx, ny});
            }
        }
    }
 
    // BFS for player
    queue<tuple<int,int,int>> pq;
    vector<vector<int>> pl_time(n, vector<int>(m, INF));
    vector<vector<pii>> par(n, vector<pii>(m, {-1,-1}));
 
    int sx = start.f, sy = start.s;
    pl_time[sx][sy] = 0;
    pq.push({sx, sy, 0});
 
    pii exit_cell = {-1, -1};
 
    while (!pq.empty()) {
        auto [x, y, t] = pq.front(); pq.pop();
 
        // If on border, escape!
        if (x==0 || y==0 || x==n-1 || y==m-1) {
            exit_cell = {x, y};
            break;
        }
 
        for (int d=0; d<4; d++) {
            int nx = x+dx[d], ny = y+dy[d];
            if (nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny] != '#' && pl_time[nx][ny]==INF) {
                // Can player arrive before monster?
                if (mon_time[nx][ny] > t+1) {
                    pl_time[nx][ny]=t+1;
                    par[nx][ny]={x,y};
                    pq.push({nx,ny,t+1});
                }
            }
        }
    }
 
    if (exit_cell.f==-1) {
        cout<<"NO\n";
        return;
    }
 
    cout<<"YES\n";
 
    // Recover path
    string path;
    int cx=exit_cell.f, cy=exit_cell.s;
    while (make_pair(cx,cy)!=start) {
        auto [px,py]=par[cx][cy];
        for (int d=0; d<4; d++) {
            if (px+dx[d]==cx && py+dy[d]==cy) {
                path+=DIR[d];
                break;
            }
        }
        cx=px; cy=py;
    }
 
    reverse(path.begin(), path.end());
    cout<<path.size()<<'\n';
    cout<<path<<'\n';
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t=1;
    // cin>>t; // Uncomment if multiple test cases
    while(t--) solve();
}
