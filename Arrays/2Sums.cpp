#include<bits/stdc++.h>
#define ll long long
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define inf 1e9
using namespace std;
/*

To be able to divide the set into two different sets of equal sum, 
n must be of the form 4k or 4k+3,

case [i] -> n = 4k 
ex- n=8
    1 2 3 4 5 6 7 8

    1,8        2,7
    3,6        4,5


case [ii] -> n = 4k + 3
ex- n=7
    1 2 3 4 5 6 7
    
    1,6        2,5
    3,4        7


*/

int main(){
    ll n; cin>>n;

    if(((n*(n+1))/2) % 2 != 0){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;

        vector<ll> f;
        vector<ll> s;

        if(n%2==0){
            for(int i=0; i<n/2; i++){
                if(i%2==0){
                    f.push_back(i + 1LL);
                    f.push_back(n-i);
                }else{
                    s.push_back(i+1LL);
                    s.push_back(n-i);
                }
            }
        }else{
            for(int i=0; i<(n-1)/2; i++){
                if(i%2==0){
                    f.push_back(i+1LL);
                    f.push_back(n-i-1);
                }else{
                    s.push_back(i+1LL);
                    s.push_back(n-i-1);
                }
            }
            if(f.size()>s.size()){
                s.push_back(n);
            }else{
                f.push_back(n);
            }
        }

        cout << f.size() << endl;
        for(int i=0; i<f.size();i++){
            cout << f[i] << " ";
        }
        cout << endl;
        cout << s.size()<< endl;
        for(int i=0; i<s.size(); i++){
            cout << s[i] << " ";
        }

    }
}