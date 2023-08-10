#include<bits/stdc++.h>
#define ll long long
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define inf 1e9
using namespace std;

ll dp[1000007] = {-1};
int f(string s){

    int num = stoi(s);
    if(num==0) return 0;
    if(dp[num] != -1) return dp[num];

    int minSteps = INT_MAX;
    for(int i=0; i<s.size(); i++){
        int x = s[i] - '0';
        if(x!=0){
            string str = to_string(num-x);
            minSteps=min(minSteps,1 + f(str));
        }
        
    }
    return dp[num]= minSteps;
}

int main(){
    int n; cin>>n;
    string s = to_string(n);

    cout << f(s) << endl;
}