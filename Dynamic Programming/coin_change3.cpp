//minimum coin need to make x . (coin supply finite)

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define INF (1 << 30)

ll n;
vector<ll> coin;
vector<ll> coin_am;
ll dp[1005][1005];

ll minc(ll idx, ll x){
    if(idx==n){
        if(x==0) return 0;
        return INF;
    }
    if(x<0) return INF;

    if(dp[idx][x] != -1) return dp[idx][x];

    ll result = INF;
    for(ll i=0; i<=coin_am[idx]; i++){
        result = min(result, i+minc(idx+1, x-i*coin[idx]));
    }

    return dp[idx][x] = result;
}

void solve(ll cs) {

    cout << "Number of Coin : " << endl;
    cin >> n;

    cout << "Enter Coins : " << endl;
    for(ll i=0; i<n; i++){
        ll y;
        cin >> y;
        coin.push_back(y);
    }

    cout << "Enter Coins Ammount: " << endl;
    for(ll i=0; i<n; i++){
        ll y;
        cin >> y;
        coin_am.push_back(y);
    }

    ll x;
    cout << "Enter Ammount : " << endl;
    cin >> x;

    ll result = minc(0, x);
    if(result >= INF) cout << "IMPOSSIBLE" << endl;
    //if(result <= -INF) cout << "IMPOSSIBLE" << endl; //for maximum
    else cout << "Minimum Number of Coins : " << result << endl;
    //else cout << "Maximum Number of Coins : " << result << endl; //for maximum
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    memset(dp, -1, sizeof(dp));

    ll t=1, cs=1;
    //cin>>t;
    while(t--) {
        solve(cs++);
    }

    return 0;
}
