#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()

ll Remainder(string dividend, ll divisor) {
    ll remainder = 0;
    for(ll i=0; i<dividend.size(); i++) {
        if(dividend[i]=='-') continue;
        remainder = remainder*10 + dividend[i]-'0';
        remainder %= divisor;
    }
    return remainder;
}

string Quotient(string dividend, ll divisor) {
    string quotient;
    ll idx = 0;
    ll temp = dividend[idx]-'0';
    while(temp < divisor) temp = temp*10 + dividend[++idx]-'0';
    while(idx < dividend.size()) {
        quotient += (temp / divisor) + '0';
        temp = (temp%divisor)*10 + dividend[++idx]-'0';
    }

    if(quotient.size()==0) return "0";
    else return quotient;
}

void solve(ll cs) {
    string dividend;
    ll divisor;
    cin >> dividend >> divisor;
    cout << "Quotient : " << Quotient(dividend, divisor) << endl;
    cout << "Remainder : " << Remainder(dividend, abs(divisor)) << endl;
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
