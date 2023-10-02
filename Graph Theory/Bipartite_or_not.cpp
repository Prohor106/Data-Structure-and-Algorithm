#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()

ll const N = 1e3+5;
vector<ll> g[N];
bool vis[N];
ll color[N];

bool bfs(ll src) {
    queue<ll> q;
    q.push(src);
    color[src] = 0;
    while(!q.empty()) {
        ll new_src = q.front();
        q.pop();
        for(auto child : g[new_src]) {
            if(color[child]==-1) {
                q.push(child);
                color[child] = 1-color[new_src];
            }
            else if(color[child]==color[new_src]) return false;
        }
    }
    return true;
}

bool isBipart(ll n) {
    for(ll i=0; i<=n; i++) color[i] = -1;
    for(ll i=1; i<=n; i++) {
        if(color[i]==-1) {
            if(!bfs(i)) return false;
        }
    }

    return true;
}

void solve(ll cs) {
    ll n, x;
    cin >> n;
    for(ll i=1; i<=n; i++) {
        while(cin >> x && x!=0) {
            g[i].push_back(x);
            g[x].push_back(i);
        }
    }

    bool ck = isBipart(n);
    if(!ck) cout << -1 << endl;
    else {
        for(ll i=1; i<=n; i++) cout << color[i];
        cout << endl;
    }
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
