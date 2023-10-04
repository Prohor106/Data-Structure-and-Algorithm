#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll M = 2e5+10;

ll arr[M];
struct Node {
    ll sum, pref, suf, ans;
} seg[4*M];

Node ck(Node l, Node r) {
    Node res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suf = max(r.suf, r.sum + l.suf);
    res.ans = max({l.ans, r.ans, l.suf + r.pref});

    return res;
}

Node make(ll val) {
    Node m;
    m.sum = val;
    m.pref = m.suf = m.ans = max(0LL, val);

    return m;
}

void build(ll node, ll l, ll r) {
    if(l==r) {
        seg[node] = make(arr[l]);
        return;
    }
    ll mid = (l+r)>>1;
    ll l_node = node*2;
    ll r_node = node*2 + 1;

    build(l_node, l, mid);
    build(r_node, mid+1, r);

    seg[node] = ck(seg[l_node], seg[r_node]);
}

void update(ll node, ll l, ll r, ll idx, ll val) {
    if(l==r) {
        seg[node] = make(val);
        return;
    }
    ll mid = (l+r)>>1;
    ll l_node = node*2;
    ll r_node = node*2 + 1;

    if(idx <= mid) {
        update(l_node, l, mid, idx, val);
    }
    else {
        update(r_node, mid+1, r, idx, val);
    }

    seg[node] = ck(seg[l_node], seg[r_node]);
}

Node query(ll node, ll l, ll r, ll i, ll j) {
    if(j<l || i>r) return make(0);
    if(l>=i && r<=j) return seg[node];

    ll mid = (l+r)>>1;
    ll l_node = node*2;
    ll r_node = node*2 + 1;

    Node q1 = query(l_node, l, mid, i, j);
    Node q2 = query(r_node, mid+1, r, i, j);

    return ck(q1, q2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    ll n, q;
    cin >> n >> q;
    for(ll i=1; i<=n; i++) cin >> arr[i];
    build(1, 1, n);
    cout << query(1,1,n, 1, n).ans << endl;

    while(q--) {
        ll ty;
        cin >> ty;
        if(ty==1) {
            ll idx, val;
            cin >> idx >> val;
            update(1, 1, n, ++idx, val);
        }
        else {
            ll l, r;
            cin >> l >> r;
            cout << query(1,1,n, l, r).ans << endl;
        }
    }

    return 0;
}

