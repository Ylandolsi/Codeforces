#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long 


class Solution {
public:
 
    void solve()
    {
        int n , x , y ;
        cin>> n >> x >> y ;
        vector<int> a(n+1) ;
        map<pair<int,int>,int> mp ;
        ll ans = 0 ;
        for(int i = 1 ; i<=n ; i++){
            cin>>a[i] ;
            pair<int,int> p= make_pair((x - a[i]%x)%x , a[i] %y) ;
            ans += mp[p] ;
            p = make_pair( a[i]%x , a[i] %y) ;
            mp[p]++ ;
        }
        cout<<ans<<endl;
          
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








