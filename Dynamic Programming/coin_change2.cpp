//Minimum coin need to make x . (coin supply infinity)
//Maximum coin need to make x . (coin supply infinity)

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define INF (1 << 30)

vector<ll> coin;
ll dp[1005];

ll minc(ll n){
    if(n==0) return 0;
    if(n<0) return INF;

    if(dp[n] != -1) return dp[n];

    ll res = INF;
    //ll res = -INF; //for maximum
    for(ll c:coin){
        res = min(res, 1+minc(n-c));
        //res = max(res, 1+minc(n-c));  //for maximum
    }

    return dp[n] = res;
}

void solve(ll cs) {
    ll n;
    cout << "Number of Coin : " << endl;
    cin >> n;

    cout << "Enter Coins : " << endl;
    for(ll i=0; i<n; i++){
        ll y;
        cin >> y;
        coin.push_back(y);
    }

    ll x;
    cout << "Enter Ammount : " << endl;
    cin >> x;

    ll result = minc(x);
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
