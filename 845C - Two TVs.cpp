#include <bits/stdc++.h>
using namespace std ; 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define pb push_back
#define FAST  cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0) ; 
typedef long long ll ;
typedef pair<ll,ll> pi;
#ifndef ONLINE_JUDGE
#include "___()___.cpp"
#endif
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))
#define getunique(vt)  vt.erase(unique(all(vt)), vt.end())
#define rev(x)   reverse (all(x)) 
#define inf  __LONG_LONG_MAX__ 
#define Sum(x) accumulate( x.begin() , x.end() , 0ll ) 
#define For( i , debut , fin )  for ( int i = debut ; i <= fin ; i++ )
#define Forr( i , debut , fin )  for ( int i = debut ; i >= fin ; i-- )
#define  ibits(x) 32 - __builtin_clz(x) // 32 - bts(x) if int 
#define  lbits(x) 64 -  __builtin_clzll(x) // 64 - bts(x) if long long 
ll add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
void makemod(ll &a, ll md ) { a =  (a % md + md) % md;}
bool sortinc(pi &a,pi &b){ if ( a.second == b.second ) return a.first < b.first ;  else  return a.second < b.second;}
bool sortdec(pi &a,pi &b){ if ( a.second == b.second ) return a.first > b.first ;  else  return a.second > b.second;}
template<typename... T>void read(T&... args) {((cin >> args), ...);}
template<typename... T>void print(T&&... args) {((cout << args /*<< " "*/), ...);}
template<class T , class V > bool ckmax(T& a, const V& b){return a < b ? a = b, 1 : 0;}
template<class T , class V > bool ckmin(T& a, const V& b){return a > b ? a = b, 1 : 0;}
template<typename F, typename S>ostream& operator <<(ostream& ostream, pair<F, S>& p) {cout << p.first << " " << p.second;return ostream;}
template<typename T>ostream& operator <<(ostream& ostream, vector<T>& v) {for(auto& element : v) {cout << element << " ";}return ostream;}
template<typename T>ostream& operator <<(ostream& ostream, vector<vector<T>>& v) {for(auto& row : v) {for(auto& cell : row) {cout << cell << " ";}cout << "\n";}return ostream;}

class Solution{
public : 
   void solve(){
    int n ; read  (n ) ; 
    vector<pi>lr;
    vector<ll>pref(2*n + 50) , total ;
    map<ll,int>mp;
    For ( i  ,0 ,  n-1 ) {
        ll L , R ; read ( L , R ) ; 
        lr.pb({L,R});
        total.pb(L);
        total.pb(R);
    }
    sortt(total);
    For ( i  , 0 , total.size()-1 )   if ( mp[total[i]] == 0 ) mp[total[i]] = i+1 ; 
    For ( i , 0 , n-1 ){
        ll le = mp[lr[i].first];
        ll ri = mp[lr[i].second];
        pref[le]++;
        pref[ri+1]-- ; 
    }
    string ans = "YES\n";
    For ( i , 1 , pref.size()-1 ){
        pref[i]+=pref[i-1];
        if ( pref[i] > 2 ) ans = "NO\n";
    }
    print ( ans ); 

   
   }
     
};




int main() {
   cout << fixed << setprecision(14) ;
   FAST
   #ifndef ONLINE_JUDGE
      freopen("inp.txt", "r", stdin);
      freopen("out.txt", "w", stdout);
      freopen("err.txt", "w", stderr);
   #endif
   int t = 1;
   while (t-- ) { Solution sol ; sol.solve(); }
   return 0;
}
