#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define int long long 
#define endl "\n"


class Solution {
public:
	 void solve(){
		int n , m   ;
		cin >> n >> m  ;
		int  mcopy = m ;
		string larg ="" , small="";
		for ( int i = 0 ; i < n ; i++ ) 
		{
			for( int j = 9 ; j >= 0 ; j-- )
			{
				int Rest = mcopy  - j ;
				if ( Rest >= 0 && ( n- ( i+ 1 ) ) * 9  >= Rest ){
					larg += '0' + j;
					mcopy -= j ;
					break;
				}
			}
				
		}
		mcopy = m ;
		for ( int i = 0 ; i < n ; i++ )
		{
			for ( int j = i == 0 && n != 1 ? 1 : 0  ; j <= 9 ; j++ )
			{
				int Rest = mcopy - j;
				if ( Rest >= 0 && ( n - ( i +1 ) ) * 9 >= Rest ) 
				{
					small += '0' + j;
					mcopy-=j;
					break;
				}
			}
		}
		int sum_ = 0 , sum = 0 ;
		for ( int i = 0 ; i < n ; i++ )
		{
			sum_+=larg[i]-'0';
			sum+=small[i]-'0';
		}
		if ( sum_ != m || sum != m )cout << -1 << " " << -1 << endl ;
		else cout << small << " " << larg << endl ;
		
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
