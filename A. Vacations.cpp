#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define endl "\n"

class Solution {
public:
     int n ; 
     vector<int> A; 
     int DP[5][101];
     int Best ( int i , int prev ) 
     {
          if ( i == n ) return 0 ; 
          int &res = DP[prev][i] ;
          if ( i &&  res != -1 ) return res ; 
          if ( i && A[i] == prev || A[i] == 0 ) res = 1 + Best ( i + 1 , 0 ) ; 
          else if ( A[i] == 3 ) 
          {
               int FirstC = ( i && prev == 1 ? 1 : 0 ) + Best( i + 1 , 1 ) ; 
               int SecC = ( i && prev == 2 ? 1 : 0 ) + Best( i + 1 , 2 ) ; 
               res = min( FirstC , SecC ) ; 
          }
          else res = Best( i + 1 , A[i] ) ; 
          return res ; 
     }
     void solve()
     {
          cin >> n ; 
          for ( int i = 0 ; i < 4 ; i++ ){
               for ( int j = 0 ; j < n  ; j++ ) DP[i][j]=-1;
          }
          A.resize(n) ;
          for ( auto &d : A) cin >> d ;
          int Result = Best ( 0 , A[0] ) ; 
          cout << Result << endl ; 
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
     //cin >> t;
     Solution sol;  
     while (t--) sol.solve();
     return 0;
}
