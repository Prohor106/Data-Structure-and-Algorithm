#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll M = 2e5+10;
ll arr[M];
ll seg[4*M], prop[4*M];

void build(ll node, ll l, ll r) {
    if(l==r) {
        seg[node] = arr[l];
        prop[node]= 0;
        return;
    }
    ll mid = (l+r)>>1;
    ll l_node = node*2;
    ll r_node = node*2 + 1;

    build(l_node, l, mid);
    build(r_node, mid+1, r);

    seg[node]  = seg[l_node] + seg[r_node];
}

void update(ll node, ll l, ll r, ll i, ll j, ll val) {
    if(prop[node]!=0) {
        seg[node] += prop[node] * (r-l+1);
        if(l!=r) {
            prop[2*node] += prop[node];
            prop[2*node+1] += prop[node];
        }
        prop[node] = 0;
    }

    if(r<i || l>j) return;
    if(l>=i && r<=j) {
        seg[node] += val*(r-l+1);
        if(l!=r) {
            prop[2*node] += val;
            prop[2*node+1] += val;
        }
        return;
    }
    ll mid = (l+r)>>1;
    ll l_node = node*2;
    ll r_node = node*2 + 1;

    update(l_node, l, mid, i, j, val);
    update(r_node, mid+1, r, i, j, val);

    seg[node] = seg[l_node] + seg[r_node];
}

ll query(ll node, ll l, ll r, ll i, ll j) {
    if(prop[node]!=0) {
        seg[node] += prop[node] * (r-l+1);
        if(l!=r) {
            prop[2*node] += prop[node];
            prop[2*node+1] += prop[node];
        }
        prop[node] = 0;
    }

    if(r<i || l>j) return 0;
    if(l>=i && r<=j) return seg[node];

    ll mid = (l+r)>>1;
    ll l_node = node*2;
    ll r_node = node*2 + 1;

    ll q1 = query(l_node, l, mid, i, j);
    ll q2 = query(r_node, mid+1, r, i, j);

    return q1+q2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    ll n, q;
    cin >> n >> q;
    for(ll i =1; i<=n;  i++) cin >> arr[i];
    build(1, 1, n);

    while(q--){
        ll type;
        cin >> type;
        if(type==1){
            ll l, r, val;
            cin >> l >> r >> val;
            update(1, 1, n, l, r, val);
        }
        else{
            ll id;
            cin >> id;
            cout << query(1, 1, n, id, id) << endl;
        }
    }

    return 0;
}
