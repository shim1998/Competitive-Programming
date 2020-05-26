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

vvi adj;
vb vis;
vi dis;

void bfs(int s){
    vis[s]=1;
    qii q;
    q.push(s);
    dis[s]=0;
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(int u:adj[v]){
            if(!vis[u]){
                vis[u]=1;
                q.push(u);
                dis[u]=dis[v]+1;
            }
        }
    }
}

void solve(){
    int n,m,u,v;
    cin>>n>>m;
    adj=vvi(n);
    vis=vb(n,0);
    dis=vi(n,-1);
    rep(i,0,m){
        cin>>u>>v;
        u--,v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int x;
    cin>>x;
    x--;
    bfs(x);
    rep(i,0,n) if(dis[i]!=0) cout<<dis[i]<<' ';
    cout<<'\n';
}
    
int main(){
    // #ifndef ONLINE_JUDGE  
        // freopen("input.txt", "r", stdin); 
        // freopen("output.txt", "w", stdout); 
    // #endif 
    // fastio;
    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
