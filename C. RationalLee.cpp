#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long 
#define endl "\n"
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))
#define rev(x)   reverse (all(x)) 

class Solution {
public:
    
    void solve()
    {
        ll n , k , cteones = 0 , ans = 0 ;
        cin >> n >> k ; 
        deque<ll>a(n) , b(k);
        for(auto &d : a )   cin>>d;
        for(auto &d : b ) { cin>>d;  cteones+=d==1;}
        sortt(a);
        sortt(b);
        for ( int i = 0 ; i<cteones ; i++ )
        {
            ans+=a.back()*2;
            a.pop_back();
            b.pop_front();
        }
        rev(b);
        ll index = 0 ;
        for ( int i = 0 ; i < b.size() ; i++ )
        {
            ans+=a.back();
            ans+=a[index];
            index+=b[i]-1;
            a.pop_back();
        }
        cout << ans<<endl ;
        
    
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
