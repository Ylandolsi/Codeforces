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
template<typename... T>void print(T&&... args) {((cout << args /*<< " "*/), ...);}
template<class T> bool ckmax(T& a, const T& b){return a < b ? a = b, 1 : 0;}
template<class T> bool ckmin(T& a, const T& b){return a > b ? a = b, 1 : 0;}
template<typename F, typename S>ostream& operator <<(ostream& ostream, pair<F, S>& p) {cout << p.first << " " << p.second;return ostream;}
template<typename T>ostream& operator <<(ostream& ostream, vector<T>& v) {for(auto& element : v) {cout << element << " ";}return ostream;}
template<typename T>ostream& operator <<(ostream& ostream, vector<vector<T>>& v) {for(auto& row : v) {for(auto& cell : row) {cout << cell << " ";}cout << "\n";}return ostream;}


class Solution {
public:

     int n ;
     map<int,set<int>>indexes ; 
     vector<ll>DP , a , added  ;
     ll work ( int index  ){
          if ( index >= n  ) return  0;
          ll &ret =DP[index];  
          if ( ret != -1 ) return ret ; 

          ll choice1 = work(index+1);
          ll choice2 = 0 ; 
          if ( indexes[a[index]].size() > 1 ){
               int indi = *(indexes[a[index]].upper_bound(index)) ;
               bool found = false ;
               if  (indexes[a[index]].find(indi) != indexes[a[index]].end() ) found = true ; 
               if ( indi > index && indi < n && found ) {
                    int  add = indi - index + 1  ;
                    if ( added[indi] == 1 ) add-- ; 
                    choice2 = work( indi  ) + add ; 
               }
               

          }
          
          ret = max( choice1 , choice2 ) ;
          if ( DP[index] != DP[index+1] && DP[index] != 0 && DP[index+1] != -1  ) added[index] =  1 ;
          return ret ; 
          
     }
     void Test_Case(){
          indexes.clear();
          read(n);
          DP.resize( n + 8 , -1 ); 
          a.resize(n) , added.resize( n  + 8 , -1 ); 
          for(auto &d : a )  cin>>d;
          for ( int i = 0 ; i < n  ;i++ ) {
               indexes[a[i]].insert(i);
          }
          ll x = work(0);
          cout << *max_element(all(DP)) << endl ; 
          
          

               
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
