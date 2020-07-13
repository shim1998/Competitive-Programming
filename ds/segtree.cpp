/*Made by Shivam Solanki*/
#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
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

vll segtree;

int init(int n,int size){
   while(size<n) size*=2;
   segtree.assign(2*size,0LL);
   return size;
}

void build(vi &a,int x,int lx,int rx){
   if(rx-lx==1){
      if(lx<(int)a.size()) segtree[x]=a[lx];
   }
   else{
      int m=(lx+rx)/2;
      build(a,x*2+1,lx,m);
      build(a,x*2+2,m,rx);
      segtree[x]=segtree[x*2+1]+segtree[x*2+2];
   }
}

void update(int i,int v,int x,int lx,int rx){
   if(rx-lx==1) segtree[x]=v;
   else{
      int m=(lx+rx)/2;
      if(i<m) update(i,v,2*x+1,lx,m);
      else update(i,v,2*x+2,m,rx);
      segtree[x]=segtree[x*2+1]+segtree[x*2+2];
   }
}

ll sum(int l,int r,int x,int lx,int rx){
   if(lx>=r||l>=rx) return 0;
   if(lx>=l&&rx<=r) return segtree[x];
   int m=(lx+rx)/2;
   return sum(l,r,x*2+1,lx,m)+sum(l,r,x*2+2,m,rx);
}

void solve(){
   int n,m;
   cin>>n>>m;
   int size=init(n,1);
   vi a(n);
   rep(i,0,n) cin>>a[i];
   build(a,0,0,size);
   int o,l,r;
   while(m--){
      cin>>o>>l>>r;
      if(o==1) update(l,r,0,0,size);
      else cout<<sum(l,r,0,0,size)<<'\n';
   }
}

int main(){ 
   // #ifndef ONLINE_JUDGE  
      // freopen("input.txt", "r", stdin); 
      // freopen("output.txt", "w", stdout); 
   // #endif 
   fastio;
   int t=1;
   //cin>>t;
   while(t--)
      solve();
   return 0;
}
