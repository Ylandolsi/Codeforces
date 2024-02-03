#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define int long long 
#define endl "\n"
#define map(a,b) map<a,b>
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))

class Solution {
public:
     void solve(){
          int n , k ; 
          cin >> n >> k ;
          string s , t ;
          cin >> s >> t ;
          map(char ,int ) used , checka , checkb ;
          // Check If they Have The Same Occurences of Charc
          for ( int i = 0 ; i < n ; i++ ){
               checka[s[i]]++;
               checkb[t[i]]++;
          }
          for ( int i = 0 ; i < n ; i++ ){
               if ( checka[s[i]] != checkb[s[i]] ) {
                    cout << "No" << endl ;
                    return ;
               }
          }
          for ( int i = 0 ; i < n ;i++ ) used[s[i]]++;
          for ( int i = 0 ; i< n ;i++ ){
          if ( s[i] == t[i] ) {
               used[s[i]]-- ;
               continue ;
          }
          if (  ( i <=n-(k+1) || i-k >=0) && used[t[i]] > 0  )used[t[i]]--;
          else {
               cout << "No" << endl;
               return;
          }
          
        }
          cout << "Yes" << endl;    
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
