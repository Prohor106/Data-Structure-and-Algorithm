#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()

const ll N = 1e5+10;

vector<ll> g[N];
bool present_vis[N];

bool iscycle(ll src, ll par) {
    present_vis[src] = true;
    for(auto child : g[src]){
        if(child != par){
            if(present_vis[child]) return true;
            if(!present_vis[child] && iscycle(child, src)) return true;
        }
    }

    return false;
}

void solve(ll cs) {
    ll n, e, u, v;
    cin >> n >> e;
    for(ll i=0; i<e; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool cycle = false;
    for(ll i=1; i<=n; i++) {
        if(!present_vis[i] && iscycle(i, -1)) {
            cycle = true;
        }
    }

    if(cycle) cout << "Cycle is present" << endl;
    else cout << "Cycle is not present" << endl;

    memset(g, 0, sizeof(g));
    memset(present_vis, 0, sizeof(present_vis));
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
