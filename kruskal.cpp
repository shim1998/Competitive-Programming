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

vector<pair<int,pii>> a;
vi r,parent;

void make_set(int v){
    parent[v]=v;
    r[v]=0;  
}

int find_set(int v){
    if(v==parent[v])
        return v;
    return parent[v]=find_set(parent[v]);
}

void union_sets(int a,int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(r[a]<r[b])
            swap(a,b);
        parent[b]=a;
        if(r[a]==r[b])
            r[a]++;
    }
}

bool comp(pair<int,pii> a,pair<int,pii> b){
    if(a.S.S<b.S.S) return 1;
    return 0;
}

ll kruskal(){
    ll cost=0;
    for(auto i:a){
        if(find_set(i.F)!=find_set(i.S.F)){
            cost+=i.S.S;
            union_sets(i.F,i.S.F);
        }
    }
    return cost;
}

void solve(){
    int n,m;
    cin>>n>>m;
    a=vector<pair<int,pii>>(n);
    r=vi(n);
    parent=vi(n);
    rep(i,0,n) make_set(i);
    int u,v,w;
    rep(i,0,m){
        cin>>u>>v>>w;
        u--,v--;
        a.pb({u,{v,w}});
    }
    sort(all(a),comp);
    cout<<kruskal()<<'\n';
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