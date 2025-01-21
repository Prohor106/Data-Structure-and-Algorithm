#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
#define bug(a) cout << #a << " : " << a << endl;
#define endl '\n'
#pragma GCC target("popcnt")

int mod = 1000000007;
struct Mat{
    int n, m;
    vector<vector<int>> a;
    Mat(){}
    Mat(int _n, int _m){n=_n; m=_m; a.assign(n, vector<int>(m, 0));}
    Mat(vector<vector<int>>v){n=v.size(); m=n?v[0].size():0; a=v;}
    inline void make_unit(){
        assert(n==m);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) a[i][j] = i==j;
    }
    inline Mat operator + (const Mat &b){
        assert(n==b.n && m==b.m);
        Mat ans = Mat(n, m);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++) ans.a[i][j] = (a[i][j]+b.a[i][j])%mod;
        return ans;
    }
    inline Mat operator - (const Mat &b){
        assert(n==b.n && m==b.m);
        Mat ans = Mat(n, m);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++) ans.a[i][j] = (a[i][j]-b.a[i][j]+mod)%mod;
        return ans;
    }
    inline Mat operator * (const Mat &b){
        assert(m==b.n);
        Mat ans = Mat(n, b.m);
        for(int i=0; i<n; i++)
            for(int j=0; j<b.m; j++)
                for(int k=0; k<m; k++) ans.a[i][j] = (ans.a[i][j]+1LL*a[i][k]*b.a[k][j]%mod)%mod;
        return ans;
    }
    inline Mat pow (long long k){
        assert(n==m);
        Mat ans(n, n), t=a; ans.make_unit();
        while(k) {if(k&1) ans = ans*t; t=t*t; k>>=1;}
        return ans;
    }
    inline Mat& operator += (const Mat& b) {return *this=(*this)+b;}
    inline Mat& operator -= (const Mat& b) {return *this=(*this)-b;}
    inline Mat& operator *= (const Mat& b) {return *this=(*this)*b;}
    inline bool operator == (const Mat& b) {return a==b.a;}
    inline bool operator != (const Mat& b) {return a!=b.a;}

    static ll nthFibonacci(int x, int y, int n, int m){
        if(n==0) return x;
        if(n==1) return y;
        Mat fibMat(2, 2);
        fibMat.a = {{1, 1}, {1, 0}};
        Mat result = fibMat.pow(n-1);
        return (1LL*result.a[0][0]*y + 1LL*result.a[0][1]*x)%m;
    }
    static ll sumNthFibonacci(int x, int y, int n, int m){
        if(n==0) return x%mod;
        if(n==1) return (x+y)%mod;
        Mat fibMat(2, 2);
        fibMat.a = {{1, 1}, {1, 0}};
        Mat result = fibMat.pow(n+1);
        return (1LL*result.a[0][0]*y + 1LL*result.a[0][1]*x -1+m)%m;
    }
};

void solve(ll cs) {
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    mod=1;
    for(int i=0; i<m; i++) mod*=10;
    
    cout << "Case " << cs << ": ";
    cout << Mat::nthFibonacci(a, b, n, mod) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
  
    ll t=1, cs=1;
    cin>>t;
    while(t--) {
        solve(cs++);
    }

    return 0;
}
