#include<bits/stdc++.h>
#define ll long long
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define inf 1e9
#define endl '\n'
using namespace std;


int mod_add(int a, int b, int m){
    return (a%m + b%m) % m;
}

int mod_sub(int a, int b, int m){
    return (a%m - b%m + m)%m;
}

int mod_multiply(int a, int b, int m){
    return (a%m * b%m) % m;
}


int main(){
    return 0;
}