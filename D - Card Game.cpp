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


class Solution {
public:
     int n ;
     vector<int>a;
     void solve(){
        bool flag = 1 ;
        cin >> n ;
        char joker ;
        cin >> joker ;
        vector<pair<int,char>>answer ; 
        map<char,deque<int>> cards ;
        for ( int i = 0 ; i < 2*n  ;i++)
        {
            string s ;
            cin >> s ;
            cards[s[1]].pb(s[0]-'0');

        }
        for ( auto d : cards)
        {
            char ind = d.first;
            if ( ind == joker) continue;
            sortt(cards[ind]);
            while ( cards[ind].size() >= 2 )
            {
                int second =  cards[ind].back() ;
               
                cards[ind].pop_back();
                int presecond = cards[ind].back();
                cards[ind].pop_back();
                answer.pb({presecond , ind });
                answer.pb({second , ind });
                
                
            }
            if ( cards[ind].size() == 1 )
            {
                if ( cards[joker].size() >= 1 )
                {
                    answer.pb({cards[ind][0], ind});
                    cards[ind].pop_back();
                    answer.pb({cards[joker][0] , joker});
                    cards[joker].pop_front();
                    
                }
                else  flag = 0 ;   
                
            }
        }
        if ( flag )
        {
            if ( cards[joker].size() % 2 == 0 ){
                sortt(cards[joker]);
                    for ( auto d: cards[joker]){
                    while ( cards[joker].size()  >= 2 )
                    {
                        answer.pb({cards[joker][0] , joker});
                        cards[joker].pop_front();
                        answer.pb({cards[joker][0] , joker});
                        cards[joker].pop_front();

                    }
                }
            }
            else flag = 0 ;
            
        }
        if ( flag == 0 ){
            cout  << "IMPOSSIBLE" << endl ;
            return ;
        }
        for ( int i = 0 ; i < answer.size() -1;  i+=2)
        {
            cout << answer[i].first << answer[i].second <<
                 " "<< answer[i+1].first <<answer[i+1].second <<endl ;
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
