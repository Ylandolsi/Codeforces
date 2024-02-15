#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long 


class Solution {
public:  
    void solve()
    {
        ll n , k ;
        cin >> n >> k ;
        set<ll>a;
        int cte = 0 ;
        for(  ll i =  1; i <= sqrt(n);i++)
        {
            if ( n% i == 0 )
            {
                cte++;
                if ( n/i != i )
                {
                    a.insert(n/i);
                }
                if ( k == cte){
                    cout <<i<<endl;
                    return;
                }
            }
            
        }
        for ( auto d : a)
        {
            cte++;
            if ( cte == k )
            {
                cout << d << endl ;
                return;
            }

        }
        cout<< -1 << endl ;

        
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
     //cin >> t;
     while (t--){
          Solution sol;  
          sol.solve();
     } 
     return 0;
}
