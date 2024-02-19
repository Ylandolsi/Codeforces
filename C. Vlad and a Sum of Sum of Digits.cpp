#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long 
#define endl "\n"


const int N = 2e5 + 10 ; 
vector<ll>answer( N , 0 );

ll work ( int x )
{
     ll res = 0;
     while ( x )
     {
          res+=x%10;
          x/=10;

     }
     return res ;

}


class Solution{
public :
     
     void solve()
     {
          int n ;
          cin >> n ;
          cout << answer[n]<<endl ;
     
     }
     
};

signed main() {
     SPEED;
     #ifndef ONLINE_JUDGE
          freopen("inp.txt", "r", stdin);
          freopen("out.txt", "w", stdout);
          freopen("err.txt", "w", stderr);
     #endif
     for ( int i = 1 ; i <= N ; i++ )
          answer[i] = answer[i-1] + work(i);
     
     int t = 1;
     cin >> t;
     while (t--){
          Solution sol;  
          sol.solve();
     } 
     return 0;
}
