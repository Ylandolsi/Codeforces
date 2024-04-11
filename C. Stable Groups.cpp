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
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...);}
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))
#define getunique(vt)  vt.erase(unique(all(vt)), vt.end())
#define rev(x)   reverse (all(x)) 
#define inf  __LONG_LONG_MAX__ 
void yno(bool value){cout<<(value?"Yes\n":"No\n");}
#define Sum(x) accumulate( x.begin() , x.end() , 0ll ) 
#define For( i , debut , fin )  for ( int i = debut ; i <= fin ; i++ )
#define Forr( i , debut , fin )  for ( int i = debut ; i >= fin ; i-- )
#define  ibits(x) 32 - __builtin_clz(x) // 32 - bts(x) if int 
#define  lbits(x) 64 -  __builtin_clzll(x) // 64 - bts(x) if long long 
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
      ll n , k , x ; read ( n , k ,x );
      vector<ll>a(n);
      For ( i , 0 , a.size()-1 )  cin>>a[i];
      sortt(a);
      ll groups_without_change = 0;  
      vector<pair<ll,ll>>end_start ; 
      ll prev = a[0];
      for ( int i = 1 ; i < n ; i++ ){
         if ( a[i] - prev > x )  end_start.pb({prev,a[i]});
         prev=a[i];
      }
      vector<ll>greedy_choice;
      groups_without_change = end_start.size()+1 ; 
      for ( auto [ st , en ] : end_start ){
         ll need = ( en - st +x-1)/x;
         greedy_choice.pb(need-1) ; 
      }
      sortt(greedy_choice);
      ll added_so_far = 0 ; 
      for ( auto d : greedy_choice ){
         added_so_far+= d; 
         if ( added_so_far > k ) break ; 
         groups_without_change-- ; 
      }
      print ( groups_without_change , "\n");

   
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
   auto start = std::chrono::high_resolution_clock::now();
   int t = 1;
   while (t-- ) { Solution sol ; sol.solve(); }
   auto end =chrono::high_resolution_clock::now(); auto duration = chrono::duration_cast<chrono::milliseconds>(end - start); cerr << "Execution time: " << duration.count() << " milliseconds" << std::endl;

   return 0;
}
