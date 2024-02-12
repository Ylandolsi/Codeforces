#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long 
#define endl "\n"


class Solution {
public:
     int n , m  ;
     vector<int>a;
     Solution(){
          cin >> n >> m  ;
          a.resize(n);
     }
     void solve(){
          
          for(auto &d : a )  cin>>d;
          set<int>st ;
          int number_1 = 0 , number_2 = 0 ;
          for ( int i = 0 ; i < n ; i++ )
          {
               number_1+=a[i] == -1;
               number_2+=a[i] == -2;
               if ( a[i] > 0 ) st.insert( a[i] ) ;
          }
          int dist = st.size() , previous = 0 ;
          int ans = max ( min ( m , number_1+ dist ) , min ( m , number_2 + dist ) );
          for ( auto d : st )
          {
               int choose_left = min ( d-1 , number_1 + previous );
               int choose_right = min ( m - d , dist - ( previous + 1 )  + number_2 ) ;
               ans =  max ( ans , min ( m , choose_left + choose_right + 1 ));
               previous++;
          }
          cout << min ( ans , m ) << endl ;
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
     while (t--) {
          Solution sol; 
          sol.solve();
     } 
     return 0;
}
