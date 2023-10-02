/*
Q. Given an array A and Q queries. There are two types of queries,
	1. l....r , print the sum of Array[l...r]
	2. idx val, update A[idx] to val
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()

const ll N = 1e5+10;
ll bit[N];

ll query(ll idx){
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
	ll n;
	cin >> n;
	ll arr[n+1];
	for(ll i=1; i<=n; i++) {
		cin >> arr[i];
		update(i, arr[i], n);
	}
	
	ll q;
	cin >> q;
	while(q--){
		ll type;
		cin >> type;
		if(type==1){
			ll l, r;
			cin >> l >> r;
			cout << query(r)-query(l-1) << endl;
		}
		else{
			ll idx, val;
			cin >> idx >> val;
			update(idx, val-arr[idx], n);
			arr[idx] = val;
		}
	}
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
