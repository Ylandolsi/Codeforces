#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long 
#define endl "\n"

class Solution {
public:
     
     // aorB = 1 --> B  
     // aorB = 0 --→ A:
     vector<ll>a, b;
     ll n ; 
     ll rec ( int index , int aORb , vector<vector<ll>> &dp ){
        if ( index >= n ) return 0 ;
        if ( dp[aORb][index] != 0  ) return dp[aORb][index];
        
        ll search_1 = rec( index+1 , ( aORb + 1)  % 2  , dp ) +  ( aORb == 1 ?  b[index] : a[index]  )  ; 
        ll search_2 = rec ( index +2 , ( ( aORb + 1 )  % 2) , dp ) +  ( aORb == 1 ?  b[index] : a[index] )    ;

        return dp[aORb][index] += max ( search_1 , search_2 ); 

        
     }

     void solve(){ 
        cin >> n ;
        vector<vector<ll>> dp( 2ll , vector<ll>( n+1 , 0ll ));
        a.resize(n) , b.resize(n);
        for(auto &d : a )  cin>>d;
        for(auto &d : b )  cin>>d;

        cout << max ( rec( 0 , 0 , dp ) , rec(0 , 1 , dp ) ) <<endl ;


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
      Solution sol;  
      while (t--) sol.solve();
      return 0;
 }
 
