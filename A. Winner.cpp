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
#define unq(vt)  vt.erase(unique(all(vt)), vt.end())
#define rev(x)   reverse (all(x)) 
template<class T> bool ckmax(T& a, const T& b){return a < b ? a = b, 1 : 0;}
template<class T> bool ckmin(T& a, const T& b){return a > b ? a = b, 1 : 0;}



class Solution {
public:
    int n ;
    void solve(){
        cin >> n ; 
        map<string , vector<pair<int,int>> >mp;
        map<string,int>winners ;
        int search = -1e9 , cte = 0  , ind = 2001;

        for ( int i = 0 ; i < n ; i++ )
        {
            string s ; int points ; 
            cin >> s >> points;
            if ( mp[s].size() == 0 ) mp[s].pb({points,i});
            else mp[s].pb( { mp[s].back().first + points , i } )  ;    
        }

        for ( auto d : mp )
            search = max (search , d.second.back().first );
    
        for ( auto d : mp ){
            if ( d.second.back().first == search ) {
                    cte++;
                    winners[d.first]++;
            }
            
        }
       
        string winner ;
     
        for ( auto d : mp ) {
            for ( auto v : d.second ) {
                if (  winners[d.first] 
                         && v.second < ind && v.first >= search ) {
                    winner = d.first ; 
                    ind = v.second ;
                }
            }
        }
        cout << winner ;
        
        
        


               
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
    //cin >> t;
    while (t--){
          Solution sol;  
          sol.solve();
    } 
    return 0;
}
