#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define int long long 
#define vt vector<int>
#define takevect(vect) for(auto &mooo : vect ){cin>>mooo;}
#define takevect1 (vect) for( int i = 1 ; i <= x ;i++)cin>>vect[i];
typedef pair<int,pair<int,int>> tup;
typedef pair<int,int> pi;
#define endl "\n"
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define all(doo) doo.begin(), doo.end()
#define sortt(doo) sort(all(doo))
#define unq(vt)  vt.erase(unique(all(vt)), vt.end())
#define rev(doo)   reverse (all(doo)) 
#define lb lower_bound
#define up upper_bound
int gcd(int a , int b) {return b ? gcd(b , a % b) : a ;}
int lcm(int a , int b) {return (a * b) / gcd(a , b);}
#define forr(i, doo, y)   for(int i = doo; i <= y; i++)
#define forrb(i, doo, y)   for(int i = doo; i >= y ; i--)

#ifndef ONLINE_JUDGE           
#define dbg(doo) cerr << #doo<< " " ;  _print(doo) ;  cerr << endl;
#endif

void _print(auto t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T> bool ckmax(T& a, const T& b){return a < b ? a = b, 1 : 0;}
template<class T> bool ckmin(T& a, const T& b){return a > b ? a = b, 1 : 0;}

class Solution {
public:
     int n , k  ; 
     void solve(){
          cin >> n >> k;
          if ( n > k + 1  || k > (n+1)*2  ){ 
               cout << -1 << endl ;
          } else if ( n <= k  ) {
               int restofones = k - ( n +1 ) , newk = 0 ;
               for  ( int i = 0 ; i <k ; i++ ){
                    if (newk == k ) break;
                    cout << 1;newk++;
                    if ( restofones >= 1  ){
                         cout << 1 ;
                         restofones--;
                         newk++;
                    }
                    if ( n ) { cout<< 0 ; n--; }
               }
          } else if ( n > k ){
               for ( int i = 0 ; i < n-1 ; i++ ) cout<<0<<1;
               cout<< 0;
          } else cout<<-1;
       
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
    //cin >> t;
    Solution sol;  
    while (t--) sol.solve();
    return 0;
}
