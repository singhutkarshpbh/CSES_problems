#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 5;
vector<int> adj[N];
int parent[N], visited[N];
int start = -1, end_node = -1;
 
bool dfs(int u, int p) {
    visited[u] = 1;
    parent[u] = p;
 
    for (int v : adj[u]) {
        if (v == p) continue;
        if (visited[v]) {
            start = v;
            end_node = u;
            return true;
        }
        if (!visited[v]) {
            if (dfs(v, u))
                return true;
        }
    }
    return false;
}
 
int main() {
    int n, m;
    cin >> n >> m;
 
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    for (int i = 1; i <= n; ++i) {
        if (!visited[i] && dfs(i, -1))
            break;
    }
 
    if (start == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.push_back(start);
        for (int v = end_node; v != start; v = parent[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(start);
        reverse(cycle.begin(), cycle.end());
        cout << cycle.size() << "\n";
        for (int v : cycle) cout << v << " ";
        cout << "\n";
    }
 
    return 0;
}
