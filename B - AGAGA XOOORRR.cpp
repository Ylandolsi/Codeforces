#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
typedef long long ll ;
typedef pair<ll,pair<ll,ll>> tup;
typedef pair<ll,ll> pi;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#endif

class Solution {
public:
    int n  ;
     void solve(){
        cin >> n ;
        vector<int>a(n) , prefx , suff(n);
        int x = 0 ; 
        for(auto &d : a )  {
            cin >> d ;
            x^= d ;
            prefx.pb(x);
        }
        for ( int i = n - 1  ; i >= 0 ; i-- ){
            if ( i == n -1 ) suff[i] = a[i];
            else suff[i]=suff[i+1]^a[i];
            
        }
        if ( x == 0 ) { cout << "Yes" << endl; return ; }
        for ( int i = 1 ; i < n ; i++ )
        {
            
            for ( int j = i+1 ; j < n  ; j++ )
            {
                if ( prefx[i-1] == suff[j])
                {
                    int middle =  prefx[j-1] ^ prefx[i-1];
                    if ( middle == suff[j]) {
                        cout << "Yes" << endl;
                        return ;
                    }
                }
            }

        }
        cout << "No" << endl;
        
        
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
