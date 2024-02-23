#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long 


class Solution {
public:
     int n , ans = 0 , zeros = 0;
     void solve(){
          cin >> n ;
          vector<int>a(n) , ones;
          for(auto &d : a )  cin>>d;
          for ( int i = 0 ; i < n ; i++ ){
               if ( a[i] == 1) ones.pb(i);   
          }
          
          if ( ones.back() - ones[0] + 1 == ones.size() )
          {
               cout << 0 << endl ;
               return ;
          }
          for ( int i = ones[0]; i < n  ;i++ )
          {
               if ( a[i] == 0)zeros++;
               else 
               {
                    ans+=zeros;
                    zeros=0;
               }
          }
          cout << ans << endl ;
          
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
