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
     int tolenght (int x ){
          string ch =  to_string(x);
          int sz = ch.size() ;
          return sz ;
     }
     void solve(){
          int n  , opp = 0;
          cin >> n ; 
          vector<int> a(n) , b ( n ) , a_ ,b_;
          map<int,int>st;
          for(auto &d : a )  cin>>d;
          for(auto &d : b )  cin>>d;
          sortt(a); sortt(b);
          // Elminating Equal Elements 
          for ( auto d : b) st[d]++;
          for ( auto d : a ){
               if ( st[d] <= 0 ) a_.pb(d);
               st[d]--;
          }
          st.clear();
          for ( auto d : a) st[d]++;
          for ( auto d : b ){
               if ( st[d] <= 0  ) b_.pb(d);
               st[d]--;
          }
          for ( int i = 0 ; i < b_.size() ; i++ ){
               if ( b_[i] > 9 ) b_[i] = tolenght(b_[i]) , opp++;
          }
          for ( int i = 0 ; i < a_.size() ; i++ ){
               if ( a_[i] > 9 ) a_[i] = tolenght(a_[i]) , opp++;
          }
          // -------- 
          // Elminating Equal Elements 
          sortt(a_); sortt(b_);
          a.clear(); b.clear();
          st.clear();
          for ( auto d : b_) st[d]++;
          for ( auto d : a_ ){
               if (st[d] <= 0 ) a.pb(d);
               st[d]--;
          }
          st.clear();
          for ( auto d : a_) st[d]++;
          for ( auto d : b_ ){
               if (st[d] <= 0 ) b.pb(d);
               st[d]--;
          }
          // ----------------
          for ( auto d : b) if (d!= 1 ) opp++;
          for ( auto d : a) if (d!= 1 ) opp++;
          cout<< opp << endl ;
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
