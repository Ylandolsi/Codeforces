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
        int n , m , answer = 0 ;
        cin >> n >> m ;
        
        vector<int>b;
        for ( int i = 0 ; i < n  ;i++ )
        {
            string s ; cin >> s ;
            
            int count = 0 ; 
            for ( int i = s.size() - 1 ; i >= 0 ; i-- )
            {
                if ( s[i] != '0') break;
                count++;
            }
            answer+=s.size()  ;
            b.pb(count);
            
        }
        int xo = 1 ; 
        sortt(b); rev(b);
        for ( auto d : b)
        {
            if ( xo == 1 ) answer-=d;
            xo^=1;
        }
        if ( answer > m ) cout << "Sasha"<<endl ;
        else cout << "Anna"<<endl ;

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
