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
    string s ;
    int n ;
    vector<int>dp;
     Solution(){
        cin >> n ;
        dp.resize(n , -1 );
    }

    int work ( int ind )
    {
        if ( ind >= n ) return 0 ;
        if ( s[ind] == '*')
            return 0 ;
        if ( dp[ind] != -1 )return dp[ind];
        int choice1 = ((s[ind] == '@' )? 1 : 0) + work ( ind+1 ) ;
        int choice2 = ((s[ind] == '@' )? 1 : 0) + work ( ind + 2 );
        dp[ind]=max(choice1 , choice2 ) ;
        return dp[ind] ;
    }
     
    void solve(){

        cin >> s ;
        cout << work(0)  << endl ;

           
     }
     
};

signed main() {
     SPEED;
     #ifndef ONLINE_JUDGE
          freopen("Input.txt", "r", stdin);
          freopen("Output.txt", "w", stdout);
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
