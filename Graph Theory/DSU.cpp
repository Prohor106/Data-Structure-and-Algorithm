#include<bits/stdc++.h>;
using namespace std;
const int N = 1e5+7;

int parent[N];
int sz[N];

void make(int v){
    parent[v] = v;
    sz[v] = 1;
}

int find(int v){
    if(v==parent[v]) return v;
    return parent[v] = find(parent[v]);
}

void Union(int a, int b){
    a = find(a), b = find(b);
    if(a!=b){
        if(sz[a] < sz[b]) parent[a] = b, sz[b] += sz[a];
        else parent[b] = a, sz[a] += sz[b];
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++) make(i);
    while(k--){
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }
    int cnt=0;
    for(int i=1; i<=n; i++)
        if(parent[i]==i) cnt++;

    cout << cnt << endl;
}
