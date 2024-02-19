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

class Solution{
public :
     
     void solve(){
          int n;
               cin >> n;
          
          vector<unsigned int >a(n);
          for(int i = 0; i < n; ++i)
               cin >> a[i];
          map<unsigned int , int > mp ;
          for ( int i = 0 ; i <n ; i++ )
          {
               unsigned int inverse = ~a[i] - 2147483648;
               mp[inverse]++ ;
          }
          int ans = n ;
          for ( int i = 0 ; i < n ; i++ )
          {
               unsigned int inverse = ~a[i] - 2147483648;
               if ( mp[a[i]]>0 && mp[inverse]>0 )
               {
                    mp[a[i]]-- ;
                    
                    mp[inverse]-- ;
                    ans--;
               }
          }
          cout << ans <<endl ;
          
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
