/*
Time Complexity --> O(NlogN)
Used when-
    a[j]>a[i], when j>i
    j % i==0, when j is a multiple of i.
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N= 100010;
int a[N];

void lis(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];

    vector<ll> dp(n+1, 1);
    ll maxi=1;

    for(int i=1; i<=n; i++){
        for(int j=2*i; j<=n; j+=i){
            if(a[j]>a[i]){
                dp[j] = max(dp[j], 1+dp[i]);
            }
        }

        maxi=max(maxi, dp[i]);
        //cout << dp[i] << " ";
    }
    
    cout << maxi << endl;

}


int main(){
    lis();
}


