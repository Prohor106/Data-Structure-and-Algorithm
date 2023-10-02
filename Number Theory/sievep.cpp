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

const int M = 1e5 + 10;
ll ps1[M];
ll ps2[M];

void solve() {
   int n;
   cin >> n;
   int prime[n + 3];
   memset(prime, 0, sizeof(prime));

   for (int i = 2; i * i <= n; i++) {
      if (prime[i] == 0) {
         for (int j = i * i; j <= n; j += i) {
            prime[j] = 1;
         }
      }
   }

   for (int i = 2; i <= n; i++)
      if (prime[i] == 0) cout << i << ' ';
   cout << endl;
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(0), cout.tie(0);

   testcase(t)
   solve();

   return 0;

}