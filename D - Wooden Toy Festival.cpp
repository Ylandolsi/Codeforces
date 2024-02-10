#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long 
#define endl "\n"



class Solution {
public:
    ll mid ;
    vector<int> a;
    bool verif()
    {
        int taken = 1 ;
        ll MaxDiff = mid + a[0];
        for ( int i = 1 ; i < a.size() ; i++){
            if ( abs ( a[i]-MaxDiff )  > mid )
            {
                MaxDiff = a[i] + mid ;
                taken++;
            }
            if ( taken > 3 )
            {
                return false ;
            }    
        }
        if ( taken <= 3 ) return true ;

    }
    void solve(){

        int n;
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin() , a.end() ) ;
        ll left = 0 , right = 2e9 , answer = 0 ;
        while ( left <= right )
        {
            mid= (left + right) /2 ;
            if ( verif())
            {
                right = mid - 1 ;
                answer = mid ;
            }
            else {
                left = mid  +1  ;
            }
        }
        cout << answer << endl;

          
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
