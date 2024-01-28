#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define FIO cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
//#define int long long 
#define vt vector<int>
#define takevect(vect) for(auto &mooo : vect ){cin>>mooo;}
#define takevect1 (vect) for( int i = 1 ; i <= x ;i++)cin>>vect[i];
typedef pair<int,pair<int,int>> tup;
typedef pair<int,int> pi;
#define endl "\n"
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define all(doo) doo.begin(), doo.end()
#define sortt(doo) sort(all(doo))
#define unq(vt)  vt.erase(unique(all(vt)), vt.end())
#define rev(doo)   reverse (all(doo)) 
#define lb lower_bound
#define up upper_bound
int gcd(int a , int b) {return b ? gcd(b , a % b) : a ;}
int lcm(int a , int b) {return (a * b) / gcd(a , b);}
#define forr(i, doo, y)   for(int i = doo; i <= y; i++)
#define forrb(i, doo, y)   for(int i = doo; i >= y ; i--)

#ifndef ONLINE_JUDGE           
#define dbg(doo) cerr << #doo<< " " ;  _print(doo) ;  cerr << endl;
#endif

void _print(auto t) {cerr << t;}
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
template<class T> bool ckmax(T& a, const T& b){return a < b ? a = b, 1 : 0;}
template<class T> bool ckmin(T& a, const T& b){return a > b ? a = b, 1 : 0;}

class Solution {
public:
     int n ; 
     vector<vector<int>>graph;
     vector<set<int>>answer;
     bool visit[120];
     
      
     void dfs(int x ){
          for ( auto child : graph[x]) {
               if ( !visit[child]){
                    dfs(child);
               }
               for ( auto o : answer[child]){
                    answer[x].insert(o);
               }
          }
          visit[x]=true;
          answer[x].insert(x+1);
     }
     
     void solve(){
          cin >> n ;
          graph.clear(); answer.clear();
          graph.resize(n);
          answer.resize(n);
          vector<vector<int>>a(n,vector<int>(n,0));
          memset(visit, 0 , sizeof(visit));
          
          for ( int i = 0 ; i < n ; i++ ){
               for ( int j = 0 ; j  < n ; j++ ){
                    char x ; cin >> x ;
                    a[i][j] = x-'0';
                    if ( a[i][j] == 1){
                         graph[j].pb(i);
                    }
               }
          }

          for ( int i = 0 ; i < n ; i++ ) {
               if ( !visit[i]) dfs(i);
          }
          for ( auto d : answer ){
               cout<<d.size()<< " ";
               for ( auto f : d ){
                    cout<<f<<" ";
               }
               cout<<endl ;
          }
     }

};

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        freopen("err.txt", "w", stderr);
    #endif
    int t = 1;
    cin >> t;
    Solution sol;  
    while (t--) sol.solve();
    return 0;
}
