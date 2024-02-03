#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define int long long 
typedef pair<int,pair<int,int>> tup;
typedef pair<int,int> pi;
#define endl "\n"
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))
#define unq(vt)  vt.erase(unique(all(vt)), vt.end())
#define rev(x)   reverse (all(x)) 

class Solution {
public:
     void solve(){
        int n , k ; 
        cin >> n >> k ;
        vector<int> a (n );
        for(auto &d : a )  cin>>d;
        sortt(a);
        map<int,int>mp;
        int mid = ceil ( n / double( 2 )) ;
        for ( int i = n - 1 ; i > n /2 ; i-- ){
          if ( a[i] - a[i-1] >= 1 ) mp[mid-1]= a[i]-a[i-1];
          mid--; // Calculating The distance and K needed for Each One :
               // To make it more optimal 
        }
        int middle = a[n/2];
        mid = ceil ( n / double( 2 )) ;
        for ( auto d : mp ){
          if ( k <= 0 ) break ; 
          int ff = min ( d.second  , k );
          int Count = d.first * ff ; 
          int plus = min( k , Count ) ;
          k -=plus;
          middle +=plus/d.first;
        }
        if ( k >= mid )  middle+=k/mid;
        cout << middle << endl ; 
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
    //cin >> t;
    Solution sol;  
    while (t--) sol.solve();
    return 0;
}
