#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long 
typedef pair<ll,pair<ll,ll>> tup;
typedef pair<ll,ll> pi;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#endif
#define endl "\n"
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))
#define unq(vt)  vt.erase(unique(all(vt)), vt.end())
#define rev(x)   reverse (all(x)) 
template<class T> bool ckmax(T& a, const T& b){return a < b ? a = b, 1 : 0;}
template<class T> bool ckmin(T& a, const T& b){return a > b ? a = b, 1 : 0;}





class Solution {
public:
     int n  , ct = 0;
     void solve(){
          cin >> n ;
          vector<int>a(n) , answer ;
          for(auto &d : a )  cin>>d;
          sortt(a);
          int mid = n/2 ;
          int index = 0 ;
          while ( mid < n ){
               answer.pb(a[mid++]);
               if ( index <= ( n /2 -1 ) ) answer.pb(a[index++]) ;
          }

          for ( int i = 1 ; i < n -1 ; i++ )
               ct += answer[i] < answer[i-1] && answer[i] < answer[i+1];

          cout << ct << "\n";
          for ( auto d : answer) cout << d << " ";
          cout << "\n";

               
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
     while (t--){
          Solution sol;  
          sol.solve();
     } 
     return 0;
}
