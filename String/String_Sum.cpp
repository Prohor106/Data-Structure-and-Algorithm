#include<bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    ll t=1, cs=1;
    cin>>t;
    while(t--) {
        string a, b;
        cin >> a >> b;

        if(a.size()<b.size()) swap(a, b);
        reverse(all(a));
        reverse(all(b));

        ll n = a.size(), m = b.size();
        ll i=0, j=0, carry=0;
        string ans="";

        while(i<n && j<m) {
            carry += (a[i]-'0')+(b[j]-'0');
            ans += (carry%10)+'0';
            carry /= 10;
            i++, j++;
        }
        while(i<n) {
            carry += a[i]-'0';
            ans += (carry%10)+'0';
            carry /= 10;
            i++;
        }
        while(carry) {
            ans += ((carry%10)+'0');
            carry /= 10;
        }
        while(ans.size()>1 && ans.back()=='0')
            ans.pop_back();

        reverse(all(ans));

        cout << ans << endl;
        
    }

    return 0;
}
