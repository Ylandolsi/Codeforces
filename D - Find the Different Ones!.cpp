#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define endl "\n"

class Solution {
public:
	
	void solve(){
		int n , q  ;
		cin >> n  ;
		vector<int>a(n) ;
		for(auto &d : a )  cin>>d;
		map<int,set<int> > mp ;
		for ( int i = 0 ; i < n ;i++ ){
			if ( i ){
				mp[i] = mp[i-1];
				int firstelement = *mp[i].begin() ;
				int secondelemnet;
				if ( mp[i].size() > 1 ){
					 auto it = next(mp[i].begin()); 
                	secondelemnet = *it;
					 if ( a[i] != a[secondelemnet]){
						mp[i].erase(firstelement);
						mp[i].insert(i);
					 }
					 else {
						mp[i].erase(secondelemnet);
						mp[i].insert(i);
					 }
				}
				else {
					if ( a[firstelement] != a[i] ) mp[i].insert(i);
					else {
						mp[i].erase(firstelement);
						mp[i].insert(i);
					}
				}
			}
			else mp[i].insert(i);
		}
		cin >> q;
		for ( int i = 0 ; i < q ; i++ ){
			int left , right , check ;
			cin >> left >> right ;
			left-- , right-- ;
			if ( left == 0 ){
				check = mp[right].size() ;
				if ( check < 2 ){
					cout << -1 << " " << -1 << endl;
					continue;
				}
				else {
					auto it = next(mp[right].begin()); 
                	int secondelemnet = *it;
					cout << *mp[right].begin() + 1  << " " << secondelemnet + 1 << endl;

				}
			}
			else {
				int cte = 0;
				for ( auto d: mp[right]){
					if ( d >= left ) cte++;
					
				}
				if ( cte < 2 ){
					cout << -1 << " " << -1 << endl;
					continue;
				}
				else {
					auto it = next(mp[right].begin()); 
                	int secondelemnet = *it;
					cout << *mp[right].begin() + 1 << " " << secondelemnet + 1 << endl;
				}
				
			}

		}
		cout << endl ;
		

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
