#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long 
typedef pair<ll,pair<ll,ll>> tup;
typedef pair<ll,ll> pi;
#define endl "\n"
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))
#define unq(vt)  vt.erase(unique(all(vt)), vt.end())
#define rev(x)   reverse (all(x)) 
template<class T> bool ckmax(T& a, const T& b){return a < b ? a = b, 1 : 0;}
template<class T> bool ckmin(T& a, const T& b){return a > b ? a = b, 1 : 0;}

class Solution {
public:
     int n ;
     map<int , ll > mp ; 
     int lastNum =  1   , firstnum = 1e6 ;
     vector<ll>dpR;

     /*          RECURSIVE METHOD             */
     ll work ( ll x )
     {
          if ( x > lastNum ) return 0 ;
          if ( dpR[x] != 0 ) return dpR[x];
          

          ll check_1 = work(x+2) + mp[x];
          ll check_2 = max ( check_1 , work(x+1) ) ;

          return dpR[x] = max ( check_1 , check_2 );

      }
     void solve(){
          cin >> n ; 
          dpR.resize(2e5 , 0 );
          for ( int i = 0 ; i < n ; i++ )
          {
               int x ; cin >> x ;
               mp[x]++;
               lastNum = max(lastNum , x );
               ckmin(firstnum , x);
          }
          for ( auto &d : mp ) mp[d.first] = d.first * d.second ; 


          /*        ITERATIVE METHOD         */
          vector<ll>dp( 2e5 ,  0);
          for ( int i = lastNum ; i >= 1 ; i-- )
          {
               dp[i] = mp[i] +(  i + 2 <= lastNum ? dp[i + 2 ] : 0 ) ;
               dp[i] = max( dp[i] , (( i + 1 <= lastNum )? dp[i+1] : 0 ));
          }
          //cout << *max_element(all(dp)) << endl ;
          
          
          ll f = work(firstnum);
          
          cout << f << endl ;
   
     }
     
};

signed main() {
     SPEED;
     #ifndef ONLINE_JUDGE
          freopen("inp.txt", "r", stdin);
          freopen("out.txt", "w", stdout);
          freopen("err.txt", "w", stderr);
     #endif
     int t = 1;
     // cin >> t;
     while (t--){
          Solution sol;  
          sol.solve();
     } 
     return 0;
}
