/*
Cycle detection and path printing in a undirected graph.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()

const ll N = 2e5+5;
vector<ll> g[N];
bool vis[N];
deque<ll> v;

bool iscycledfs(ll src, ll par) {
    vis[src] = true;
    v.push_back(src);
    for(auto child : g[src]){
        if(!vis[child]){
            if(iscycledfs(child, src))
                return true;
        }
        else{
            if(child != par) {
                v.push_back(child);
                return true;
            }
        }
    }
    v.pop_back();
    return false;
}

void solve(ll cs) {
    ll n, e;
    cin >> n >> e;
    for(ll i=0; i<e; i++) {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(ll i=1; i<=n; i++) {
        if(!vis[i]) {
            bool ck = iscycledfs(i, -1);
            if(ck) {
                vector<ll> ans;
                ll k = v.back(); v.pop_back();
                
                ans.push_back(k);
                while(v.back()!=k){
                    ans.push_back(v.back());
                    v.pop_back();
                }
                ans.push_back(k);

                cout << ans.size() << endl;
                for(auto u:ans) cout << u << " ";
                    cout << endl;
                
                return;
            }
        }
    }

    cout << "IMPOSSIBLE" <<endl;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    ll t=1, cs=1;
    //cin>>t;
    while(t--) {
        solve(cs++);
    }

    return 0;
}
