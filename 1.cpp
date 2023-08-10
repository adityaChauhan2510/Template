#include<bits/stdc++.h>
#define ll long long
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define inf 1e9
using namespace std;

int dp[1001][1001];
int n, q;


void preComp(){
    for(int i=0; i<n; i++){
        string s; cin>>s;
        for(int j=0; j<s.size(); j++){
            if(s[j]=='*'){
                dp[i][j] = 1;
            }else  dp[i][j] = 0;

            if(i>0) dp[i][j] += dp[i-1][j];
            if(j>0) dp[i][j] += dp[i][j-1];
            if(i>0 && j>0) dp[i][j] -= dp[i-1][j-1];
        }
    }

}


int main(){
    cin>>n>>q;
    preComp();
    while(q--){
        int y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;
        y1-=1;x1-=1;y2-=1;x2-=1;

        int ans = dp[y2][x2];
        if(y1>0) ans -= dp[y1-1][x2];
        if(x1>0) ans -= dp[y2][x1-1];
        if(x1>0 && y1 >0) ans+= dp[y1-1][x1-1];

        cout << ans << endl;


    }

}