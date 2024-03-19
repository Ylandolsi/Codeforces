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
#define  ibits(x) 32 - __builtin_clz(x) // 32 - bts(x) if int 
#define  lbits(x) 64 -  __builtin_clzll(x) // 64 - bts(x) if long long 
ll modInverse(ll a , ll modd) {return a <= 1 ? a : modd - (ll)(modd/a) * modInverse(modd % a , modd) % modd;}
bool sortinc(pi &a,pi &b){ if ( a.second == b.second ) return a.first < b.first ;  else  (a.second < b.second);}
bool sortdec(pi &a,pi &b){ if ( a.second == b.second ) return a.first > b.first ;  else  (a.second > b.second);}
ll mceil( ll a , ll b ) { return (a+b-1)/b ; }
template<typename... T>void read(T&... args) {((cin >> args), ...);}
template<typename... T>void write(T&&... args) {((cout << args /*<< " "*/), ...);}
template<class T> bool ckmax(T& a, const T& b){return a < b ? a = b, 1 : 0;}
template<class T> bool ckmin(T& a, const T& b){return a > b ? a = b, 1 : 0;}
template<typename F, typename S>ostream& operator <<(ostream& ostream, pair<F, S>& p) {cout << p.first << " " << p.second;return ostream;}
template<typename T>ostream& operator <<(ostream& ostream, vector<T>& v) {for(auto& element : v) {cout << element << " ";}return ostream;}
template<typename T>ostream& operator <<(ostream& ostream, vector<vector<T>>& v) {for(auto& row : v) {for(auto& cell : row) {cout << cell << " ";}cout << "\n";}return ostream;}
ordered_set<ll> st;
//   st.order_of_key (k) : index :  Number of items strictly smaller than k .
//   st.find_by_order(k) : K-th element in a set (counting from zero)
/* --------------Builtin Bit Functions-------------- */
// 1) __builtin_clz(x) -> returns the number of zeros at the beginning in the bit representaton of x.
// 2) __builtin_ctz(x) -> returns the number of zeros at the end in the bit representaton of x.
// 3) __builtin_popcount(x) -> returns the number of ones in the bit representaton of x.
// 4) __builtin_parity(x) -> returns the parity of the number of ones in the bit representaton of x.


class Solution {
public:
     ll n   , m  ;
     void Test_Case(){
          read( n , m ) ; 
          vector<ll>a(n) , b(n) , prefb(n);
          vector<ll>dp(n+5);
          for(auto &d : a )  cin>>d;
          for(auto &d : b )  cin>>d;
          
          ll index = n-1 ; 
          m-- ; 
          ll ans = 0 ; 
          for ( int i = n - 1 ; i >= 0 ; i-- ){
               if ( i == m ) {
                    index = i ; 
                    break ; 
               }
               ans+= min( a[i] , b[i]); 
          }
          ll fians = 1e18 ; 
          for ( int i = index  ; i >= 0 ; i-- ) {
               fians = min ( fians , ans + a[i]) ;
               ans+=min(a[i] , b[i]);
          }
          
          cout << fians << endl ;

               
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
