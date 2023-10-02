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

bool prime(int n) {
   if (n < 2) return false;
   if (n == 2) return true;
   if (n % 2 == 0) return false;
   for (int i = 3; i * i <= n; i += 2) {
      if (n % i == 0) return false;
   }
   return true;
}

void solve() {
   int n;
   cin >> n;
   if (prime(n)) cout << "Prime" << endl;
   else cout << "Not Prime" << endl;
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(0), cout.tie(0);

   testcase(t)
   solve();

   return 0;

}