#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()

const ll M = 1e6+31;
ll is_prime[M];
vector<ll> prime;

void seive() {
    for(ll i=2; i*i<M; i++)
        if(is_prime[i]==0)
            for(ll j=i*i; j<M; j+=i) is_prime[j] = 1;

    for(ll i=2; i<M; i++)
        if(is_prime[i]==0) prime.push_back(i);
}

ll noOfdiv(ll n) {
    ll ans = 1;
    for(ll i=0; i<prime.size() && prime[i]*prime[i]<=n; i++){
        ll cnt = 0;
        while(n%prime[i] == 0){
            cnt++;
            n /= prime[i];
            if(n<=1) break;
        }
        ans *= (cnt+1);
    }
    if(n>1) return ans*2;
    else return ans;
}

void solve(ll cs) {
    ll n;
    cin >> n;
    cout << noOfdiv(n) << endl;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    seive();
    ll t=1, cs=1;
    cin>>t;
    while(t--) {
        solve(cs++);
    }

    return 0;
}
