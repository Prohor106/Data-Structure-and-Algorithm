#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()

const ll M = 1000;
ll par[M], sz[M];
ll n, e, u, v, wt;

void make_set(ll v) {
    par[v] = v;
}

ll find_set(ll v) {
    if(par[v] == v) return v;
    return par[v] = find_set(par[v]);
}

void union_set(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
        if(sz[a] > sz[b]) swap(a, b);
        par[a] = b;
        sz[b] += sz[a];
    }
}

void reset() {
    for(ll i=0; i<=n; i++) make_set(i);
    for(ll i=0; i<=n; i++) sz[i] = 0;
}

pair<ll, vector<pair<ll, ll>>> find_mst(vector<pair<ll, pair<ll, ll>>> &vp) {
    ll tot = 0;
    vector<pair<ll, ll>> mst;

    for(auto u:vp) {
        ll a = u.second.first;
        ll b = u.second.second;
        if(find_set(a) != find_set(b)) {
            tot += u.first;
            union_set(a, b);
            mst.push_back({a, b});
        }
    }

    return {tot, mst};
}

void solve(ll cs) {
    cin >> n >> e;
    vector<pair<ll, pair<ll, ll>>> vp;
    for(ll i=0; i<e; i++) {
        cin >> u >> v >> wt;
        vp.push_back({wt, {u, v}});
    }
    sort(all(vp));

    reset();

    pair<ll, vector<pair<ll, ll>>> ans = find_mst(vp);

    cout << "Minimum Spanning Cost : " << ans.first << endl;
    cout << "Minimum Spanning Tree : " << endl;
    for(auto u:ans.second)
        cout << u.first << " " << u.second << endl;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    ll t=1, cs=1;
    // cin>>t;
    while(t--) {
        solve(cs++);
    }
    return 0;
}
