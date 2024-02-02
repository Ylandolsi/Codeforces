#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define int long long 
typedef pair<int,pair<int,int>> tup;
typedef pair<int,int> pi;
#define endl "\n"
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))
#define unq(vt)  vt.erase(unique(all(vt)), vt.end())
#define rev(x)   reverse (all(x)) 

class Solution {
public:
     void solve(){
          int n , ans = 0 , mi = 1e10 , firstlucky , indexoffirst   ;
          cin >> n ; 
          vector<int> a ( n ) ;
          for(auto &d : a )  cin>>d;
          for ( int i = 1 ; i < n ;i++ ){
               mi = min ( a[i-1] , mi );
               if ( a[i] > mi ) {
                    firstlucky = a[i] ;
                    indexoffirst = i ;
                    ans++;
                    break ; 
               }
          }
          for ( int i = indexoffirst ; i < n ;i++ ){
               ans += a[i] < firstlucky && a[i] > mi  ; 
               firstlucky =  a[i] < firstlucky  && a[i] > mi  ? min (  a[i],firstlucky ) : firstlucky ; 
               mi = min (mi ,a[i]);
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
    Solution sol;  
    while (t--) sol.solve();
    return 0;
}
