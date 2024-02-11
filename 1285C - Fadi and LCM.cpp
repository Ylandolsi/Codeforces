 #include <bits/stdc++.h>
 using namespace std ; 
 #define pb push_back
 #define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
 #define ll long long 
 #define endl "\n"
 
 class Solution {
 public:
      void solve(){
           ll n ; 
           cin >> n ;
           pair<ll,ll>answer={1e18,0};
           
           for ( ll i = 1 ; i <= sqrt(n) ; i++ )
           {
                ll x = n/i ;
                if ( lcm(x,i) == n)
                {
                    if  ( answer.second  > answer.first ) swap(answer.second,answer.first);
                    if ( answer.first > max(x,i) )
                    {
                        answer.first=x;
                        answer.second=i;
                    }
                }
           }
           cout << answer.first << " "<<answer.second<<endl; 
           
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
      Solution sol;  
      while (t--) sol.solve();
      return 0;
 }
 
 
 
 
 
 
 
 
