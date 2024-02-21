#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long 
#define endl "\n"
#define all(x) x.begin(), x.end()



class Solution {
public:
     ll n , x , p ;
     void solve(){
          cin >> n >> x >> p  ;
          for ( ll i = 1 ; i <= min ( 2 * n + 9 , p ) ; i++)
          {
               ll m = ( i - 1 )*i / 2 ;
               ll ans = ( x + (i*i - m) )% n;
               if ( ans  == 0 ){
                    puts("Yes");
                    return;
               }
          }
          puts("No");
          

               
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
