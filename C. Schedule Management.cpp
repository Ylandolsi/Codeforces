#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define int long long 
typedef pair<int,pair<int,int>> tup;
typedef pair<int,int> pi;
#define endl "\n"
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))
#define unq(vt)  vt.erase(unique(all(vt)), vt.end())
#define rev(x)   reverse (all(x)) 


class Solution {
public:

    void solve()
    {
        int n , m ; cin >> n >> m ; 
        vector<int> A(m) , Tasks(n) ;
        for ( int i = 0 ; i < m ; i++ ) {
            cin >> A[i] ; 
        } 
        for ( int i = 0 ; i < m ; ++i ) Tasks[A[i]-1]++;
        int TotalTasks  ,  l = 1 , r = m * 2 ; 
        for ( auto d : Tasks ) TotalTasks+=d;
        while ( l <= r ) 
        {
            int x = ( l + r ) / 2 , HelpOthers = 0 , WorkDone = 0 ;
            for ( int i = 0 ; i < n ; ++i ) 
            {
                if ( x >= Tasks[i] ) 
                {
                    WorkDone += Tasks[i];
                    HelpOthers += ( x - Tasks[i] ) / 2;
                } 
                else WorkDone += x;
            }
            if ( WorkDone + HelpOthers >= m ) r = x - 1 ; 
            else l = x + 1 ; 
        } 
        cout << l << endl ; 

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
	cin >> t;
	Solution sol;  
	while (t--) sol.solve();
	return 0;
}
