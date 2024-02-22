#include <bits/stdc++.h>
using namespace std ; 
#define pb push_back
#define SPEED cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long 
typedef pair<int,int> pi;
#define endl "\n"




class Solution {
public:

     
     void solve(){
          string s ;
          cin >> s ;
          int n = s.size(); 
          pi AB_1 , AB_2 , BA_1 , BA_2 , compare ; 
          AB_1 = AB_2 = BA_1 = BA_2 = compare = { -1 , -1};
          bool find_ab = 0 , find_ba = 0;
          for ( int i = 0 ; i < n-1 ; i++)
          {
               if (  find_ab == 0 && s[i] == 'A' && s[i+1]  == 'B')
               {
                    AB_1 = { i , i+1 };
                    find_ab = 1;
                    continue;
               }
               if ( find_ba == 0  && s[i] == 'B' && s[i+1]  == 'A')
               {
                    BA_1 = { i , i+1 };
                    find_ba = 1;
                    continue;
               }
               if ( find_ba && i!= BA_1.second &&  s[i] == 'B' && s[i+1]  == 'A' ) BA_2 = { i , i+1 };
               if ( find_ab && i != AB_1.second &&  s[i] == 'A' && s[i+1]  == 'B' ) AB_2 = { i , i+1 };
          
               

          }
          if ( BA_1 != compare  && AB_2 != compare  && BA_1.second != AB_2.first &&  BA_1.first != AB_2.second )puts("Yes");
          else if ( BA_1 != compare  && AB_1 != compare  && BA_1.second != AB_1.first &&  BA_1.first != AB_1.second ) puts("Yes");
          else if ( AB_1 != compare  && BA_2 != compare && AB_1.second != BA_2.first && AB_1.first != BA_2.second ) puts("Yes");
          else if ( AB_1 != compare &&  BA_1 != compare && AB_1.second != BA_1.first && AB_1.first != BA_1.second ) puts("Yes");
          else puts("No");
          
     
          
          

     }
     
};

int main() {
     SPEED;
     #ifndef ONLINE_JUDGE
          freopen("inp.txt", "r", stdin);
          freopen("out.txt", "w", stdout);
          freopen("err.txt", "w", stderr);
     #endif
     int t = 1;
     //cin >> t;
     while (t--){
          Solution sol;  
          sol.solve();
     } 
     return 0;
}
