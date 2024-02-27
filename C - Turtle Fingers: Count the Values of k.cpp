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
        ll l , a , b ;
        cin  >> a >> b >> l  ;
        int cnte = 0 ;
        set<ll>st;
        long double aaa = a == 1 ? 1 : log(a);
        long  double  bbb = b == 1 ? 1 : log(b);
        for ( int i = 0 ; i <= log(l)/aaa  + 5  ; i++ )
        {
            for ( int j = 0 ; j <= log(l)/bbb  + 5  ; j++)
            {
                long double x = pow(a,i) ;
                long double y = pow(b,j);
                ll z = x * y;

                if (   x !=0 && y !=0 && l %  z  == 0) st.insert( l / (x*y) );

            }
        }
        cout << st.size() <<endl ;
               

               
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
