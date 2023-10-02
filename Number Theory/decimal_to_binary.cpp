#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()

string dec_to_binary(ll n){
    string ans1 = "";
    while(n>0){
        ans1 += (n % 2) + '0';
        n /= 2;
    }
    reverse(all(ans1));
    return ans1;
}

int main() {

    ll n;
    cin >> n;
    cout << dec_to_binary(n) << endl;

    return 0;
}
