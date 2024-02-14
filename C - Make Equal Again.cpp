#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long 


class Solution {
public:
   int n ;
    Solution(){
          cin >> n ;    
    }   
   
    void solve()
    {
        deque<int>a(n);
        int delete_bothside = 0;
        for(auto &d : a )  cin>>d;
        deque<int>b = a ;
        int comp = b[0];
        while ( !b.empty() && b.front() == comp && b.back() == comp)
        {
            if ( !b.empty() )
            {
                b.pop_front();
                delete_bothside++;
            }
            if ( !b.empty() )
            {
                b.pop_back();
                delete_bothside++;
            }
            
        }
        while ( !b.empty() && b.back() == comp ){
            b.pop_back();
            delete_bothside++;
        }
        while ( !b.empty() && b.front() == comp ){
            b.pop_front();
            delete_bothside++;
        }    
        if ( b.empty() )
        {
            cout << 0 << endl ;
            return;
        }
        int occ = 1 , ref = a[0] ;
        for ( int i =  1 ; i<a.size() ; i++ )         
        {
            if ( a[i] == ref ) occ++;
            else break;
        }
        int occ2 = 1 , ref2 = a[a.size() - 1];
        for ( int i = a.size() -2 ; i>= 0 ; i-- )
        {
            if ( a[i] == ref2 )occ2++;
            else break;
        }
        int max_occ = max ( occ2 ,  max ( occ , delete_bothside )  );
        int answer = a.size() - max_occ;
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








