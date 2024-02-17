#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long 
typedef pair<ll,pair<ll,ll>> tup;
typedef pair<ll,ll> pi;
#define endl "\n"
#define all(x) x.begin(), x.end()
#define sortt(x) sort(all(x))
#define unq(vt)  vt.erase(unique(all(vt)), vt.end())
#define rev(x)   reverse (all(x)) 


vector<ll> tree;

class SegmentTree {

   

public:
    void update(int node , ll leftR , ll RightR , ll RightUSER , ll LeftUSER) {
        if ( LeftUSER > RightUSER ) return ; 
        if (leftR == LeftUSER && RightR == RightUSER) {
            tree[node]++;
            return ;
        }
        ll mid = ( leftR + RightR) / 2 ;
        update(node*2  , leftR ,mid  , min ( RightUSER , mid ) , LeftUSER );
        update(node*2 +1 , mid + 1  , RightR , RightUSER , max ( LeftUSER  , ( mid + 1 ) ) );

    }
    int QueryDis ( int node , int left , int right , int pos )
    {
        if ( left == right) return tree[node];

        ll mid = ( left + right ) / 2 ;
        if ( mid >= pos )
        return  tree[node] + QueryDis( node * 2 , left , mid , pos  ) ; 

        else  return tree[node] + QueryDis( node * 2 +1 , mid + 1  , right , pos  ) ;
    }



    
};



class Solution {
public:
     
    string todigit ( string x )
    {
        int res = 0  ; 
        for ( int i = 0 ;  i< x.size() ; i++)
        {
            res+=x[i]-'0';
        }
        return to_string(res);
    }
     void solve(){
        int n , q ;
        cin >> n >>q ;
        vector<vector<ll>>a(n);
        SegmentTree seg;
        tree.clear();
        tree.resize(4 * n ); 
        for ( int i = 0 ; i < n  ;i++)
        {
            string num;  cin >> num ;
            while ( true )
            {
                a[i].pb(stoll(num));
                num = todigit(num);
                if ( num.size() <= 1 ){
                    a[i].pb(stoll(num));
                    break;

                } 
                

            }

        }

        for ( int i = 0 ; i < q ;i++ )
        {
            int one_or_two  ; cin >> one_or_two ;
            if ( one_or_two == 1 )
            {
                int L , R ; cin >> L >> R ;
                seg.update(1 , 0 , n-1 , R-1 , L-1 );

            }
            else 
            {
                int po ; cin >> po ; po--;
                ll k = seg.QueryDis( 1 , 0 , n-1 , po) ;
                if ( k >= a[po].size() )
                {
                    int sz = a[po].size() ; 
                    cout << a[po][sz - 1] << endl ;
                }
                else  cout << a[po][k] << endl ;
                
            }
        }

               
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
