//Q.Link : https://lightoj.com/problem/curious-robin-hood

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()

const ll N = 1e5+10;
ll bit[N];

ll get(ll idx){
	ll ans = 0;
	while(idx){
		ans += bit[idx];
		idx -= (idx & -idx);
	}
	return ans;
}

void update(ll idx, ll val, ll n){
	while(idx<=n){
		bit[idx] += val;
		idx += (idx & -idx);
	}
}

void solve(ll cs){
	ll n, q;
	cin >> n >> q;
	ll arr[n+1];
	for(ll i=1; i<=n; i++){
        cin >> arr[i];
        update(i, arr[i], n);
	}
	cout << "Case " << cs << ":" << endl;
	while(q--){
        ll type;
        cin >> type;
        if(type==1){
            ll idx;
            cin >> idx;
            idx++;
            ll ans = get(idx) - get(idx-1);
            update(idx, -ans, n);
            cout << ans << endl;

        }
        else if(type==2){
            ll idx, val;
            cin >> idx >> val;
            idx++;
            update(idx, val, n);
            arr[idx] += val;
        }
        else{
            ll l, r;
            cin >> l >> r;
            l++, r++;
            cout << get(r)-get(l-1) << endl;
        }
	}
	for(ll i=0; i<=n; i++) bit[i] = 0;
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
