#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) (v).begin(), (v).end()

const int mx = 1e6+5;
int parrent[mx];
long long dist[mx];
vector<pair<int,ll>> g[mx];

void dijkstra(int src, int n) {
    for(int i=1; i<=n; i++) dist[i] = LONG_LONG_MAX;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>> > pq;

    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty()) {
        int cur_n = pq.top().second;
        ll cur_d = pq.top().first;
        pq.pop();

        if(dist[cur_n] < cur_d) continue;

        for(auto child : g[cur_n]) {
            if(cur_d + child.second < dist[child.first]) {
                parrent[child.first] = cur_n;
                dist[child.first] = cur_d + child.second;
                pq.push({dist[child.first], child.first});
            }
        }
    }
}

void solve(ll cs) {
    int n,e;
    cin >> n >> e;
    for(int i=0; i<e; i++) {
        int u, v;
        ll wt;
        cin >> u >> v >> wt;
        g[u].push_back({v,wt});
        g[v].push_back({u,wt});
    }

    dijkstra(1, n);

    if(dist[n]==LONG_LONG_MAX) {
        cout << -1 << endl;
        return;
    }

    vector<int> ans = {n};
    int x = n;
    while(parrent[x]!=0) {
        ans.push_back(parrent[x]);
        x = parrent[x];
    }
    reverse(all(ans));

    for(auto u:ans) cout << u << ' ';
    cout << endl;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    ll tc = 1, cs = 1;
    // cin >> tc;
    while(tc--) {
        solve(cs++);
    }

    return 0;
}

