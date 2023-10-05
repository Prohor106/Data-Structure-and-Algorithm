#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 2e5+10;

ll arr[M];
ll seg[4*M];

void build(ll node, ll l, ll r) {
    if(l==r) {
        seg[node] = arr[l];
        return;
    }
    ll mid = (l+r)>>1;
    ll l_node = node*2;
    ll r_node = node*2 + 1;

    build(l_node, l, mid);
    build(r_node, mid+1, r);

    seg[node] = seg[l_node] + seg[r_node];
}

void update(ll node, ll l, ll r, ll idx) {
    if(l==r) {
        seg[node] = 1-seg[node];
        return;
    }
    ll mid = (l+r)>>1;
    ll l_node = node*2;
    ll r_node = node*2 + 1;

    if(idx <= mid) {
        update(l_node, l, mid, idx);
    }
    else {
        update(r_node, mid+1, r, idx);
    }

    seg[node] = seg[l_node]+seg[r_node];
}

ll query(ll node, ll l, ll r, ll k) {
    if(l==r) return l;

    int mid = (l+r)>>1;
    int l_node = node*2;
    int r_node = node*2 + 1;

    if(k>seg[l_node]) return query(r_node, mid+1, r, k-seg[l_node]);
    else  return query(l_node, l, mid, k);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--) {
        ll n, q;
        cin >> n >> q;
        for(ll i=1; i<=n; i++) cin >> arr[i];
        build(1, 1, n);

        while(q--) {
            ll ty;
            cin >> ty;
            if(ty==1) {
                ll id;
                cin >> id;
                update(1, 1, n, ++id);
            }
            else {
                ll k;
                cin >> k;
                cout << query(1, 1, n, ++k)-1 << endl;
            }
        }

        for(ll i=0; i<=4*n; i++) seg[i] = 0;
    }
}

