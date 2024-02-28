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
        cin >> n ;
        map<ll,ll>mp;
        set<ll>st;
        for ( int i = 0 ; i < n ; i++ )
        {
            char type ; ll what ;
            cin >> type >> what ;
            if ( type == '+') 
                st.insert(what);
            else {
                ll start = mp[what] == 0 ? what : mp[what];
                for ( ll i = start ; i<=2e18 ; i+=what )
                {
                    if ( st.find(i) == st.end() )
                    {
                        cout << i << endl;
                        mp[what] = i ;
                        break ;
                    }
                }
            }

        }
        
               
     }
     
};

signed main() {
    cout << fixed << setprecision(2) ;
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
