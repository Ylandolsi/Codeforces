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
          int n ;
          cin >> n ;
          vector<pi>a(n) ;
          ll toRight = 0 , toLeft = 0  ;
          for ( int i= 0 ; i < n ; i++ )
          {
               cin >> a[i].first ;
               a[i].second = i ; 
               toRight+=a[i].first;
          }
          sortt(a);
          vector<ll>answer(n);
          for ( int i = 1 ; i <= n ;i++)
          {
               toRight -= a[i-1].first;
               toLeft += a[i-1].first;   
               answer[a[i-1].second] = n + a[i-1].first * (2ll*i - n) - toLeft + toRight;
          }
          for ( int i = 0 ; i < n  ; i++ )
               cout << answer[i] << " " ;
          cout << endl ;

     }
     
};

int main() {
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
