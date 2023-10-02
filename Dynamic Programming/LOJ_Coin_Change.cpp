//Q.Link :- https://lightoj.com/problem/coin-change-i

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define INF (1 << 30)

const ll MOD = 100000007;

ll n;
vector<ll> c;
vector<ll> v;
ll dp[1005][1005];

ll count(ll idx, ll x){
    if(idx==n){
        if(x==0) return 1;
        else return 0;
    }
    if(x<0) return 0;

    if(dp[idx][x]!=-1) return dp[idx][x];

    ll ans = 0;
    for(ll i=0; i<=v[idx]; i++)
        ans = (ans + count(idx+1, x-i*c[idx])) %MOD;

    return dp[idx][x] = ans;
}

void solve(ll cs) {
    ll x;
    cin >> n >> x;
    
    c.clear();
    for(ll i=0; i<n; i++){
        ll y;
        cin >> y;
        c.push_back(y);
    }

    v.clear();
    for(ll i=0; i<n; i++){
        ll y;
        cin >> y;
        v.push_back(y);
    }

    memset(dp, -1, sizeof(dp));

    cout << "Case " << cs << ": " << count(0, x) << endl;
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
