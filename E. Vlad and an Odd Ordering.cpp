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

     void solve(){
          ll n , k ;
          cin >> n >> k ;
          if ( k <= ceil(n/2.0))
          {
               cout << k + k-1 << endl ;
               return;
          }           
          for ( int i = 1 ; i<= log2(n) + 5 ; i++ )
          {
               ll gap = pow( 2.0 , i );
               ll start = gap/2 ; 
               ll compare = (n+start)/gap;
               if ( k <= compare )
               {
                    cout << ( start + (k-1)*gap ) << endl ;
                    return ; 
               }
               else k-= compare ;
          }

               
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
     cin >> t;
     while (t--){
          Solution sol;  
          sol.solve();
     } 
     return 0;
}
