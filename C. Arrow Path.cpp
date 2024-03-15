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
#define  bts(x) __builtin_clz(x)
#define  lbts(x) __builtin_clzll(x)
ll modInverse(ll a , ll modd) {return a <= 1 ? a : modd - (ll)(modd/a) * modInverse(modd % a , modd) % modd;}
bool sortinc(pi &a,pi &b){ if ( a.second == b.second ) return a.first < b.first ;  else  (a.second < b.second);}
bool sortdec(pi &a,pi &b){ if ( a.second == b.second ) return a.first > b.first ;  else  (a.second > b.second);}
ll mceil( ll a , ll b ) { return (a+b-1)/b ; }
template<class T> bool ckmax(T& a, const T& b){return a < b ? a = b, 1 : 0;}
template<class T> bool ckmin(T& a, const T& b){return a > b ? a = b, 1 : 0;}
ordered_set<ll> st;
//order_of_key (k) : index :  Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero)




class Solution {
public:
     int n ;
     vector<vector<int>>grr ; 
     vector<vector<int>>visited ; 
     int di[4]={-1,0,1,0};
     int dj[4]={0,1,0,-1};

     bool canMove(int i, int j){
          return i>-1 && i<n && j>-1 && j<2;
     }
     bool flag = 0 , firstmove = 0 ;
     void dfs( int i , int j ) {

          if ( visited[i][j] == 1  ) return ; 
          visited[i][j] = 1 ;
 
          if ( j == n-1 && i == 1){
               flag = 1; 
               return ; 
          }
          if ( grr[i][j] == 0 && firstmove == 1  ) return ;
          if ( firstmove ) j++ ; 
          if ( j == n-1 && i == 1){
               flag = 1; 
               return ; 
          }
          firstmove = 1 ; 
          
          for ( int ind = 0 ; ind < 4 ; ind++ ){
               int x = j+di[ind];
               int y = i+dj[ind];
               if ( canMove(x,y) ) dfs(y,x);

          }
     }

     void Test_Case(){
          cin >> n ;
          grr.resize( 3 , vector<int>( n+5 , 0 )) ;
          visited.resize( 3 , vector<int>( n+5 , 0 )) ;
          string s1  , s2 ; cin >> s1 >> s2 ;
          for ( int i = 0 ; i < n ; i++ ){
               grr[0][i] = s1[i] == '>' ?  1 : 0 ;
               grr[1][i] = s2[i] == '>' ?  1 : 0 ;
          }          
          dfs(0,0);
          if ( flag == 1 ){
               cout << "YES"<<endl ;
          }
          else cout <<"No"<<endl;

               
     }
     
};



int32_t main() {
     cout << fixed << setprecision(2) ;
     i_love_binary_search 
     #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        freopen("err.txt", "w", stderr);
     #endif
     int t = 1;
     cin >> t;
     while (t--){
          Solution sol;  
          sol.Test_Case();
     } 
     return 0;
}
