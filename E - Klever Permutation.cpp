#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define endl "\n"


class Solution {
public:
	
	void solve(){
		int n , k  ;
		cin >> n >> k  ;
		vector<int>a(k) , answer(n);
		int lenght = n ; 
		for ( int i = 0 ; i< k ; i++ )
		{
			a[i]= ceil(lenght/double(k));
			lenght--;
		}
		int index = k-1 , lastused = 0 , use , comp = 0 ;
		bool avance = 1 ;
		for ( int i = k-1  ; i >= 0 ;i-- ){
			int combien = a[i];
			if ( avance) use = lastused+1;
			else use = combien + lastused ; 
			comp = 0;
			for ( int j = i ; j < n ; j+=k ){
				if ( avance)
				{
					answer[j]=use;
					comp=max(use,comp);				
				
					use++;
				}
				else 
  				{
					answer[j]=use;
					comp=max(use,comp);		
					use--;
				}
			}
			if ( avance == 1) avance = 0;
			else avance = 1;
			lastused = comp;
			

		}
		for ( auto d : answer ){
			cout << d << " ";
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
