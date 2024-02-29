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


class Solution {
public:
    int n ;
    int countBits(ll number) {
        if (number <= 0) 
            return 0;
        int bits = static_cast<int>(log2(number)) + 1;
        return bits;
    }
    void solve(){
        cin >> n ;
        map<int,ll>mp;
        ll ans = 0 ;
        for ( int i = 0 ; i < n ; i++ )
        {
            int x ; cin >> x ;
            ll cte = countBits(x);
            ans+=mp[cte];
            mp[cte]++;
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
    while (t--){
          Solution sol;  
          sol.solve();
    } 
    return 0;
}
