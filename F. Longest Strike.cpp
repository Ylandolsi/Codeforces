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
    int n, k;
    cin >> n >> k;
    vt vect(n);
    takevect(vect); sortt(vect);
    map<int, int> temp, mp;
    for (auto d : vect) temp[d]++;
    for (auto d : vect) {
        if (temp[d] >= k) mp[d]++;
    }
    if ( mp.size()==0){
        co -1;
        line;
        return;
    }
    int left = mp.begin()->first , right = left, diff = INT_MIN;
    auto iter = mp.begin(); iter++; // start from second element 
    pair<int,int> ans;
    while (iter != mp.end()) {
        if (iter->first != right + 1) {
            if ( right - left > diff ) {
                diff=right-left;
                ans.first=left, ans.second=right;   
            }
            left = iter->first;
            right = left;
        } else 
            right = iter->first;
        ++iter;
    }
    if ( right - left > diff ) {
        diff=right-left;
        ans.first=left, ans.second=right;   
    }
    cout << ans.first << " " << ans.second;
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
