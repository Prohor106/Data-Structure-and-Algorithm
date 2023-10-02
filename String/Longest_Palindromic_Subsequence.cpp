//Longest Palindromic Subsequence using dp
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()

void solve(ll cs) {
    string s, rev1;
    cin >> rev1;

    s = rev1;
    reverse(all(rev1));

    int row = s.size()+1, col = s.size()+1;
    int mat[row][col];
    char track[row][col];
    memset(mat, 0, sizeof(mat));

    for(int i=1; i<row; i++) {
        for(int j=1; j<col; j++) {
            if(s[i-1]==rev1[j-1]) {
                mat[i][j] = mat[i-1][j-1]+1;
                track[i][j] = 'D';
            }
            else {
                if(mat[i-1][j]>=mat[i][j-1]) {
                    mat[i][j] = mat[i-1][j];
                    track[i][j] = 'U';
                }
                else {
                    mat[i][j] = mat[i][j-1];
                    track[i][j] = 'L';
                }
            }
        }
    }

    string ans="";
    row--, col--;
    while(row>0 && col>0) {
        if(track[row][col]=='D') {
            ans += s[row-1];
            row--, col--;
        }
        else if(track[row][col]=='U') row--;
        else col--;
    }

    cout << ans << endl;
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
