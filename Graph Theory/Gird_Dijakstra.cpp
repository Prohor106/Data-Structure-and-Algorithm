//Question Link :- https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=870

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define INF (1<<30)

typedef pair<int, pair<int, int>> pipii;

int n, m;
int g[1005][1005];
int dist[1005][1005];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool valid(int i, int j) {
    return(i>=0 && j>=0 && i<n && j<m);
}

void dijkstra(int n, int m) {
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            dist[i][j] = INF;

    priority_queue<pipii, vector<pipii>, greater<pipii> > pq;

    pq.push({g[0][0], {0,0}});
    dist[0][0] = g[0][0];

    while(!pq.empty()) {
        pair<int, int>node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        int x = node.first;
        int y = node.second;

        if(dist[x][y] < cost) continue;

        for(int i=0; i<4; i++) {
            int new_x = x+dx[i];
            int new_y = y+dy[i];
            if(valid(new_x, new_y)) {
                if(g[new_x][new_y]+cost < dist[new_x][new_y]) {
                    dist[new_x][new_y] = g[new_x][new_y]+cost;
                    pq.push({dist[new_x][new_y], {new_x, new_y}});
                }
            }
        }
    }
}

void solve(ll cs) {

    cin >> n >> m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> g[i][j];

    dijkstra(n, m);

    cout << dist[n-1][m-1] << endl;
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
