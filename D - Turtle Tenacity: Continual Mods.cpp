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
template<class T> bool ckmax(T& a, const T& b){return a < b ? a = b, 1 : 0;}
template<class T> bool ckmin(T& a, const T& b){return a > b ? a = b, 1 : 0;}






class Solution {
public:
     int n ;
     void solve(){
        cin >> n ;
        vector<ll>a(n);
        for(auto &d : a )  cin>>d;
        sortt(a);
        bool found = 0 ;
        for ( int i = n-1 ; i >= 0 ; i-- )
        {
            if ( a[i] % a[0] != 0 ) {
                found = 1 ;
                break;
            }
            
        }
        if (  found || a[0] != a[1] )cout << "Yes" << endl;
        else cout << "No" << endl;

               
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
