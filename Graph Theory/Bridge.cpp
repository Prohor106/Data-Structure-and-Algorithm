#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
#define bug(a) cout << #a << " : " << a << endl;
#pragma GCC target("popcnt")

const int M = 1005;
vector<int> g[M];
int vis[M], tin[M], low[M], timer=0;
vector<pair<int, int>> vp;

void dfs(int node, int par) {
    vis[node] = 1;
    tin[node] = low[node] = ++timer;
    for(auto u:g[node]) {
        if(u==par) continue;
        if(!vis[u]) {
            dfs(u, node);
            low[node] = min(low[node], low[u]);
            if(low[u] > tin[node]) vp.push_back({min(u, node), max(u, node)});
        } else {
            low[node] = min(low[node], low[u]);
        }
    }
}

void solve(int cs) {
    int n, m, x, y;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(int i=1; i<=n; i++)
        if(!vis[i]) dfs(i, -1);

    for(auto [x, y]:vp) cout << x << " " << y << endl;
    cout << endl;

    for(int i=1; i<=n; i++) {
        g[i].clear();
        vis[i] = tin[i] = low[i] = 0;
    }
    vp.clear();
    timer = 0;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t=1, cs=1;
    cin>>t;
    while(t--) {
        solve(cs++);
    }
    return 0;
}

