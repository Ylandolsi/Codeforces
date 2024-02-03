#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define int long long 
#define endl "\n"
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))

int MOD = 1e9 + 7 ;
class Solution {
public:
      class DisjointSet {
      public: 
          vector<int>size , parent ; 
          DisjointSet(int n) { 
              size.resize(n+3); 
              parent.resize(n+3);
              for(int i = 0;i<=n;i++) {
                  parent[i] = i; 
                  size[i] = 1; 
              }
          }
          int findboss(int node) { 
              if(node == parent[node])
                  return node; 
              return parent[node] = findboss(parent[node]); 
          }
          void unionset(int u, int v) {    
              int x = findboss(u); 
              int y = findboss(v); 
              if(x == y) return; 
              if ( size[x] >= size[y] ) swap(x,y);
              parent[x] = y; 
              size[y] += size[x]; 
          }
          
      };
      
     void solve(){
            int n ;
            cin >> n ;
            vector<int> a ( n ) , b ( n ) , c ( n );
            for(auto &d : a )  cin>>d;
            for(auto &d : b )  cin>>d;
            for(auto &d : c )  cin>>d;
            DisjointSet dsu (n+2);
            for ( int i = 0 ; i < n ; i++ )
            {
                  dsu.unionset(a[i] , b[i]) ; 
                  if(a[i]==b[i]) c[i]=b[i];
            }
            set<int>st;
            for ( int i = 1 ; i <= n ; i++ )  st.insert(dsu.findboss(i));
            
            for ( int i = 0 ; i < n ;i++ )
                 if ( c[i] ) st.erase(dsu.findboss(c[i]));
            
      
            int ans = 2 ;
            for ( int i = 0 ; st.size() > 0 &&  i < st.size() -1  ; i++ ){
                  ans*=2;
                  ans%=MOD;
            }
            cout << (  st.size() >=  1 ? ans : 1 ) << endl ;
            
       
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
