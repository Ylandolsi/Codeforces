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


class Solution {
public:

     ll n , a , b ;
     void solve(){
          cin >> n >> a >> b  ;
          ll p = 1 ; 
          if ( a == 1 )
          {
               if ( (n - a) % b == 0 )  puts("Yes");
               else  puts("No");
               return ;
          }
          while ( p <= n )
          {
               
               if ( (n - p) % b == 0 )
               {
                    puts("Yes");
                    return ;
               }
               p*=a;
          }
          puts("No");
          
          

     }
     
};

int main() {
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
