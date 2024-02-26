#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long 
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

using namespace std;

class SegmentTree {
private:
    ll  n;
    vector<ll> a , seg;
    void Increment(int node , ll Start , ll End , ll RightUSER , ll LeftUSER) {
        
        if (Start >= LeftUSER && End <= RightUSER){ 
            seg[node]++;
            return;
        }
        if (LeftUSER > End || RightUSER < Start)
            return; 
        ll mid = ( Start + End) / 2 ;
        Increment(node*2  , Start ,mid  ,  RightUSER, LeftUSER );
        Increment(node*2 +1 , mid + 1  , End , RightUSER ,  LeftUSER   );

    }
    ll QueryDis ( ll node , ll left , ll right , ll pos ){
        if ( left == right) return seg[node];
        ll mid = ( left + right ) / 2 ;
        if ( mid >= pos ) return  seg[node] + QueryDis( node * 2 , left , mid , pos  ) ; 
        else  return seg[node] + QueryDis( node * 2 +1 , mid + 1  , right , pos  ) ;
    }
    
public:
    SegmentTree(const vector<ll>& arr) {
        n = arr.size();
        a = arr;
        seg.resize(4 * n , 0ll );
        
    }
    void incRange ( ll start , ll end ){
        Increment(1, 0, n - 1, end, start ) ;
    }
    ll query(ll pos ) {
        return QueryDis( 1 , 0 , n-1 , pos ) ;
    }

};

class Solution {
public:
     ll n ;
     void solve(){
          cin >> n ;
          vector<ll>a(n ) , b ( n ) , resteV ( n , 0 ) , PrefixB ;
          for(auto &d : a )  cin>>d;
          for(auto &d : b )  { cin>>d; PrefixB.pb(d); }
          for ( int i = 1 ; i < n ; i++ ) PrefixB[i]+=PrefixB[i-1];
          
          SegmentTree tree(a) ;
         
          for (  int i = 0 ; i < n  ;i++ )
          {
               ll reste = 0 ;
               ll iter = upper_bound(all(PrefixB) , a[i] + ( i ? PrefixB[i-1] : 0 ) ) - PrefixB.begin();
               if ( iter != n && iter > 0  && i > 0  ){
                    reste = abs ( a[i] - PrefixB[iter-1] + PrefixB[i-1]  ) ;
                    resteV[iter] += reste ;
               }
               else if ( (iter == 0 || i == 0) && iter != n && iter != i  ) {
                    reste = abs  ( a[i] - PrefixB[iter-1] );
                    resteV[iter] += reste ;
               }
               else if ( iter == i ) {
                    resteV[i] = a[i];
               }
               iter--;
               if ( iter < i ) continue;
               tree.incRange( i , iter );
          }
          vector<ll>answer(n);
          for ( int i = 0 ; i < n  ; i++ )
          {
               answer[i]+= resteV[i];
               ll ct = tree.query( i  ) ; 
               answer[i]+=ct*b[i];

          }
          for ( auto d : answer) cout <<  d << " ";
     
          cout << "\n";


          
     }
     
};



signed main() {
     SPEED;
     #ifndef ONLINE_JUDGE
          freopen("inp.txt", "r", stdin);
          freopen("out.txt", "w", stdout);
          freopen("err.txt", "w", stderr);
     #endif
     int testcase = 1;
     cin >> testcase;
     while (testcase--){
          Solution sol;  
          sol.solve();
     } 
     return 0;
}


 
