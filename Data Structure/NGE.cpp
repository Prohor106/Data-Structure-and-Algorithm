#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> NGE(vector<int> v, int n) {
    vector<int> nge(n);
    stack<int> st;
    for(int i=0; i<n; i++) {
        while(!st.empty() && v[i] > v[st.top()]) {
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    while(!st.empty()) {
        nge[st.top()] = st.top();
        st.pop();
    }
    return nge;
}

void solve(ll cs) {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    vector<int> ans = NGE(v, n);

    for(int i=0; i<n; i++) {
        cout << v[i] << " " << v[ans[i]] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t=1, cs=1;
    cin>>t;
    while(t--) {
        solve(cs++);
    }
    return 0;
}
