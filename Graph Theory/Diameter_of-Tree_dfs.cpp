/* Diameter of a tree :
   *step1 : with any root, find max dept node
   *step2 : with that node(from step1) as root, find max dept
   *step3 : max dept from step 2, is your diameter of tree
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
int depth[N];

void dfs(int vertex, int par=0){
   for(auto child : g[vertex]){
      if(child == par) continue;
      depth[child] = depth[vertex] + 1;
      dfs(child , vertex);
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

   int mx_depth = -1;
   int mx_d_node;
   fo(i,1,n+1){
      if(mx_depth < depth[i]){
         mx_depth = depth[i];
         mx_d_node = i;
      }
   }  
   mem(depth , 0);

   dfs(mx_d_node);

   mx_depth = -1;
   fo(i,1,n+1){
      if(mx_depth < depth[i]){
         mx_depth = depth[i];
      }
   }  

   cout << mx_depth << endl;  
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
