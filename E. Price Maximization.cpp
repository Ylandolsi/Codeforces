#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long 
#define endl "\n"
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))
#define unq(vt)  vt.erase(unique(all(vt)), vt.end())
#define rev(x)   reverse (all(x)) 

class Solution {
public:
     int n , k ;
     void solve(){
        ll ans = 0 ; 
        cin >> n >> k ;   
        vector<ll>a(n);
        for(int i = 0 ; i < n ; i++ )
        {
            int x ; 
            cin >> x; 
            ans+= x / k ;
            a[i] = x % k ;
        
        }
        sortt(a);
        int l = 0 , r = n-1 ; 
        while ( l < r )
        {
            int end = a[r];
            int first = a[l];
            if ( ( end + first ) / k == 1 ) {
                l++;
                r--;
                ans++;
            }
            else l++;
        } 
        cout << ans <<endl;
             
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
