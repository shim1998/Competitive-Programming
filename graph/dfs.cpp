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

//Solution for Codechef FIRESC

vvi a;
vb vis;
int ctr;

void dfs(int v){
    vis[v]=1;
    ctr++;
    for(int u:a[v]){
        if(!vis[u]){
            dfs(u);
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    vis=vb(n,0);
    a=vvi(n);
    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        u--,v--;
        a[u].pb(v);
        a[v].pb(u);
    }
    ll ans=1,ans2=0;
    rep(i,0,n){
        if(!vis[i]){
            ctr=0;
            dfs(i);
            ans2=(ans2+1)%MOD;
            ans=(ans*ctr)%MOD;
        }
    }
    cout<<ans2<<' '<<ans<<'\n';
}

int main(){ 
    // #ifndef ONLINE_JUDGE  
        // freopen("input.txt", "r", stdin); 
        // freopen("output.txt", "w", stdout); 
    // #endif 
    fastio;
    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
