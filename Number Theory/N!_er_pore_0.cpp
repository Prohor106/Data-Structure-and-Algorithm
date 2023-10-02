#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()


void solve(ll cs) {
    ll n;
    cin >> n;
    ll ans = 0;
    ll k = 5;
    while(n/k>0){
        ans += n/k;
        k *= 5;
    }
    cout << ans << endl;
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


