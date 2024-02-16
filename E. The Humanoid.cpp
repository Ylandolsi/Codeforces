#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long 
#define endl "\n"
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))
#define unq(vt)  vt.erase(unique(all(vt)), vt.end())
#define rev(x)   reverse (all(x)) 


class Solution {
public:
    
    void solve()
    {
        ll n , h , copyh  , absorb = 0 , index = 0 , maxabsorb = 0 ;
        cin >> n >> h ;
        copyh = h ;
        vector<ll>a(n);
        for(auto &d : a )  cin>>d;
        sortt(a);
        deque<int>element={2,2,3};
        for ( int j = 0 ; j < 3 ; j++ )
        {
            index = 0 ;
            absorb = 0 ;
            h = copyh ;
            for ( int i = 0 ; i< n ; i++ )
            {
                if ( a[i] < h)
                {
                    h+=a[i]/2;
                    absorb++;
                    continue;
                }
                else {
                    bool flag = 1 ;
                    while (index < 3 && h <= a[i])
                    {
                        h*=element[index];
                        index++;
                        
                    }
                    if ( h <= a[i] ) break;
                    else {
                        h+=a[i]/2;
                        absorb++;
                    }
                    
                }
            }
            int to_push = element[0];
            element.pop_front();
            element.push_back(to_push);
            maxabsorb = max ( absorb , maxabsorb );
        }
       
        cout << maxabsorb << endl ;
    
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
