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
typedef pair<ll,pair<ll,ll>> tup;
typedef pair<ll,ll> pi;
#ifndef ONLINE_JUDGE
#include "TLE.cpp"
#endif
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))
#define getunique(vt)  vt.erase(unique(all(vt)), vt.end())
#define rev(x)   reverse (all(x)) 
#define inf  INFINITY 
#define Sum(x) accumulate( x.begin() , x.end() , 0ll ) 
#define For( i , debut , fin )  for ( int i = x ; i <= n ; i++ )
#define Forr( i , debut , fin )  for ( int i = x ; i >= n ; i-- )
#define  ibits(x) 32 - __builtin_clz(x) // 32 - bts(x) if int 
#define  lbits(x) 64 -  __builtin_clzll(x) // 64 - bts(x) if long long 
ll modInverse(ll a , ll modd) {return a <= 1 ? a : modd - (ll)(modd/a) * modInverse(modd % a , modd) % modd;}
void makemod(ll &a, ll md ) { a =  (a % md + md) % md;}
bool sortinc(pi &a,pi &b){ if ( a.second == b.second ) return a.first < b.first ;  else  return a.second < b.second;}
bool sortdec(pi &a,pi &b){ if ( a.second == b.second ) return a.first > b.first ;  else  return a.second > b.second;}
ll mceil( ll a , ll b ) { return (a+b-1)/b ; }
template<typename... T>void read(T&... args) {((cin >> args), ...);}
template<typename... T>void print(T&&... args) {((cout << args /*<< " "*/), ...);}
template<class T , class V > bool amax(T& a, const V& b){return a < b ? a = b, 1 : 0;}
template<class T , class V > bool amin(T& a, const V& b){return a > b ? a = b, 1 : 0;}
template<typename F, typename S>ostream& operator <<(ostream& ostream, pair<F, S>& p) {cout << p.first << " " << p.second;return ostream;}
template<typename T>ostream& operator <<(ostream& ostream, vector<T>& v) {for(auto& element : v) {cout << element << " ";}return ostream;}
template<typename T>ostream& operator <<(ostream& ostream, vector<vector<T>>& v) {for(auto& row : v) {for(auto& cell : row) {cout << cell << " ";}cout << "\n";}return ostream;}

void Test_Case(){
   int n , m ; 
   read ( n , m ) ; 
   vector<ll>a(n) , b(m);
   for( int i = 0 ; i < a.size() ; i++ )  cin>>a[i];
   for( int i = 0 ; i < b.size() ; i++ )  cin>>b[i];
   ll low = 0 , high = 1e10  , ans = 1e18 ; 
   while ( low <= high ){
      ll mid = low+(high-low)/2;
      vector<ll>allcheck(n+5);
      for ( int i = 0 ; i < m ; i++ ){
         ll checkd = b[i] + mid , checkl  = b[i]-mid ;
         int indexd = upper_bound(all(a), checkd) -a.begin(); indexd-- ; 
         int indexl = lower_bound(all(a) , checkl) -a.begin();
         if ( indexl < n && indexl <= indexd ) {
            allcheck[indexd+1]-- ;
            allcheck[indexl]++;      
         }
      }
      bool find = false ;
      for ( int i = 1 ; i < n ; i++) allcheck[i]+=allcheck[i-1]; 
      for ( int i = 0 ; i < n ; i++ ) if ( allcheck[i]<=0) find = true;  
      if ( !find  ) { high = mid - 1 ;ans = min( ans , mid );}
      else { low = mid + 1 ;  }

   }
   print ( ans); 
}
     




int main() {
   cout << fixed << setprecision(14) ;
   FAST
   #ifndef ONLINE_JUDGE
      freopen("inp.txt", "r", stdin);
      freopen("out.txt", "w", stdout);
      freopen("err.txt", "w", stderr);
   #endif
    Test_Case();
   return 0;
}
