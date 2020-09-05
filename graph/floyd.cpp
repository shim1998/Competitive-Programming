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
const ll inf = 2e18+11;

//CSES 1672

void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    vvl d(n,vll(n,inf));
    vp adj[n];
    rep(i,0,m){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        u--,v--;
        adj[u].pb({w,v});
        adj[v].pb({w,u});
        d[u][v]=min(d[u][v],w);
        d[v][u]=min(d[v][u],w);
    }
    rep(i,0,n){
        d[i][i]=0;
    }
    rep(k,0,n){
        rep(i,0,n){
            rep(j,0,n){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
            }
        }
    }
    rep(i,0,q){
        int u,v;
        cin>>u>>v;
        u--,v--;
        if(d[u][v]==inf) cout<<-1<<'\n';
        else cout<<d[u][v]<<'\n';
    }
}

int main(){ 
    // #ifndef ONLINE_JUDGE  
        // freopen("input.txt", "r", stdin); 
        // freopen("output.txt", "w", stdout); 
    // #endif 
    fastio;
    int t=1;
    // cin>>t;
    while(t--)
        solve();
    return 0;
}
