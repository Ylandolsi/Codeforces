#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long 
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#endif
#define endl "\n"
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))




class Solution {
public:
    
    
    void solve(){
       int n ; cin >> n ;
       vector<ll>a(n);
       for(auto &d : a )  cin>>d;
        sortt(a);
        ll ans = a[n-1] - a[0] + a[n-2] - a[0] + a[n-1] - a[1] + a[n-2] - a[1] ; 
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
    while (t--){
          Solution sol;  
          sol.solve();
    } 
    return 0;
}
