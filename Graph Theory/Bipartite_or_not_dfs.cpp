#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()

const int M = 100;
vector<int> g[M];
int vis[M], clr[M], f = 1;

void clear(){
    for(int i=0; i<M; i++) g[i].clear();
    memset(vis, 0, sizeof(vis));
    memset(clr, 0, sizeof(clr));
    f = 1;
}

void dfs(int src, int c) {
    if(vis[src]) {
        if(clr[src]!=c) f = 0;
        return;
    }
    vis[src] = 1;
    clr[src] = c;
    for(auto child : g[src])
        dfs(child, clr[src]^1);
}

void solve(ll cs) {
    int n, e, u, v;
    cin >> n >> e;
    for(int i=0; i<e; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, 1);

    if(!f) cout << "No" << endl;
    else {
        for(int i=1; i<=n; i++)
            cout << i << " " << clr[i] << endl;
        cout << endl;
    }

    clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    ll t=1, cs=1;
    cin>>t;
    while(t--) {
        solve(cs++);
    }
    return 0;
}
