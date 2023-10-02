#include<bits/stdc++.h>
using namespace std;

void primefact(int n) {
   for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
         int cnt = 0;
         while (n % i == 0) {
            cnt++;
            n /= i;
         }
         cout << i << "^" << cnt << ",";
      }
   }

   if (n > 1) cout << n << "^" << 1 << endl;
   else cout << endl;

}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(0), cout.tie(0);

   int tc;
   cin >> tc;
   while (tc--) {
      int n;
      cin >> n;
      primefact(n);
   }

   return 0;
}