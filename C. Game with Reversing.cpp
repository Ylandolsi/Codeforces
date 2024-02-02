#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define pb push_back
#define FIO cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define int long long
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
#define rep(i, y) for (int i = 0; i < y; i++);

void solve(){
    int n; inp ( n );
    string t , s ;
    inp ( s ) , inp ( t ) ;
    int left=0 , right = n-1;
    int diffwithoutrev=0 , diffwithrev=0;
    for ( int i = 0 ; i < n ; i++ ){
        if ( t[i] != s [i] ) diffwithoutrev++;
        if ( s[i] != t[n-i-1]) diffwithrev++;
    }
    int two=2, zero=0;
    if ( diffwithoutrev <= diffwithrev ){
        if (diffwithoutrev % 2 == 1 || diffwithoutrev == diffwithrev  )
            co ( max ((diffwithoutrev *2) -1 , zero  ));
         else if ( diffwithoutrev % 2 == 0  )
            co ( max ((diffwithoutrev *2)  , zero  ));
    }
    else {
        if (diffwithrev % 2 == 1 || diffwithoutrev == diffwithrev  )
            co ( max( (diffwithrev *2) , two  )  ); 
        else if ( diffwithrev % 2 == 0  )
            co ( max( (diffwithrev *2)-1 , two  )  ); 
    }
    
    
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
