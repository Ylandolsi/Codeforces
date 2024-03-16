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
#define  bts(x) __builtin_clz(x) // 32 - bts(x) if int 
#define  lbts(x) __builtin_clzll(x) // 64 - bts(x) if long long 
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
     int n , m , k  ;
     vector<pi> getdiv ( ll n )
     {
         vector<pi>divisors;
         for ( int i = 1 ; i <= sqrt(n) ; i++ ) {
               if ( n % i  == 0 )
                    divisors.pb({i , n/i });
         }
         return divisors ; 
         
     }
     void Test_Case(){
          cin >> n >>m >> k ; 
          vector<int>a(n) , b(m) , prefB(m+5) , prefA(n+5);
          for(auto &d : a )  cin>>d;
          for(auto &d : b )  cin>>d;
          prefB[0]=b[0];
          for ( int i = 1 ; i < m ; i++ ) prefB[i]+=prefB[i-1]+b[i];
          
          prefA[0]=a[0];
          for ( int i = 1 ; i < n ; i++ ) prefA[i]+=prefA[i-1]+a[i];
              
          vector<pi>di = getdiv(k);
          
          set<pi>allcomb ; 
          for ( int i = 0 ; i < di.size() ; i++ ){
               allcomb.insert( { di[i].first , di[i].second });
               allcomb.insert( { di[i].second , di[i].first });
          } 

          ll ans = 0 ;
          for( auto [ x , y] : allcomb ){
               map<int,pi>check;
               int deb = 0  , ch = 0 , i = 0  ;
               while ( deb + x - 1 < m )
               {
                    int CheckX =  prefB[deb+x-1]-  ( deb == 0 ? 0 : prefB[deb-1] ) ; 
                    if ( CheckX == x ) ch++ ;        
                    deb++;

               }
               while (  i + y -1 < n )
               {
                    int CheckY = prefA[i+y-1] - ( i == 0 ? 0 : prefA[i-1] ) ;
                    if ( CheckY == y )  ans+=ch;
                    i++ ; 
                           
               }
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
     //cin >> t;
     while (t--){
          Solution sol;  
          sol.Test_Case();
     } 
    return 0;
}
