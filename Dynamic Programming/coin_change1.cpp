//is possible(making x) or not, only taking one coin

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()

ll n, x;
vector<ll> coin;
ll dp[1005][1005];

bool isposs(ll n, ll idx){
    
    if(idx == 4) {
        if(n==0) return 1;
        else return 0;
    }
    if(n<0) return 0;

    if(dp[n][idx]!=-1) return dp[n][idx];

    int ok = 0;
    ok |= isposs(n-coin[idx], idx+1);
    ok |= isposs(n, idx+1); 

    return dp[n][idx] = ok;
}

void solve(ll cs) {
    
    cin >> n >> x;

    for(ll i=0; i<n; i++){
        ll y;
        cin >> y;
        coin.push_back(y);
    }

    cout << isposs(x, 0) << endl;
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
