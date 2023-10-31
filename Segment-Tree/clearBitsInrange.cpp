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
        1 1 0 1 0 1 0 1    (n)
              j   i         
              4   2        0 based indexing

        1 1 0 0 0 0 1 1---->mask(Do and with number)

        To create this mask
        1 1 0 0 0 0 0 0    (~0)>>j+1
        0 0 0 0 0 0 1 1    2^i - 1    (Do or of both these to create mask)
*/

int clearBitsInRange(int  n, int i, int j){
    int a = (~0)<<(j+1);
    int b = (1<<i) - 1;
    int mask = a|b;
    n = (n&mask);
    return n;
}


int main(){
    int n ; cin>>n; 
    int j; cin>>j;
    int i; cin>>i;

    cout << clearBitsInRange(n, i, j) << endl;
    
}