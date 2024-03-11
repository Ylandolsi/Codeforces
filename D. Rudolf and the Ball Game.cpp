#include <bits/stdc++.h>
using namespace std ; 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
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



class Solution {
public:
     int n , m , k  ;
     set<int>st;
     vector<pair<int,char>>a;
     vector<vector<int>>dp;
     void work(int index  ,  int towho  ){
          if ( index >= m  ){
               st.insert(towho);
               return ;
          }

          if(dp[towho][index] != -1 ){
               return ;
          }

          char direc = a[index].second ; 
          int plus  = ( a[index].first + towho ) % n  ;
          int inte = towho - a[index].first ; 
          if ( inte < 0 ) inte = n - abs(inte);
               
          if ( direc == '?'){
               work(index+1 , plus);
               work(index+1 , inte);
               dp[towho][index] = 1  ;      
          }
          else {
               if ( direc == '0'){
                    work(index+1 , plus);
                    dp[towho][index] = 1  ;   
               }
               else {
                    work(index+1 , inte);
                    dp[towho][index] = 1  ;  
               }
               
          }
          return ; 
     }

     void solve(){
          cin >> n >> m >> k ;
          int maxi = max( n , m ) ;
          dp.resize(maxi+8 , vector<int> ( maxi+8 ,  -1  ));
          a.resize(m);
          for ( int i = 0 ; i < m ; i++ ){
               char y ; int x ; 
               cin >> x >>y ;
               a[i]={x,y};
          }
          work(0,k-1);
          cout << st.size()  << endl ; 
          for ( auto d :st)
               cout << d+1 <<" ";
          
          cout << endl; 
                     
     }
     
};



int32_t main() {
     cout << fixed << setprecision(2) ;
     SPEED;
     #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        freopen("err.txt", "w", stderr);
     #endif
     int t = 1;
     cin >> t;
     while (t--){
          Solution sol;  
          sol.solve();
     } 
    return 0;
}
