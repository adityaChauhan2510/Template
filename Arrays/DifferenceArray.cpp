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
RANGE UPDATE QUERY

Increase arr[l....r] by x

TC---> O(N+Q)
*/


void updateArray(vector<int>& diff, int l, int r, int x){

    diff[l] += x;  //After taking prefix sum adds x from L to N

    diff[r+1] -= x;  //After taking prefix sum subtracts x from R+1 to N

}


int main(){
    int n, q;
    cin>>n>>q;

    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<int> diff(n+1, 0);


    while(q--){
        int x; cin>>x;
        if(x==1){
            //update diff array
            int l, r, u; cin>>l>>r>>u;
            updateArray(diff, l-1, r-1, u);
            
        }
        else{
            //print arr after performing query
            for(int i=1; i<=n; i++){
                diff[i] += diff[i-1];
            }

            for(int i=0; i<n; i++){
                a[i] += diff[i];
                cout << a[i]  << " ";
            }

            cout << '\n';
        }


    }
}