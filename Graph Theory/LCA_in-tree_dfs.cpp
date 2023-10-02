/* LCA = lowest Common Ancestor. between 2 nodes...
   *step1 : parent store
   *step2 : path find (vector)
   *step3 : max common path find between 2 nodes
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i,a,n) for(ll i=a;i<n;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define fi first
#define sc second
#define endl '\n'
#define mem(a,b) memset(a, b, sizeof(a))
#define de(x) cerr<<#x<<" :: "<<x<<" "<<endl

const int N = 1e5+10;
vector<int>g[N];
int pa[N];

void dfs(int vertex, int par=0){
   pa[vertex] = par;
   for(auto child : g[vertex]){
      if(child == par) continue;
      dfs(child , vertex);
   }
}

vector<int> path(int v){
   vector<int> ans;
   while(v != 0){
      ans.pb(v);
      v = pa[v];
   }
   reverse(all(ans));
   return ans;
}

void solve(){
   int n;
   cin>>n;
   fo(i,0,n-1){
      int v1,v2;
      cin>>v1>>v2;
      g[v1].pb(v2);
      g[v2].pb(v1);
   }

   dfs(1);

   int x,y;
   cin >> x >> y;

   vector<int> path_x = path(x);
   vector<int> path_y = path(y);

   int mn_ln = min(path_x.size() , path_y.size());
   int lca = -1;

   fo(i,0,mn_ln){
      if(path_x[i] == path_y[i]){
         lca = path_x[i];
         // or lca = path_y[i];
      }
      else{
         break;
      }
   } 

   cout << lca << endl;
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(0), cout.tie(0);

    ll t=1;
    cin>>t;
    while(t--){
      solve();
    }

    return 0;

}
