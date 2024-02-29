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

class Solution {
public:
    int n ;
    void solve(){
        ll l , r , x ;
        ll ans = 0;
        cin >> n >> l >> r >> x ;
        vector<int>a(n);
        for(auto &d : a )  cin>>d;
        for ( int mask = 0 ; mask < 1 << n  ; mask++  )
        {
            ll totdif = 0 ;
            int maxi = INT_MIN , mini = INT_MAX ; 
            for ( int i = 0 ; i < n  ; i++ )
            {
                if ( mask & 1 << i )
                {
                    totdif+=a[i];
                    maxi=max(a[i],maxi);
                    mini=min(a[i],mini);
                }
            }
            if ( totdif >= l && totdif <= r && maxi - mini >= x) ans++;


        }
        cout <<ans <<endl;
               

               
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
    while (t--){
          Solution sol;  
          sol.solve();
    } 
    return 0;
}
