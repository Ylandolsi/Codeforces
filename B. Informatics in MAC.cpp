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
#define endl "\n"
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))
#define getunique(vt)  vt.erase(unique(all(vt)), vt.end())
#define rev(x)   reverse (all(x)) 

class Solution {
public:
     int n ;
     void solve(){
        cin >> n ;
        vector<int>a(n);
        for(auto &d : a )  cin>>d;
        set<int>st1 , st2 ; 
        for ( int i = 0 ; i <= n + 5  ; i++ ){
            st1.insert(i) ;
            st2.insert(i);
        }
        vector<int>prefix(n) , suffix(n);
        for ( int i = n -1 ; i>= 0 ; i-- ){
            st1.erase(a[i]);
            suffix[i]=*st1.begin();
        }
        for (int i = 0 ; i < n ; i++ ){
            st2.erase(a[i]);
            prefix[i]=*st2.begin();

        }
        for ( int i = 0 ; i < n-1  ;i++ ){
            if ( prefix[i] == suffix[i+1]){
                cout << 2 << endl ;
                cout << 1 << " " << i+1 << endl ;
                cout << i+2 << " " << n << endl ;
                return ;

            }
        }
        cout << -1 << endl ;
        
               

               
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
    cin >> t;
    while (t--){
          Solution sol;  
          sol.solve();
    } 
    return 0;
}
