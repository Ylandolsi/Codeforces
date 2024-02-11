#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long 
#define endl "\n"
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))
#define unq(vt)  vt.erase(unique(all(vt)), vt.end())

class Solution {
public:
    void solve(){
        int n , answer = 0 ;
        cin >> n;
        vector<ll>a(n);
        for(auto &d : a )  cin>>d;
        sortt(a);
        unq(a);
        for ( int i = a.size() -1  ; i>= 0 ; i-- )
        {
            ll x = lower_bound(all(a),a[i]+1-n)-a.begin();
            answer= max(answer, i-x+1);
        }
        cout << answer << endl ;         



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
      cin >>t ;
      Solution sol;  
      while (t--) sol.solve();
      return 0;
 }
 
