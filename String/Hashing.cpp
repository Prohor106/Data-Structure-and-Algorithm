#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()

const int Max = 2e5+10;
const int base = 331;
const int Mod = 1e9+7;

ll pw[Max], Hash[Max];

void pre_power(){
    pw[0] = 1;
    for(int i=1; i<Max; i++)
        pw[i] = (pw[i-1]*base) %Mod;
}

void get_hash(string s){
    ll hash_val = 0;
    for(int i=0; i<s.size(); i++){
        hash_val = (hash_val*base + (s[i]-'a'+1)) %Mod;
        Hash[i+1] = hash_val;
    }
}

ll SubStringHash(int l, int r){
    return ((Hash[r] - Hash[l-1]*pw[r-l+1]) %Mod + Mod) %Mod;
}

int main() {
    pre_power();

    string s;
    cin >> s;
    get_hash(s);

    cout << SubStringHash(1, s.size()) << endl;

    return 0;
}

