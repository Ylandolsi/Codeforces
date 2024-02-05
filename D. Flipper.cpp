#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define int long long 
#define endl "\n"
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))


class Solution {
public:
	 void solve(){
		int n  , right , ref ;
		cin >> n ;
		vector<int> a ( n+2 );
		for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
		if ( n == 1 )
		{
			cout<<a[1]<<endl;
			return ;
		}
		// Search Maxi and index Of max After the first element , +2 bcz it s 1 indexed
		int maxi = *max_element(a.begin() +2 , a.end() )  ;
		int indexmaxi = max_element(a.begin() +2 , a.end() ) - a.begin()  ;
		
		if ( indexmaxi == n ) right = indexmaxi ;
		else right = max ( indexmaxi - 1 , (int) 1 ) ;
		
		int left = right ; 
		if ( right + 1 <= n ) ref = a[right+1] ;
		else ref = a[right];
		// Find L 
		for ( int i = right - 1 ; i >= 1 ; i-- )
		{
				if ( a[i] < a[1] || i == 1 ){ // we stop when we found > first element or when we reach the first element 
					left = min (i+1 , right ) ;
					break ; 
				}
				
		}  
		// Reverse the segment [ l , r ]
		reverse( a.begin() + left  , a.begin() + right + 1  );
		for ( int i = right + 1  ; i<= n ; i++ ) cout<< a[i] << endl ;
		for ( int i = left ; i <= right ; i++ )  cout<< a[i] << endl ;
		for ( int i = 1 ; i < left ; i++ )   cout<< a[i] << endl ; 
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
