#include<bits/stdc++.h>
using namespace std;
#define bug(a) cout << #a << " : " << a << endl
#define ll long long
const int M = 5e6+10;

string get_bi(int n) {
    string ans;
    while(n) {
        ans.push_back(n%2 + '0');
        n/=2;
    }
    while(ans.size()<31) ans.push_back('0');
    reverse(ans.begin(), ans.end());
    return ans;
}

int get_dec(string s) {
    int ans = 0;
    reverse(s.begin(), s.end());
    for(int i=0; i<s.size(); i++)
        if(s[i]=='1') ans += (1<<i);
    return ans;
}

struct node {
    bool is_word;
    int next[2];
    int cnt;
    node() {
        memset(next, -1, sizeof(next));
        is_word = false;
        cnt = 0;
    }
} trie[M];
int sz = 0;

void Insert(string s) {
    int now = 0;
    trie[now].cnt++;
    for(int i=0; i<s.size(); i++) {
        int d = s[i]-'0';
        if(trie[now].next[d]==-1)
            trie[now].next[d] = ++sz;

        now = trie[now].next[d];
        trie[now].cnt++;
    }
    trie[now].is_word = true;
}

void Delete(string s) {
    int now = 0;
    trie[now].cnt--;
    for(int i=0; i<s.size(); i++) {
        int ind = s[i]-'0';
        int tmp = trie[now].next[ind];
        if(trie[tmp].cnt == 1) {
            trie[now].next[ind] = -1;
        }
        now = tmp;
        trie[now].cnt--;
    }
}

void clear() {
    sz = 0;
    for(int i=0; i<M; i++) {
        trie[i].is_word = false;
        trie[i].cnt = 0;
        memset(trie[i].next, -1, sizeof(trie[i].next));
    }
}

int maxXor(string s) {
    int now = 0;
    string ans = "";
    for(int i=0; i<s.size(); i++) {
        int d = s[i]-'0', id = d^1;
        if(d==0) {
            if(trie[now].next[id]==-1) ans += '0', id ^= 1;
            else ans += '1';
        }
        else {
            if(trie[now].next[d]==-1) ans += '1', id ^= 1;
            else ans += '0';
        }
        now = trie[now].next[id];
    }

    int a = get_dec(ans);
    int b = get_dec(s);

    return (a^b);
}

int minXor(string s) {
    int now = 0;
    string ans = "";
    for(int i=0; i<s.size(); i++) {
        int d = s[i]-'0', id = d^1;
        if(d==0) {
            if(trie[now].next[d]==-1) ans += '1';
            else ans += '0', id ^= 1;
        }
        else {
            if(trie[now].next[d]==-1) ans += '0';
            else ans += '1', id ^= 1;
        }
        now = trie[now].next[id];
    }

    int a = get_dec(ans);
    int b = get_dec(s);

    return (a^b);
}

void solve(ll cs) {

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
