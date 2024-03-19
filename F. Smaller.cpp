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
//   ordered_set<ll> st;
//   st.order_of_key (k) : index :  Number of items strictly smaller than k .
//   st.find_by_order(k) : K-th element in a set (counting from zero)
/* --------------Builtin Bit Functions-------------- */
// 1) __builtin_clz(x) -> returns the number of zeros at the beginning in the bit representaton of x.
// 2) __builtin_ctz(x) -> returns the number of zeros at the end in the bit representaton of x.
// 3) __builtin_popcount(x) -> returns the number of ones in the bit representaton of x.
// 4) __builtin_parity(x) -> returns the parity of the number of ones in the bit representaton of x.

//1e18 --> 2puis 60 

class Solution {
public:
     int n ;
     void Test_Case(){
          read ( n );
          vector<ll>mp1( 26 , 0 ) , mp2(26 , 0 );
          mp1[0]++ , mp2[0]++; 
          ll totalsizeofA  = 1 , totalsizeofB = 1 ;  

          for ( int i = 0  ; i < n ; i++ ){
               int type , times , firstA = 0 ;  string add ; 
               read ( type , times  , add ); 
               vector<ll>occ ( 26 ); 
               if ( type == 1  ){
                    for ( int j = 0 ; j <add.size() ; j++ )  occ[add[j]-'a']++;
                    
                    for ( int j = 0 ; j < 26 ; j++ ){
                         occ[j]*=times ;
                         mp1[j]+=occ[j];
                    }
                    totalsizeofA += times * (ll)add.size(); 
                    
                    
               }
               else {
                    for ( int j = 0 ; j <add.size() ; j++ )  occ[add[j]-'a']++;
                    
                    for ( int j = 0 ; j < 26 ; j++ ){
                         occ[j]*=times ; 
                         mp2[j]+=occ[j];
                    }
                    totalsizeofB += times * (ll)add.size(); 

               }

               bool check = false , checkalla = true ;
                
               for ( int j = 1 ; j < 26 ; j++ ){
                    if ( mp2[j] > 0 ){
                         check = true ; 
                         break ;
                    }
                    if ( mp1[j] || mp2[j] ) checkalla = false ;
               }

               if ( checkalla &&  mp1[0] < mp2[0] ) check = true ;
               

               if ( check ) cout << "Yes\n";
               else cout << "No\n";

          }
               

               
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
