#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
typedef long long ll ;
typedef pair<ll,pair<ll,ll>> tup;
typedef pair<ll,ll> pi;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#endif
#define endl "\n"
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))
#define getunique(vt)  vt.erase(unique(all(vt)), vt.end())
#define rev(x)   reverse (all(x)) 
bool sortinc(auto &a,auto &b){return (a.second < b.second);}
bool sortdec(auto &a,auto &b){return (a.second > b.second);}
ll mceil( ll a , ll b ) { return (a+b-1)/b ; }
template<class T> bool ckmax(T& a, const T& b){return a < b ? a = b, 1 : 0;}
template<class T> bool ckmin(T& a, const T& b){return a > b ? a = b, 1 : 0;}




class Solution {
public:
    int countBits(int number) {
        if (number <= 0) {
            return 0;
        }
        int bits = (int)(log2(number)) + 1;
        return bits;
    }
     void solve(){
        int a ; cin >> a ;
        int bits = countBits(a);
        bool allones = 0 ;
        int ans = 1 ;
        for ( int i = 2 ; i <= sqrt(a) ; i++  )
            if ( a % i == 0 )  ans = max(ans , max( i , a/i) );
        
        for ( int i = 0 ; i <bits ; i++ ) 
            if ( (a & (1 << i)) == 0 ) allones = 1; 
        
        if ( !allones )   cout << ans  << endl ;
        
        else cout << ( a ^ ( a ^ (1 <<  bits)-1 ) )  << endl ;
        

               
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
