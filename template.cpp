#include<bits/stdc++.h>
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

#define ll                  long long
#define ld                  long double
#define mod                 1000000007
#define inf                 1e9
#define endl                '\n'

using namespace std;

static bool comp(const pair<int, int>& p1, const pair<int, int>& p2){
    if(p1.first!=p2.first){
        return p1.first<p2.first;
    }else{
        return p1.second>p2.second;
    }
}


void solve(){
    
}


int main(){
    fast_io;
    cout << fixed;
    cout << setprecision(10);
 
    int t;
    t=1;
    cin>>t;
 
    while(t--)
    {
        solve();
    }
}


