/*Made by Shivam Solanki*/
#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define ll long long int
#define endl '\n'
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<pii> vp;
typedef vector<pll> vpll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef set<int> sii;
typedef set<ll> sll;
typedef queue<int> qii;
typedef priority_queue<int> pq;
typedef unordered_map<int,int> umii;
typedef unordered_map<ll,ll> umll;
#define all(x) x.begin(),x.end()
#define rep(i,k,n) for (int i = k; i < n; ++i) 
#define repr(i,k,n) for (int i = n; i>=k; --i)
#define repll(i,k,n) for (ll i = k; i < n; ++i) 
#define pb push_back
#define mp make_pair
#define gcd __gcd
#define F first
#define S second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 1e9+5;
const int MOD = 1e9+7;
double pi = 2 * acos(0.0); 
const int N=20;
vector<pair<int,int>> adj[N];
vector<int>d(N,INF);
vector<int> p(N,-1);
int ans=0;

bool spfa(int s,int end,int n) {
    d[s]=0;
    int x;
    for(int i=0;i<1000;i++){
        x=-1;
        for (int j=0;j<n;++j){
            int v=j;
            for(pair<int,int> u:adj[v]){
                if (d[v]<INF){
                    if (d[u.first]>d[v]+u.second){
                        d[u.first]=d[v]+u.second;
                        p[u.first]=v;
                        x=u.first;
                    }
                }
            }
        }
    }
    if (d[end] == INF)
        return 0;
    if(x!=-1){
        int y = x;
        for (int i=0; i<n; ++i)
            y = p[y];

        vector<int> path;
        for (int cur=y; ; cur=p[cur])
        {
            path.push_back (cur);
            if (cur == y && path.size() > 1)
                break;
        }
        reverse (path.begin(), path.end());

        // cout << "Negative cycle: ";
        for (size_t i=0; i<path.size()-2; ++i){
            auto x=adj[path[i]];
            for(auto c:x){
                if(c.first==path[i+1]){
                    // cout<<c.second<<' ';
                    ans=(ans+c.second)%MOD;
                }
            }
            // cout<<'\n';
            // cout << path[i] << ' ';
        }
        return 1;
    }
    else{
        vector<int> path;
        for (int cur = end; cur != -1; cur = p[cur])
            path.push_back (cur);
        reverse (path.begin(), path.end());
        // cout << "Path from " << s << " to " << end << ": ";
        for (size_t i=0; i<path.size(); ++i){
            auto x=adj[path[i]];
            for(auto c:x){
                if(c.first==path[i+1]){
                    // cout<<c.second<<' ';
                    ans=(ans+c.second)%MOD;
                }
            }
            // cout<<'\n';
            // cout << path[i] << ' ';
        }
    }
    return 1;
}

int getDirectedPath(int n,vector<int> E,int start,int end){
    int m=E.size();
    for(int i=0;i<m;i+=3){
        int u=E[i];
        int v=E[i+1];
        int w=E[i+2];
        adj[u].push_back({v,w});
    }
    // for(int i=0;i<n;i++){
    //     cout<<i<<": ";
    //     for(pair<int,int> j:adj[i]){
    //         cout<<j.first<<' ';
    //     }
    //     cout<<'\n';
    // }
    bool f=spfa(start,end,n);
    if(!f) return MOD;
    return ans;
}

int main(){ 
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int>E(m);
    for(int i=0;i<m;i++){
        cin>>E[i];
    }
    int start,end;
    cin>>start>>end;
    cout<<getDirectedPath(n,E,start,end);
    return 0;
}