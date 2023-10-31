#include<bits/stdc++.h>
#define ll long long
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define inf 1e9
using namespace std;


ll gcd(ll a, ll b){
    if(b==0) return a;

    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return (a*b)/gcd(a,b);
}


int main(){
    cout << gcd(15,35) << endl;
    cout << lcm(5, 15);
}