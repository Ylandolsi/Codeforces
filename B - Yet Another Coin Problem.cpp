#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long 
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#endif
#define endl "\n"
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))


class Solution {
public:
    
    
    void solve(){
       ll n ; cin >> n ;
       ll qinz = n / 15 ; 
       ll reste  = n%15;
       map<int,int>mp;
       mp[1]= mp[6] =  mp[3] = mp[15] = mp[10] = 1 ;
       mp[2] = mp[4] = mp[7] = mp[9] = mp[12] =  2 ;
       mp[8] = mp[5] = mp[18] = 3 ;
       mp[0] = 0;
       if ( n <15 ) {
            if ( n >= 10 ) cout <<( mp[n]? mp[n]:( mp[10] + mp[n%10]) )<< endl ;
            else cout << mp[n%10] << endl ;;
            return ; 
       }
       ll ans1 , ans2 ;
       ans1 = qinz + (mp[reste] ? mp[reste] : ((( reste >= 10 ) ? mp[10] : 0) + mp[reste % 10 ]));
       reste+=15;
       ans2 = qinz-1 +( mp[reste] ? mp[reste] : ((( reste >= 10 ) ? mp[10]*(reste/10) : 0 )+ mp[reste % 10 ]));
       cout << min(ans2,ans1) << endl;
       
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
