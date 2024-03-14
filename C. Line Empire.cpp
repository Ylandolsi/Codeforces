#include <bits/stdc++.h>
using namespace std ; 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define pb push_back
#define i_love_binary_search  cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0) ; 
typedef long long ll ;
typedef pair<ll,pair<ll,ll>> tup;
typedef pair<ll,ll> pi;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#endif
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))
#define getunique(vt)  vt.erase(unique(all(vt)), vt.end())
#define rev(x)   reverse (all(x)) 
#define  bts(x) __builtin_clz(x)
ll modInverse(ll a , ll modd) {return a <= 1 ? a : modd - (ll)(modd/a) * modInverse(modd % a , modd) % modd;}
bool sortinc(pi &a,pi &b){ if ( a.second == b.second ) return a.first < b.first ;  else  (a.second < b.second);}
bool sortdec(pi &a,pi &b){ if ( a.second == b.second ) return a.first > b.first ;  else  (a.second > b.second);}
ll mceil( ll a , ll b ) { return (a+b-1)/b ; }
template<class T> bool ckmax(T& a, const T& b){return a < b ? a = b, 1 : 0;}
template<class T> bool ckmin(T& a, const T& b){return a > b ? a = b, 1 : 0;}
ordered_set<ll> st;
//order_of_key (k) : index :  Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero)


class Solution {
public:
     int n  , a , b ;
     void solve(){
          cin >> n >> a >> b ; 
          vector<ll>vect(n) , suff ;
          for(auto &d : vect )  cin>>d;
          for ( auto d: vect ) suff.pb(d);
          for ( int i = n-2 ; i >= 0 ; i-- )  suff[i]+=suff[i+1];
          
          ll ans = b *vect[0]  ;
          ll cur = 0 ; 

          for ( int i = 1 ; i < n ; i++ ){
               ll choiceJump = (suff[i]-(vect[i-1]*(n-i) )) *  b;
               choiceJump +=(vect[i-1]-cur)*a;
               ll nojump = ((suff[i]-(cur*(n-i)))*b);
               if ( choiceJump <= nojump ) {
                    ans+=(vect[i-1]-cur)*a; 
                    ans+=(vect[i]-vect[i-1])*b;
                    cur = vect[i-1];
               }
               else ans+=(vect[i]-cur)*b ; 
               
          }
          cout << ans << endl ;

               
     }
     
};



int32_t main() {
     cout << fixed << setprecision(2) ;
     i_love_binary_search 
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
