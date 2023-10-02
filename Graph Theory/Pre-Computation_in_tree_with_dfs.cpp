/* Given Q queries , Q <= 10e5
 * In each query given V
 * Print subtree sum of V, 
 * Number of even numbers in subtree of V
 * Number of odd numbers in subtree of V
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

const ll N = 1e5+10;
vector<ll>g[N];
ll subtree_sum[N];
//ll val[N];
ll even_cnt[N];
ll odd_cnt[N];

void dfs(int vertex, int par=0){
   if(vertex&1) odd_cnt[vertex]++;
   else even_cnt[vertex]++;
   
   subtree_sum[vertex] += vertex;
   //subtree_sum[vertex] += val[vertex];

   for(auto child : g[vertex]){
      if(child == par) continue;
      dfs(child , vertex);

      subtree_sum[vertex] += subtree_sum[child];
      even_cnt[vertex] += even_cnt[child];
      odd_cnt[vertex] += odd_cnt[child];
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

   int q;
   cin>>q;
   while(q--){
      int v;
      cin>>v;

      cout << "Sum of subtree of " << v << " = : " << subtree_sum[v] << endl;
      cout << "Number of even numbers in subtree of " << v << " = : " << even_cnt[v] << endl;
      cout << "Number of odd numbers in subtree of " << v << " = : " << odd_cnt[v] << endl;
      cout<<endl;
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
