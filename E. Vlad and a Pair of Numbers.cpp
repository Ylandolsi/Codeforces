#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0) 
#define endl "\n"
#define ll long long 

class Solution {
public:
    
    void solve(){
        ll x  ;
        cin >> x   ;
        if ( x % 2 == 1 ) cout<<-1<<endl;
        else {
            bitset<32> binaryNumber(x) ,binaryNumber2(x/2) ;
            set<int>st;
            for ( int i = 0 ; i <= 31 ; i++ ){
                if ( binaryNumber[i] == 1 && binaryNumber2[i] == 1 ){
                   cout << -1<< endl ;return;
                } 
            }
            cout << x - x/2 << " " << x + x/2  << endl ;
        }
        
        
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
