/*Made by Shivam Solanki*/
#include<bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define ll long long int
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
typedef priority_queue<int> pq;
typedef unordered_map<int,int> umii;
typedef unordered_map<ll,ll> umll;
typedef queue<int> qii;
#define rep(i,k,n) for (int i = k; i < n; ++i) 
#define repr(i,k,n) for (int i = n; i>=k; --i)
#define REP(i,k,n) for (int i = k; i <= n; ++i) 
#define REPR(i,k,n) for (int i = k; i >= n; --i)
#define repll(i,k,n) for (ll i = k; i < n; ++i) 
#define pb push_back
#define mp make_pair
#define gcd __gcd
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 1e9+5;
const int MOD = 1e9+7;
const int MAX = 1e4+5;

vector<pll> a[MAX];
vb vis(MAX);

ll prim(int x){
    ll cost=0;
    priority_queue<pll,vector<pll>,greater<pll>>q;
    int y;
    pll p;
    q.push({0,x});
    while(!q.empty()){
        p=q.top();
        q.pop();
        x=p.S;
        if(vis[x]) continue;
        cost+=p.F;
        vis[x]=1;
        for(int i=0;i<a[x].size();i++){
            y=a[x][i].S;
            if(!vis[y]){
                q.push(a[x][i]);
            }
        }
    }
    return cost;
}

void solve(){
    int n,m;
    cin>>n>>m;
    int u,v,w;
    rep(i,0,m){
        cin>>u>>v>>w;
        u--,v--;
        a[u].pb({w,v});
        a[v].pb({w,u});
    }
    cout<<prim(0)<<'\n';
}
    
int main(){
    // #ifndef ONLINE_JUDGE  
        // freopen("input.txt", "r", stdin); 
        // freopen("output.txt", "w", stdout); 
    // #endif 
    // fastio;
    int t=1;
    // cin>>t;
    while(t--)
        solve();
    return 0;
}