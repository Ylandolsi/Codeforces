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

int calculprefix(int indexL , int indexR , vector<int>& p) {
    return p[indexR] - (indexL ? p[indexL - 1] : 0); // 0indxed : 
} 

// Consider N is Even Or N is Odd and check It s impact on result ::! 
// Check If there is smthg That repeats each time or 
//                                      smthng 
// LB_UB - > suffix prefix ....
vector<bool> isPrime(1e6 + 1, true); 
class Solution {
public:
     void solve(){
          int n, m , cte = 1 ; cin >> n >> m;
          vector<vt> ma (n ,vt(m,0));
          for ( int i = 0 ; i< n ; i++ ){
               for ( int j = 0 ; j < m ; j++) ma[i][j] = cte++;
          }
          for(int i = 1; i < n; i+= 2) {
               for(int j = 0; j < m; ++j) cout <<ma[i][j]<< " ";
               cout<<endl;
          }
          for(int i = 0; i < n; i+= 2 ) {
               for(int j = 0; j < m; ++j)cout <<ma[i][j]<< " "; 
               cout<<endl;
          }
          cout<<endl;
     }
     
};

signed main() {
     SPEED;
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        freopen("err.txt", "w", stderr);
    #endif
//     for (int p = 2; p * p <= 1e6 + 5 ; p++) {
//         if (isPrime[p]) {  
//             for (int i = p * p; i <= 1e6 + 5; i += p) 
//                 isPrime[i] = false;
//         }
//      }    
    int t = 1;
    cin >> t;
    Solution sol;  
    while (t--) sol.solve();
    return 0;
}
