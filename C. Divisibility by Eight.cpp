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
#define unq(vt)  vt.erase(unique(all(vt)), vt.end())
#define rev(x)   reverse (all(x)) 
template<class T> bool ckmax(T& a, const T& b){return a < b ? a = b, 1 : 0;}
template<class T> bool ckmin(T& a, const T& b){return a > b ? a = b, 1 : 0;}

class Solution {
public:
     
     string s ;
     void solve(){
        cin >> s ;
        bool found = 0 ;
        string res="";
        for ( int i = 0 ; i <= 1000   ; i+=8 )
        {
            string ch = to_string(i);
            int cont = 0 ;
            bool wefound = 1 ; 
            for ( auto c:ch ){
                bool check = 0 ;
                for ( int i = cont ; i  < s.size()  ; i++){
                    if ( s[i] == c ) {
                        cont=i+1;
                        check = 1 ;
                        break ;

                    }
                }
                if ( !check ) { wefound = 0 ; break ;}
            }
            if ( wefound == 1 && ch !="" ) { found = 1 ; res=ch; break ;}
        }
        if ( found && res!="" )  cout << "YES\n" << res << endl ;
        else cout << "NO\n";
          
               

               
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
