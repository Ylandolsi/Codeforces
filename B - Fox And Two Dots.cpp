#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define pb push_back
#define FIO cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long 
#define vt vector<ll>
typedef pair<ll, pair<ll, ll>> tup;
typedef pair<ll, ll> pi;
//#define mat vector<vector<ll>>
#define endl "\n"
#define F first
#define S second
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define all(left) left.begin(), left.end()
#define sortt(left) sort(all(left))
#define unq(vt)    vt.erase(unique(all(vt)), vt.end())
#define rev(aa)      reverse ( all(aa) )
#define co      cout <<
#define inp(left) cin >> left
#define espace cout << " "
#define line cout << endl
#define INF 2e18 
#define takevect(left) for (auto &d : left) cin >> d;
#define takevect1(x) for( int i = 1 ; i<= n ; i++ ) cin>>x[i];
#define fo(j, right,h) for (int i = j; i < right; j+=h)
#define sumtot(x) accumulate(all(x),(ll)0)
#define mapi map<ll,ll>
#define read(x) int x; cin >> x
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}

#ifndef ONLINE_JUDGE           
#define dbg(x) cerr << #x<< " " ;  _print(x) ;  cerr << endl;
#endif
void _print( auto t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }

const int N = 55 ;
vector<int>graph[N];
bool vis[N][N];
char a[N][N];
int cte = 0  , n , m  , parentx , parenty ; 
bool cycl = 1 ;
bool move(int i , int j , char comp){
    return i>= 0 && j>= 0 && i< n && j < m && a[i][j] == comp;
}
const int dx[] = {1 , -1 , 0 , 0 };
const int dy[] = {0 , 0 , 1 , -1};

void dfs(int x , int y , char color ){
    cte++;
    vis[x][y]=1;
    for ( int i = 0 ; i < 4 ; i++ ){
        int xi = dx[i]+x , yi = dy[i]+y;
        if ( move(xi,yi ,color) ){
            if ( xi==parentx && yi==parenty && vis[xi][yi] == 1 && cte > 2){
                cycl=0;
            }
            if ( !vis[xi][yi] ) dfs(xi,yi,color);
        }
    }
    cte--;
    

}
void solve(){
    cin >> n >> m ;
    for ( int i = 0 ; i < n ; i++ ){
        for ( int j =0 ;  j < m ; j++ ){
            cin>>a[i][j];
        }
    }
    
    for ( int i = 0 ; i < n ; i++ ){
        for ( int j = 0 ; j < m ; j++ ){
            memset(vis,0,sizeof(vis));
            cycl=1;
            cte = 0 ;
            parentx=i,parenty=j;
            dfs(i,j,a[i][j]);
            if ( cycl == 0 ){
                yes;return;
            }

        }
    }
    no;


     
} 

signed main() {
    FIO;
    cout<<fixed<<setprecision(14);
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        freopen("err.txt", "w", stderr);
    #endif
    int test = 1 ;//cin>>test;
    while ( test -- ) solve();
    return 0;
}

