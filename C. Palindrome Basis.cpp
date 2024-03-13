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
ll modInverse(ll a , ll modd) {return a <= 1 ? a : modd - (ll)(modd/a) * modInverse(modd % a , modd) % modd;}
bool sortinc(pi &a,pi &b){ if ( a.second == b.second ) return a.first < b.first ;  else  (a.second < b.second);}
bool sortdec(pi &a,pi &b){ if ( a.second == b.second ) return a.first > b.first ;  else  (a.second > b.second);}
ll mceil( ll a , ll b ) { return (a+b-1)/b ; }
template<class T> bool ckmax(T& a, const T& b){return a < b ? a = b, 1 : 0;}
template<class T> bool ckmin(T& a, const T& b){return a > b ? a = b, 1 : 0;}
ordered_set<ll> st;
//order_of_key (k) : index :  Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero)

vector<vector<int>>dp   ;
const ll mod = 1e9 + 7 ;
bool ispalin( string s)
{
     int l = 0 ,r = s.size() - 1 ;
     bool ret = 1 ;
     while( l < r )
     {
     if( s[l] != s[r] ){ ret = 0 ; break ; }
     l++ ; r-- ;
     }
     return ret;
}


int32_t main() {
     cout << fixed << setprecision(2) ;
     i_love_binary_search 

     cin >> t;
     vector<int>pal ; 
     for( int i = 2 ; i <= 4e4 ; i++ ){
          string s = to_string(i);
          if ( ispalin(s))  pal.pb(i);
     }
     int sz =  pal.size();
     dp.resize( sz +8  , vector<int>(4e4 + 10 ) );

     for ( int i = 0 ; i <= 4e4+ 5 ; i++ ) dp[0][i]=1;
     for ( int i = 0 ; i <= sz ; i++ ) dp[i][0]=1;
     
     for ( int i = 1 ; i <= sz ; i++ )
     {
          int x = pal[i-1];
          for ( int j = 1 ; j <= 4e4 +1 ; j++ ) 
          {
               if ( x > j ) dp[i][j] = dp[i-1][j] % mod ;
               else dp[i][j]= dp[i-1][j] % mod  + dp[i][j-x] % mod  ;
          }
     }

     while (t--){
          int inp ; cin >> inp ;
          cout << dp[sz][inp]<<endl;
     } 
    return 0;
}
