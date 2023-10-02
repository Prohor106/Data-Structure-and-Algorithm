#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()

ll mul(ll n, ll r, ll m){
    if(r==0) return 0;
    if(r&1) return (mul(n, r-1, m)%m + n%m) %m;
    else return (mul(n, r/2, m)%m + mul(n, r/2, m)%m) %m;
}

void solve(ll cs) {
    ll n, r, m;
    cin >> n >> r >> m;
    cout << mul(n, r, m) << endl;
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
