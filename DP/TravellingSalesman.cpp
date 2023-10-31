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
Here we are representing visited cities as bitmask

For Ex-
A------>0001
B------>0010
AB----->0011
ABD---->1011


No of states for visited cities = 2^N    from (0000........1111)
states for curr city = N

dp[2^N][N]

TC----> O(2^N * N * N)

*/

int tsp(vector<vector<int>> dist, int visCity, int currCity, int n,vector<vector<int>>& dp){

    //base case
    if(visCity == (1<<n)-1){
        return dist[currCity][0];  //return cost from city to original 
    }

    if(dp[visCity][currCity] != -1) return dp[visCity][currCity];

    int ans = INT_MAX;
    for(int choice=0; choice<n; choice++){

        //to check if city is visited or not
        if((visCity & (1<<choice))==0){

            visCity |= (1<<choice);
            int smallAns = dist[currCity][choice] + tsp(dist, visCity,choice,n, dp);
            ans=min(ans, smallAns);

            visCity ^= (1<<choice);
        }
    }

    return dp[visCity][currCity] = ans;
}


int main(){
    int n = 4;
    vector<vector<int>> dist = {
        {0, 20, 42, 25},
        {20, 0, 30, 34},
        {42, 30, 0, 10},
        {25, 34, 10, 0}

    };
    vector<vector<int>> dp(1<<n, vector<int> (n, -1));
    cout << tsp(dist, 1, 0, n, dp) << endl;
}