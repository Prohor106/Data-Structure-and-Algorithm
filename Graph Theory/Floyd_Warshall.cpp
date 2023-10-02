#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()

const int N = 250, INF = 1e15;
int dist[N][N];

void make_graph() {
    for(ll i=0; i<=N; i++) {
        for(ll j=0; j<=N; j++) {
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
}

void floyd_warshall(ll n) {
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(dist[i][k]!=INF && dist[k][j]!=INF)
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
}

void solve(ll cs) {
    make_graph();

    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        dist[u][v] = wt;
    }

    floyd_warshall(n);

    for(ll i=1; i<=n; i++) {
        for(ll j=1; j<=n; j++) {
            if(dist[i][j]==INF) cout << "-1" << " ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

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

