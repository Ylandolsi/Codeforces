#include <bits/stdc++.h>
using namespace std ; 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define pb push_back
#define i_love_binary_search  cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0) ; 
typedef long long ll ;
typedef pair<ll,pair<ll,ll>> tup;
typedef pair<ll,ll> pi;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#endif
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))
#define getunique(vt)  vt.erase(unique(all(vt)), vt.end())
#define rev(x)   reverse (all(x)) 
#define Sum(x) accumulate( x.begin() , x.end() , 0ll ) 
#define  ibits(x) 32 - __builtin_clz(x) // 32 - bts(x) if int 
#define  lbits(x) 64 -  __builtin_clzll(x) // 64 - bts(x) if long long 
ll modInverse(ll a , ll modd) {return a <= 1 ? a : modd - (ll)(modd/a) * modInverse(modd % a , modd) % modd;}
bool sortinc(pi &a,pi &b){ if ( a.second == b.second ) return a.first < b.first ;  else  return a.second < b.second;}
bool sortdec(pi &a,pi &b){ if ( a.second == b.second ) return a.first > b.first ;  else  return a.second > b.second;}
ll mceil( ll a , ll b ) { return (a+b-1)/b ; }
template<typename... T>void read(T&... args) {((cin >> args), ...);}
template<typename... T>void print(T&&... args) {((cout << args /*<< " "*/), ...);}
template<class T> bool ckmax(T& a, const T& b){return a < b ? a = b, 1 : 0;}
template<class T> bool ckmin(T& a, const T& b){return a > b ? a = b, 1 : 0;}
template<typename F, typename S>ostream& operator <<(ostream& ostream, pair<F, S>& p) {cout << p.first << " " << p.second;return ostream;}
template<typename T>ostream& operator <<(ostream& ostream, vector<T>& v) {for(auto& element : v) {cout << element << " ";}return ostream;}
template<typename T>ostream& operator <<(ostream& ostream, vector<vector<T>>& v) {for(auto& row : v) {for(auto& cell : row) {cout << cell << " ";}cout << "\n";}return ostream;}


void Test_Case() {
     int n  , m  , cte = 0  , totalpushed = 0  ;
     read( n ,  m ) ;
     vector<vector<int>>graph( n + 10 );
     vector<bool>vis ( n + 10 ) ; 
     vector<set<int>>answer  ;
     set<int> without , st , inter   ; 

     for ( int i = 0 ; i < m ; i++ ){
          int a  , b  ;
          read ( a , b ); 
          graph[a].pb(b);
          graph[b].pb(a);
          inter.insert(a), inter.insert(b);
     }
     for ( int i = 1 ; i <= n  ; i++ )without.insert(i);
     for ( auto d :inter) without.erase(d);
     inter.clear();

     
     function <void(int)> dfs = [&] ( int x ){
          if ( vis[x]) return ; 
          cte++ ; 
          st.insert(x);
          vis[x] =  1 ; 
          for ( int i = 0 ; i < graph[x].size() ; i++ )  dfs(graph[x][i]);
          
     };
     
     for  ( int i = 1 ; i <= n ;i++  ){
          if ( vis[i]) continue; ; 
          st.clear();
          cte = 0 ; 
          dfs(i);
          if ( cte > 3   ){
               cout << -1 << endl ; 
               return ; 
          }
          
          if ( st.size() > 1  ) answer.pb(st) , totalpushed += st.size();
  
     }
     for ( int i = 0 ; i < answer.size() ; i++ ){
          inter.clear();
          if  ( answer[i].size() < 3 ){
               for ( auto d : without){
                    if ( answer[i].find(d) != answer[i].end()) continue; 
                    answer[i].insert(d);
                    totalpushed++ ;
                    inter.insert(d); 
                    if (answer[i].size() ==  3) break ; 
               }
          }
          for ( auto d : inter ) without.erase(d);
               
          
     }
     
     inter.clear();
     for ( auto d : without ){
          inter.insert(d);
          if ( inter.size() == 3 ){
               answer.pb(inter);
               totalpushed+= 3 ; 
               inter.clear();
          }
     }

     if ( totalpushed != n || answer.size() > n/3  ){ print(-1 , "\n"); return ; }

     for ( int i = 0 ; i < n/3 ; i++ ){
          for ( auto d : answer[i]) print ( d ," ");   
          print ( "\n");
     }     
}




int32_t main() {
     cout << fixed << setprecision(2) ;
     i_love_binary_search 
     #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        freopen("err.txt", "w", stderr);
     #endif
     int t = 1;
     Test_Case();
     
     return 0;
}
