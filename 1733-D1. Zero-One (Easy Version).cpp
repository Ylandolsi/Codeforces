#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define FIO cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define int long long 
#define vt vector<int>
typedef pair<int,pair<int,int>> tup;
typedef pair<int,int> pi;
#define endl "\n"
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))
#define unq(vt)  vt.erase(unique(all(vt)), vt.end())
#define rev(x)   reverse (all(x)) 
int gcd(int a , int b) {return b ? gcd(b , a % b) : a ;}
int lcm(int a , int b) {return (a * b) / gcd(a , b);}
#ifndef ONLINE_JUDGE           
#define dbg(x) cerr << #x<< " " ;  _print(x) ;  cerr << endl;
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

class Solution {
public:
    void solve(){
        int n , x, y , si ;
        cin >> n >> x >>y ;
        string a , b ; 
        cin >> a >> b ; 
        vector<int>indexed;
        for ( int i = 0 ; i < n ; i++ ){
            if ( a[i] != b[i])  indexed.pb(i);
        }        
        si=indexed.size();
        if ( si & 1 ){
            cout<< -1 << endl ; 
            return ; 
        }
        if ( si == 2 ){
            if ( indexed[0]+1 == indexed[1] )cout<< min(x ,y*2)<<endl;
            else  cout << y << endl ;
            return ; 
        }
        int ans = indexed.size()/2 * y ;     
        cout <<ans <<endl;  
        
    }
};

signed main() {
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
