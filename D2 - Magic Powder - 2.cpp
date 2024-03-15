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
#define  bts(x) __builtin_clz(x) // 32 - bts(x) if int 
#define  lbts(x) __builtin_clzll(x) // 64 - bts(x) if long long 
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
     int n , k  ;
     void Test_Case(){
          cin >> n >> k ;
          ll pr = 0 ;
          vector<ll>a(n),  b(n) ;
          vector<pi>cr_modres(n);
          for(auto &d : a )  cin>>d, pr+=d ;
          for(auto &d : b )  cin>>d;

          for ( int i = 0 ; i < n ; i++ ){
               cr_modres[i].first = b[i]/a[i];
               cr_modres[i].second = a[i] - (b[i]%a[i] ); 
          }
          
          ll high =2e9 , low = 0 ; 
          ll ans = 0 ;
          while ( low <= high ){
               ll mid =   low + (high-low)/2;
               ll needed= 0 ;
               for ( int i = 0 ; i < n ; i++ ){
                    if (cr_modres[i].first < mid  )
                    needed+= cr_modres[i].second ; 
                    ll goal = mid- 1 ;
                    if ( cr_modres[i].first < goal )
                         needed+=a[i]*(goal-cr_modres[i].first);
                    if ( needed > 1e9 ) break ; 
               }
               if ( needed <= k && needed >= 0   ){
                    ans = max(mid,ans) ;
                    low = mid + 1 ;
               }
               else high = mid - 1 ;

          }
          cout << ans <<endl ;
          

               
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
     //cin >> t;
     while (t--){
          Solution sol;  
          sol.Test_Case();
     } 
    return 0;
}
