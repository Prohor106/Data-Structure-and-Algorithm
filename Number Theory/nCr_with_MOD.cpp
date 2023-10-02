#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define MOD 1000000007
#define N 10000005

ll fact[N];

ll binExp(ll a, ll b){
    ll ans = 1;
    while(b > 0){
        if(b & 1){
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }
    return ans;
}

ll modInv(ll a, ll b){
    return binExp(a, b-2);
}

ll nCr(ll n, ll r){
    if(n < r || n < 0 || r < 0) return 0;
    return (fact[n] * (( modInv(fact[r], MOD) * modInv(fact[n-r], MOD) ) % MOD )) % MOD;
}

void solve(ll cs) {
    ll n, m;
    cin >> n >> m;
    cout << nCr(n, m) << endl;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    fact[0] = 1;
    for(ll i=1; i<N; i++)
        fact[i] = (i * fact[i-1]) % MOD;

    ll t=1, cs=1;
    //cin>>t;
    while(t--) {
        solve(cs++);
    }

    return 0;
}
