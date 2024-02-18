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

class Solution {
public:

    void solve(){
        int n ;
        cin >> n ;
        vector<ll>a(n);
        for(auto &d : a )  cin>>d;
        ll years = a[0] ;
        for ( int i = 1 ; i < n ; i++)
        {
            ll mult = 1 ;
            if ( a[i] <= years )
            {
                ll low = 1 , high = 1e9 ;
                while ( low <= high )
                {
                    ll mid = ( low + high ) / 2 ;
                    if ( a[i] * mid <= years) low = mid + 1 ;
                    else {
                        mult = mid ;
                        high = mid -1 ;
                    }
                }
                years = mult * a[i];                
            }
            else years = a[i];
            
        }  
        cout << years << endl ;
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
