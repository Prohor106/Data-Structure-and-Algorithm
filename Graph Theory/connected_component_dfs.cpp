#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i,a,n) for(ll i=a;i<n;i++)
#define all(v) (v).begin(),(v).end()
#define al(rv) (v).rbegin(),(v).rend()
#define fi first
#define sc second
#define pb push_back
#define endl '\n'
#define mem(a,b) memset(a, b, sizeof(a))

const int N = 1e5+10;
vector<int>g[N];
bool vis[N];

vector<vector<int>>cc;
vector<int>cur_cc;

void dfs(int vertex){
   vis[vertex] = true;
   cur_cc.pb(vertex);
   for(int child : g[vertex]){
      if(vis[child]) continue;
      dfs(child);
   }
}

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(0), cout.tie(0);

   int v,e;
   cin>>v>>e;
   while(e--){
      int a,b;
      cin>>a>>b;

      g[a].pb(b);
      g[b].pb(a);
   }

   for(int i=1; i<=v; i++){
      if(vis[i]) continue;
      cur_cc.clear();
      dfs(i);
      cc.pb(cur_cc);
   }

   cout << "Conected Compo = " << cc.size() << endl;
   
   for(auto p_cc : cc){
      for(auto ver : p_cc){
         cout << ver << ' ';
      }
      cout<<endl;
   }

   return 0;
}