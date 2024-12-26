const int M = 30;
const int N = 2e5+5;
int timer;
int ancestor[N][M], tin[N], tout[N];
vector<int> adj[N];

void dfs(int u, int p) {
    tin[u] = ++timer;

    ancestor[u][0] = p;
    for(int i=1; i<M; i++)
        ancestor[u][i] = ancestor[ancestor[u][i-1]][i-1];

    for(auto v:adj[u])
        if(v!=p) dfs(v, u);

    tout[u] = ++timer;
}

bool is_ancestor(int u, int v){
    return (tin[u]<=tin[v] && tout[u]>=tout[v]);
}

int lca(int u, int v) {
   if(is_ancestor(u, v)) return u;
   if(is_ancestor(v, u)) return v;

    for(int i=M-1; i>=0; i--)
        if(!is_ancestor(ancestor[u][i], v))
            u = ancestor[u][i];

    return ancestor[u][0];
}
