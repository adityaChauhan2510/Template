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
    ll n, c; cin>>n>>c;
    vector<ll> a(n+1);
    for(int i=0; i<n; i++) cin>>a[i];

    ll sum = a[0];
    int j = 0;
    for(int i=1; i<n; i++){
        if((sum + a[i])/((i+1)*c) > 0){
            for(int k=j+1; k<=i; k++){
                sum += a[k];
            }
            j = i;
        }
    }

    if(j==n-1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }


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


