#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 101
ll arr[N][N], res[N][N];

void multi(ll arr[][N], ll res[][N], ll n) {
   ll r[n][n];
   for (ll i = 1; i <= n; i++) {
      for (ll j = 1; j <= n; j++) {
         r[i][j] = 0;
         for (ll k = 1; k <= n; k++) {
            ll x = (arr[i][k] * res[k][j]);
            r[i][j] = (r[i][j] + x);
         }
      }
   }
   for (ll i = 1; i <= n; i++) {
      for (ll j = 1; j <= n; j++) {
         arr[i][j] = r[i][j];
      }
   }
}

void MatrixExpo(ll arr[][N], ll n, ll p) {
   for (ll i = 1; i <= n; i++) {
      for (ll j = 1; j <= n; j++) {
         if (i == j) res[i][j] = 1;
         else res[i][j] = 0;
      }
   }

   while (p) {
      if (p % 2) {
         multi(res, arr, n);
         p--;
      }
      else {
         multi(arr, arr, n);
         p /= 2;
      }
   }

   for (ll i = 1; i <= n; i++) {
      for (ll j = 1; j <= n; j++) {
         arr[i][j] = res[i][j];
      }
   }

}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(0), cout.tie(0);

   int tc;
   cin >> tc;
   while (tc--) {

      ll n, p;
      //n*n matrix, p power
      cin >> n >> p;

      for (ll i = 1; i <= n; i++) {
         for (ll j = 1; j <= n; j++) {
            cin >> arr[i][j];
         }
      }

      MatrixExpo(arr, n, p);

      for (ll i = 1; i <= n; i++) {
         for (ll j = 1; j <= n; j++) {
            cout << arr[i][j] << ' ';
         }
         cout << endl;
      }

   }

   return 0;
}