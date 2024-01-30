#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define pb push_back
#define FIO cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0)
#define int long long 
#define vt vector<int>
#define pi pair<int,int>
#define mat vector<vector<int>>
#define F first
#define S second
#define yes cout << "yes" << endl;
#define no cout << "no" << endl;
#define ps(left, right) fixed << setprecision(right) << left;
#define all(left) left.begin(), left.end()
#define sortt(left) sort(all(left))
#define mems(vect, left) memset(vect, left, sizeof(vect))
#define rev(vec)      reverse ( all(vec) )
#define co      cout <<
#define inp(left) cin >> left
#define espace cout << " "
#define line cout << endl
#define MAXNUM       LONG_LONG_MAX 
#define takevect(left) for (auto &d : left) cin >> d;
#define takevect1(x) for( int i = 1 ; i<= n ; i++ ) cin>>x[i];
#define fo(j, right,h) for (int i = j; i < right; j+=h)
#define sumtot(x)           accumulate(all(x),(int),0)
void dbgvect(vector<int> tab){
    cout << "###############DEBUGVECT#######################";
    line;
    for(auto it : tab) cout<<it<<" ";
    cout<<endl;
     cout << "###############ENDDEBUG#######################";line;
}
void dbgp(pi p){
    cout<<p.F<<" "<<p.S<<endl;
}
void dbgvectp(vector<pi> tab ){
    cout << "###############DEBUGVECTPAIR#######################";
    line;
    for (auto an :tab)dbgp(an);
    line;
    cout << "###############ENDDEBUG#######################";line;
}
void dbgsingle(auto d){
    cout << "###############DEBUG#######################"; line ;
    cout<<d<<endl;
    cout << "###############ENDDEBUG#######################";line;
}
void solve() {
    int n ; cin >> n ;
    vt vect(n+1,0); takevect1(vect); vect.pb(INT_MAX);
    int l=1 , r=1 , found=0 , newone=1;
    for ( int i= 1 ;  i <= n ; i++ ){
        if (  found && vect[i] < vect[i-1] && vect[i+1]>vect[i]){
            r=i;
            newone=1;
            continue;
        }
        if (  newone && vect[i] < vect[i-1]){
            l=i-1;
            r=i;
            found++;
            newone=0;
        }  
    }
    if ( found >= 2){no;return;}
    reverse(vect.begin()+l,vect.begin()+r+1);
    if ( is_sorted(all(vect))){
        yes;
        cout<< l << " "<< r ;
        return;
    }
    else no;
    
}
signed main() {
    FIO;cout<<fixed;cout<<setprecision(14);
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int test = 1 ; //inp ( test );
    while ( test -- ) solve();
    return 0;
}
