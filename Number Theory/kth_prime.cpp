#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> pii;

#define testcase(t)  ll t; cin>>t; while(t--)
#define fo(i,a,n) for(ll i=a;i<n;i++)
#define all(v) v.begin(),v.end()
#define fi first
#define sc second
#define pb push_back
#define mp make_pair
#define endl '\n'
#define mem(a,b) memset(a, b, sizeof(a))

const int M = 1e7 + 10;
ll ps1[M];
ll ps2[M];
vector<ll>v;

void solve() {

   for (int i = 2; i * i <= M; i++) {
      if (ps1[i] == 0) {
         for (int j = i * i; j <= M; j += i) {
            ps1[j] = 1;
         }
      }
   }

   for (int i = 2; i <= M; i++)
      if (ps1[i] == 0) v.pb(i);

   int k;
   cin >> k;
   cout << v[k - 1] << endl;
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(0), cout.tie(0);

   testcase(t)
   solve();

   return 0;

}