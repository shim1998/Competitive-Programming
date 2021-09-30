//My submission to codeforces round 745 Div 2
//https://codeforces.com/contest/1581/problem/C
#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

const int INF=1000000007;

void solve(){
    int n,m;cin>>n>>m;
    vector<vector<int>> pre3(n+1,vector<int>(n+1,INF));
    vector<string> br(n);
    for (auto &s:br) cin>>s;
    vector<vector<int>> b(m,vector<int>(n+1,0));
    for (int c=0;c<m;++c) {
        for (int r=0;r<n;++r){
            b[c][r+1]=b[c][r]+(br[r][c]=='1');
        }
    }
    int re=INF;
    for (int c=0;c<m-3;++c){
        // update pre3
        for (int i=1;i<n;++i){
            for (int j=i+2;j<n-1;++j){
                int add=b[c][j+1]-b[c][i];
                pre3[i][j]=min(pre3[i][j]+(add+(br[i-1][c]=='0')+(br[j+1][c]=='0')),j-i+1-add);
                int cur=0;
                for (int t=1;t<=2;++t){
                    cur+=(b[c+t][j+1]-b[c+t][i]+(br[i-1][c+t]=='0')+(br[j+1][c+t]=='0'));
                }
                cur+=j-i+1-(b[c+3][j+1]-b[c+3][i]);
                re=min(re,pre3[i][j]+cur);
            }
        }
    }
    cout<<re<<'\n';
}


int main() {
    fastio;
    int t;cin>>t;
    while (t--) solve();
    return 0;
}
