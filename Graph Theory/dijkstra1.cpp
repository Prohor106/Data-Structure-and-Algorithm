#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define INF (1<<30)

typedef pair<int, int> pii;

void dijkstra(int src, vector<vector<pii>> &g, vector<int> &dist) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;

    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty()) {
        int node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if(dist[node] < cost) continue;

        for(auto child : g[node]) {
            int child_node = child.first;
            int child_cost = child.second;
            if(child_cost + dist[node] < dist[child_node]) {
                dist[child_node] = child_cost + dist[node];
                pq.push({dist[child_node], child_node});
            }
        }
    }
}

void solve(ll cs) {
    int n, e;
    cin >> n >> e;

    vector<vector<pii>> g(n+1);
    vector<int> dist(n+1, INF);

    for(int i=1; i<=e; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});

    }

    dijkstra(1, g, dist);

    if(dist[n]==INF) cout << "Case " << cs << ": " << "Impossible" << endl;
    else cout << "Case " << cs << ": " << dist[n] << endl;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tc=1, cs=1;
    cin>>tc;
    while(tc--) {
        solve(cs++);
    }

    return 0;
}
