#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define pb push_back
#define FIO cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
//#define int long long
#define vt vector<int>
#define matrix vector<vector<int>>
#define ff first
#define ss second
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define ps(x, y) fixed << setprecision(y) << x;
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))
#define mems(a, x) memset(a, x, sizeof(a))
#define rev(x)      reverse ( all(x) )
#define co      cout <<
#define inp(x) cin >> x
#define espace cout << " "
#define line cout << endl
#define takevect(x) for (auto &d : x) cin >> d;
#define rep(j, y) for (int i = j; i < y; i++)
void solve() {
    int n, k,cte=0 ,  maxx=INT_MIN;
    cin >> n ;
    vector<int> vect(n); takevect(vect);
    sortt(vect);
    map <int , int> mp;
    vt num(n+1);
    for( auto d : vect) mp[d]++;
    auto iter=mp.begin();
    while ( iter != mp.end() ){
        int gap=iter->first;
        int occ=iter->second;
        for ( int j=gap; j <=n ; j+=gap){
            num[j]+=occ;
            maxx=max(num[j],maxx);
        } 
        iter++;
    }
    co max(maxx,0);
    line;
}

signed main() {
    FIO;
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int test = 1 ;  inp ( test );
    while ( test -- ) solve();
    return 0;
}
