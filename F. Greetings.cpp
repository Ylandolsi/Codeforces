#include <bits/stdc++.h>
using namespace std ; 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
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
#define  bts(x) __builtin_clz(x)
ll modInverse(ll a , ll modd) {return a <= 1 ? a : modd - (ll)(modd/a) * modInverse(modd % a , modd) % modd;}
bool sortinc(auto &a,auto &b){return (a.second < b.second);}
bool sortdec(auto &a,auto &b){return (a.second > b.second);}
ll mceil( ll a , ll b ) { return (a+b-1)/b ; }
template<class T> bool ckmax(T& a, const T& b){return a < b ? a = b, 1 : 0;}
template<class T> bool ckmin(T& a, const T& b){return a > b ? a = b, 1 : 0;}
ordered_set<ll> st;
 
//order_of_key (k) : index :  Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero)


class Solution {
public:
    int n ; ll  ans = 0 ;
    void solve(){
        cin >> n ;
        ordered_set<ll>s ;
        vector<pi>a_b;
        for ( int i = 0 ; i < n ; i++ ){
            ll x, y ; cin >> x >> y ;
            a_b.emplace_back(x,y);
            s.insert(y);
        }
        sortt(a_b);
        for ( int i = 0 ; i < n ; i++ ){
            ans+=s.order_of_key(a_b[i].second);
            s.erase(a_b[i].second);

        }
        cout  << ans << endl ;

               
    }
     
};



int32_t main() {
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
