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
#define pi pair<int,int>
#define mat vector<vector<int>>
#define endl "\n"
#define F first
#define S second
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define all(left) left.begin(), left.end()
#define sortt(left) sort(all(left))
#define co      cout <<
#define inp(left) cin >> left
#define espace cout << " "
#define line cout << endl
#define INF 2e18
#define takevect(left) for (auto &d : left) cin >> d;
#define takevect1(x) for( int i = 1 ; i<= n ; i++ ) cin>>x[i];
#define fo(j, right,h) for (int i = j; i < right; j+=h)
#define sumtot(x) accumulate(all(x),(int)0)
#define mapi map<int,int>


void solve() {
    int n; cin >> n ;
    vt a(n),b,vis(11,-1); takevect(a);
    unordered_map<int,int> mp;
    for ( int i = 0 ; i < n ; i++ ){
        if ( mp[a[i]%10] < 3 )
            mp[a[i]%10]++;
    }
    for ( int i = 0 ; i<10 ; i++ ){
        for  ( int j = 0 ; j<mp[i] ; j++ ){
            b.pb(i);
        }
    }
    for ( int i = 0 ; i < b.size() ; i++ ){
        for ( int j = 0 ; j < b.size() ; j++ ){
            if ( i == j ){continue;}
            for ( int k = 0 ; k<b.size() ; k++ ){
                if ( i==k || j == k ){continue;}
                if ( ( b[i]+b[j]+b[k] ) % 10 == 3){
                    yes;return;
                    }
                    
                }

            }
        }
    
    no;
    
}    


signed main() {
    FIO;
    cout<<fixed;cout<<setprecision(14);
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        freopen("err.txt", "w", stderr);
    #endif
    int test = 1 ;cin>>test;
    while ( test -- ) solve();
    return 0;
}
