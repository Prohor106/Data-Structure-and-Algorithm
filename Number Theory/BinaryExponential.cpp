#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()

const ll MOD = 1e7+10;

ll BinaryExpo(ll b, ll p){
    ll ans = 1;
    while(p>0){
        if(p&1){
            ans *= b;
            ans %= MOD;
        }
        b *= b;
        b %= MOD;
        p >>= 1;
    }
    return ans;
}

void solve(ll cs) {
    ll base, power;
    cin >> base >> power;

    cout << BinaryExpo(base, power) << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    ll t=1, cs=1;
    cin>>t;
    while(t--){
        solve(cs++);
    }

    return 0;
}


