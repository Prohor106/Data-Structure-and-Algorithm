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

const ll N = 1e5+10;
vector<ll>g[N];
ll height[N], depth[N];

void dfs(int vertex, int par=0){

   for(auto child : g[vertex]){
      if(child == par) continue;

      depth[child] = depth[vertex] + 1;
      dfs(child , vertex);
      height[vertex] = max(height[vertex] , height[child]+1);
   }
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

   fo(i,1,n+1){
      cout<<i<<" "<<depth[i]<<" "<<height[i]<<endl;
   }
   cout<<endl;
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
