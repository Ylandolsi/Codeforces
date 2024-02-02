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
          int n ,  m ;
          cin >> n >> m ; 
          vector<int> vet ( n );
          for(auto &d : vet )  cin>>d;
          sortt(vet);
          for ( int i = 0 ; i < m ; i++ ){
               int a , b ,c ; 
               cin >>a >> b >> c ;
               auto iter = upper_bound(all(vet), b- sqrt(4*a*c) ) ;
               if ( iter != vet.end() && *iter < b+sqrt(4*a*c)) {
                    cout << "Yes" << endl;
                    cout << *iter << endl ;
               }
               else cout << "No" << endl;
               cout << endl ;
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
