#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long 

class Solution {
public:
 
    string s;
    ll n , cnt;
    vector <int>v;
    Solution(){
          cin >> n ;
          cin >> s ;     
    }   
    ll func(ll x){
        ll d=0;
        for( int i = 0 ; i < cnt ; i++)
            d += abs( x - v[i] );
        
        return d;
    }

    ll ternary_search()
    {
        ll count_1,count_2;
        ll l=0, r=n-1;
        ll m2 , m1 ;
        while(r-l>4)
        {
            m1= l + ( r-l ) /3;
            m2= r- ( r-l )/3;
            count_1= func( m1 );
            count_2=func( m2 );
            if( count_1 < count_2 ) r = m2;
            else if(count_1==count_2) l = m1, r = m2;
            else l = m1 ;
        }
        ll Index_Of_Answer=0;
        count_1 = 1e18 ;
        for(ll i=l;i<=r;i++)
        {
            if(func(i)<count_1)
            {
                count_1=func(i);
                Index_Of_Answer=i;
            }
        }
        return Index_Of_Answer;
    }

    void solve()
    {
        cnt = 0;
        for ( int i = 0; i < n; i++){
            if (s[i] == '*'){
                v.push_back(i - cnt);
                cnt++;
            }
        }
        ll Index = ternary_search();
        ll answer = func(Index);
        cout << answer << endl ;
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
     while (t--){
          Solution sol;  
          sol.solve();
     } 
     return 0;
}
