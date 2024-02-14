#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long 

class Solution {
public:
    
    int fact ( int x )
    {
        if ( x == 1 ) return x;
        return x * fact(x-1);
    }
    
    void solve()
    {
        int n ; cin >> n ;
        string s ; cin >> s ;
        vector<ll>a(10);
        for ( int i = 1 ; i <= 9 ; i++ ) a[i] = fact(i);
            
        vector<ll> answer ;

        for ( int i = 0 ; i < n ; i++){
            if ( s[i] == '1' || s[i] == '0') continue;
            if ( s[i] == '2')
            {
                answer.pb(2);
                continue;
            }
            ll  ft = ft = s[i] - '0' -1 ;
            ll  checkifcan = 1 ;
            int  ind = 0 ;
            vector<ll>maxans , ch ;
            bool flag = 1 ;
            while ( ft > 1 )
            {
                
                ft = s[i] - '0' -1 - ind ;
                checkifcan*=s[i]-'0'-ind;
                if ( ft == 1) break;
                for ( int j = 9 ; j >= 2  ; j--)
                {
                    ll copycheck = checkifcan ;
                    for ( int k = j ; k>= 2 ; k-- )
                    {
                        while ( copycheck% a[k] == 0  )
                        {
                            copycheck = copycheck / a[k];
                            ch.pb(k);
                        }
                        if ( copycheck == 1 )
                        {
                            ch.pb(ft);
                            if ( ch.size() > maxans.size() ){
                                maxans = ch ;
                            }
                            flag = 0;
                            break ;
                        } 
                    }
                    ch.clear();
                    

                }
                ch.clear();
                ind++;
                
            }
            if ( flag ) answer.pb( s[i]-'0' );
            for ( auto d : maxans )
            {
                answer.pb(d);
            }
            

        }
        sort(answer.begin() , answer.end()) ;
        reverse(answer.begin() , answer.end());
        for ( auto d : answer ) cout << d  ;
        cout<<endl;
          
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
     while (t--){
          Solution sol;  
          sol.solve();
     } 
     return 0;
}
