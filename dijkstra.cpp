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
const int MAX = 1e6+5;
const ll inf=2e18;
vector<pll> a[MAX];
vll par(MAX);
vll x(MAX,inf);

void print(ll n){
    if(n!=1)
        print(par[n]);
    cout<<n<<' ';
}

void dijkstra(ll s){
    priority_queue<ll> p;
    p.push(s);
    x[s]=0;
    while(!p.empty()){
        ll v=p.top();
        p.pop();
        repll(i,0,a[v].size()){
            ll d=a[v][i].F;
            ll w=a[v][i].S;
            if(x[v]+w<x[d]){
                x[d]=x[v]+w;
                p.push(d);
                par[d]=v;
            }
        }
    }
}

void solve(){
    ll n,m;
    cin>>n>>m;
    ll u,v,w;
    repll(i,0,m){
        cin>>u>>v>>w;
        a[u].pb({v,w});
        a[v].pb({u,w});
    }
    repll(i,1,n+1) par[i]=i;
    dijkstra(1);
    if(x[n]==inf) cout<<-1<<'\n';
    else{
        print(n);
    }
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