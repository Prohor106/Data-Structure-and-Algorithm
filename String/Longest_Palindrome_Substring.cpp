//Longest Palindrome Substring
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()

int check(string s, int p1, int p2, int &st, int &en){
    int cnt=0;
    if(p1==p2){
        cnt++;
        p1--;
        p2++;
    }
    while(p1>=0 && p2<s.length()){
        if(s[p1]!=s[p2]){
            st = p1+1;
            en = p2-1;
            return cnt;
        }
        else{
            p1--;
            p2++;
            cnt += 2;
        }
    }

    st = p1+1;
    en = p2-1;
    return cnt;
}

string pali(string s){
    int st=-1, en=-1, len=0, f_st=-1, f_en=-1;

    for(int i=0; i<s.length(); i++){
        int x = check(s, i, i, st, en); //for odd length
        if(x>len){
            len = x;
            f_st = st;
            f_en = en;
        }

        int y = check(s, i, i+1, st, en); // for even length
        if(y>len){
            len = y;
            f_st = st;
            f_en = en;
        }
    }

    return s.substr(f_st, f_en-f_st+1);
}

void solve(ll cs) {
    string s;
    cin >> s;

    cout << pali(s) << endl;
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



