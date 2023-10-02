//how many ways to make n, using x ammount numbers.

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define INF (1 << 30)

const ll MOD = 1e9+7;
ll dp[1005][1005];

ll count(ll x, ll rem){
    if(x==0 && rem==0) return 1;
    if((x>0 && rem==0) || (x==0 && rem>0)) return 0;

    if(dp[x][rem]!=-1) return dp[x][rem];

    ll ans = 0;
    for(ll i=1; i<=x; i++)
        ans = (ans + count(x-i, rem-1))%MOD;

    return dp[x][rem] = ans;
}

void solve(ll cs) {
    ll n, x;
    cin >> n >> x;
    cout << count(n, x) << endl;
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
