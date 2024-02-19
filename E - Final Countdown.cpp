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
          int n ;
          cin >> n ;
          string s , ans  ;
          cin >> s ;
          
          
          ll prefix[n+2];
          memset( prefix , 0ll , sizeof(prefix));    
          for ( int i = 1 ; i < n ; i++)
               prefix[i] = prefix[i-1] + s[i-1]-'0';
               
          
          ll rem = 0 ;
          for ( int i = n-1 ; i >= 0 ; i-- )
          {
               ll cur = prefix[i] + rem ; 
               rem = ((s[i] - '0') + cur)/10;
               ll in = s[i]-'0';
               s[i]= ( ((cur + in )%10)  +'0');
          }
          if ( rem > 0 ){
               char x = rem+'0' ;
               s = x + s  ;
          } 
          reverse(all(s));
          ll ind = s.size();
          while ( s[s.size()-1] =='0'&& ind >= 0){
               s.pop_back();
          } 
          reverse(all(s));
          cout << s << endl ;
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
