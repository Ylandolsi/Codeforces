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
	
	void solve(){
		int n , m , k , countdiff = 0 ;
		cin >> n  >> m >> k ;
		vector<int>a(n) , b(m);
		for(auto &d : a )  cin>>d;
		for(auto &d : b )  cin>>d;
		sortt(a);
		sortt(b);
		unq(a);
		unq(b);
		int a_new = a.size() , b_new = b.size();
		map<int,int> checka , checkb ; 
		for ( int i = 0 ; i < a_new ; i++ )
		{
			if ( a[i] >= 1 && a[i] <= k ) checka[a[i]]++;
		}
		for ( int i= 0 ; i < b_new ; i++ )
		{
			if ( b[i] >= 1 && b[i] <= k )checkb[b[i]]++;
		}
		int elementsa = checka.size() ;
		int coun = 0 ;
		map<int,int>done;
		for ( auto d : checkb )
		{
			int x = d.first;
			if ( checka[x] == 1 ) continue;
			
			
			coun++;
			done[x]++;
			if ( coun>= k/2 &&  elementsa >= k/2  ){
				cout << "Yes" << endl;
				return;
			}

		}
		for ( auto d : checkb )
		{
			int x = d.first;
			if ( done[x] == 1 ) continue;
			
			
			elementsa--;
			coun++;
			done[x]++;
			if ( coun>= k/2 &&  elementsa >= k/2  ){
				cout << "Yes" << endl;
				return;
			}

		}
		cout << "No" << endl;
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
