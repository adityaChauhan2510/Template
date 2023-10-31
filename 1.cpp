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
    ll n; cin>>n;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];


    ll pow = 0;
    ll cnt = 0;
    
    for(int i=1; i<n; i++){
        if(a[i] + pow >= a[i-1]){
            a[i] = a[i] + pow;
        }
        else{
            a[i] = a[i] + pow;

            while(a[i]<a[i-1]){
                cout << a[i] << " " << cnt << endl;
                if(pow==0){
                    a[i] += 1;
                    pow=1;

                }else{
                    pow = (pow*2); 
                    a[i] += pow;
                }
                cnt++;
            } 
            cout << a[i] << " " << cnt << endl;
            
              
        }        
    }

    cout << cnt << endl;
    

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


