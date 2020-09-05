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
const ll inf = 2e18+2;
vp a[200005];
vll d;

//Solution for CSES 1671

void dijkstra(int s,int n){
    d[s]=0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({s,0});
    while(!q.empty()){
        int v=q.top().F;
        int d_v=q.top().S;
        q.pop();
        if(d_v!=d[v]) continue;
        for(auto edge:a[v]){
            int to=edge.F;
            int len=edge.S;
            if(d[v]+len<d[to]){
                d[to]=d[v]+len;
                q.push({to,d[to]});
            }
        }
    }
}
 
void solve(){
    int n,m;
    cin>>n>>m;
    d=vll(n,inf);
    rep(i,0,m){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        a[u].pb({v,w});
    }
    dijkstra(0,n);
    rep(i,0,n) cout<<d[i]<<' ';
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
