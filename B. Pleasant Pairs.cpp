#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define FIO cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define int long long
#define vt vector<int>
#define matrix vector<vector<int>>
#define ff first
#define ss second
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define wh(t) \
    int t;    \
    cin >> t; \
    while (t--)
#define ps(x, y) fixed << setprecision(y) << x;
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))
#define print(x) cout << x
#define input(x) cin >> x
#define espace cout << " "
#define line cout << endl
#define take(x)       \
    for (auto &d : x) \
        cin >> d;
#define rep(i, y) for (int i = 0; i < y; i++)


void solve()
{
    int n;
        cin >> n;
        int ar[2*n+1];
        for (int i = 0; i <=2*n; ++i) 
            ar[i] = LONG_LONG_MAX;
        
        for (int i = 1; i <= n; ++i) {
            int x;
            cin>>x;
            ar[x] = i;
        }
        int count =0;
        for (int i = 3; i < 2*n; ++i) {
            for (int j = 1; j <sqrt(i) ; ++j) {
                if (i%j==0 && (ar[j] + ar[i/j] == i)) {
                    count++;
                }
            }
        }
        cout<<count<<"\n";
    }
   
    
signed main()
{
    FIO;
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int test = 1;
    cin >> test;
    while (test--)
        solve();
    return 0;
}
